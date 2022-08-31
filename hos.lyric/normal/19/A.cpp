//  Codeforces Beta Round #19
//  Problem A

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
    int x = 0, c;
    for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
    do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
    return x;
}

char buf[1010];
int N;
string S[110];
map<string,int> tr;
pair<pint,pint> ps[110];
string ans[110];

int main() {
    int i, j, k;
    int a, b;
    string s, t;
    
    N = in();
    for (i = 0; i < N; ++i) {
        scanf("%s", buf);
        S[i] = buf;
        tr[S[i]] = i;
    }
    for (i = 0; i < N; ++i) {
        ps[i].second.second = i;
    }
    for (int nu = N * (N - 1) / 2; nu--; ) {
        scanf("%s", buf);
        for (k = 0; buf[k] != '-'; ++k);
        buf[k] = ' ';
        istringstream iss(buf);
        iss >> s >> t;
        i = tr[s];
        j = tr[t];
        a = in();
        b = in();
//cout<<i<<" "<<j<<"  "<<a<<" "<<b<<endl;
        if (a > b) {
            ps[i].first.first += 3;
        } else if (a == b) {
            ps[i].first.first += 1;
            ps[j].first.first += 1;
        } else {
            ps[j].first.first += 3;
        }
        ps[i].first.second += a - b;
        ps[j].first.second += b - a;
        ps[i].second.first += a;
        ps[j].second.first += b;
    }
    sort(ps, ps + N, greater< pair<pint,pint> >());
    for (i = 0; i < N / 2; ++i) {
        ans[i] = S[ps[i].second.second];
    }
    sort(ans, ans + N / 2);
    for (i = 0; i < N / 2; ++i) {
        cout << ans[i] << endl;
    }
    
    return 0;
}