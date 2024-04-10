//  Codeforces Beta Round #60

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
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void pvq(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first.first << "," << i->first.second << "," << i->second.first << "," << i->second.second << ") "; cout << endl; }
void chmin(int &t, int f) { if (t > f) t = f; }
void chmax(int &t, int f) { if (t < f) t = f; }
void chmin(Int &t, Int f) { if (t > f) t = f; }
void chmax(Int &t, Int f) { if (t < f) t = f; }
void chmin(double &t, double f) { if (t > f) t = f; }
void chmax(double &t, double f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

char A[][110] = {
"Gryffindor", 
"Hufflepuff", 
"Ravenclaw", 
"Slytherin", 
};

typedef pair<pint,pint> qint;
#define mq(a,b,c,d) mp(mp(a,b),mp(c,d))

int N;
char S[10010];
set<qint> dp, DP;

int main() {
    int i, j;
    set<qint>::iterator it, en;
    int a, b, c, d, e;
    
    for (; ~scanf("%d%s", &N, S); ) {
        dp.clear();
        dp.insert(mq(0, 0, 0, 0));
        for (i = 0; i < N; ++i) {
            DP.clear();
            j = string("GHRS").find(S[i]);
            for (it = dp.begin(), en = dp.end(); it != en; ++it) {
                a = it->first.first;
                b = it->first.second;
                c = it->second.first;
                d = it->second.second;
                switch (j) {
                    case 0: { DP.insert(mq(a + 1, b, c, d)); } break;
                    case 1: { DP.insert(mq(a, b + 1, c, d)); } break;
                    case 2: { DP.insert(mq(a, b, c + 1, d)); } break;
                    case 3: { DP.insert(mq(a, b, c, d + 1)); } break;
                    default: {
                        e = min(min(a, b), min(c, d));
                        if (a == e) DP.insert(mq(a + 1, b, c, d));
                        if (b == e) DP.insert(mq(a, b + 1, c, d));
                        if (c == e) DP.insert(mq(a, b, c + 1, d));
                        if (d == e) DP.insert(mq(a, b, c, d + 1));
                    }
                }
            }
            dp.swap(DP);
//cout<<dp.size()<<endl;
//pvq(dp.begin(),dp.end());
assert(dp.size()<=13);
for(it=dp.begin(),en=dp.end();it!=en;++it)
for(set<qint>::iterator it2=dp.begin(),en2=dp.end();it2!=en2;++it2)
{
assert(abs(it->first.first-it2->first.first)<=2);
assert(abs(it->first.second-it2->first.second)<=2);
assert(abs(it->second.first-it2->second.first)<=2);
assert(abs(it->second.second-it2->second.second)<=2);
assert(abs(it->first.first-it2->first.first)<2||
abs(it->first.second-it2->first.second)<2||
abs(it->second.first-it2->second.first)<2||
abs(it->second.second-it2->second.second)<2);
}
        }
        bool ans[4] = { 0, 0, 0, 0, };
        for (it = dp.begin(), en = dp.end(); it != en; ++it) {
            a = it->first.first;
            b = it->first.second;
            c = it->second.first;
            d = it->second.second;
            e = min(min(a, b), min(c, d));
            if (a == e) ans[0] = 1;
            if (b == e) ans[1] = 1;
            if (c == e) ans[2] = 1;
            if (d == e) ans[3] = 1;
        }
        for (j = 0; j < 4; ++j) {
            if (ans[j]) {
                puts(A[j]);
            }
        }
    }
    
    return 0;
}