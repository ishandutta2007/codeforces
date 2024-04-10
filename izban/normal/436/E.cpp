#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 300300;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, w;
pair<pair<int, int>, int> a[maxn];
ll ans;
int pans;

bool cmp(pair<pair<int, int> , int> a, pair<pair<int, int> , int> b) {
    return a.first.first + a.first.second < b.first.first + b.first.second;
}

set<pair<int, int> > st1, st2;
bool is[maxn], inF[maxn];
int cur;
ll sum;

int g(int i) {
    return !is[i] ? a[i].first.first : a[i].first.second;
}

void add(int i) {
    if (st1.size() < cur) {
        st1.insert(make_pair(g(i), i));
        inF[i] = 1;
        sum += g(i);
        return;
    }
    int j = g(i);
    if (st1.empty()) return;
    set<pair<int, int> > :: iterator it = st1.end(); it--;
    if (it->first > j) {
        int o = it->second;
        sum -= g(o);
        sum += j;
        st1.erase(make_pair(g(o), o));
        st2.insert(make_pair(g(o), o));
        st1.insert(make_pair(j, i));
        inF[o] = 0;
        inF[i] = 1;
        return;	
    }
    inF[i] = 0;
    st2.insert(make_pair(j, i));
}

void del(int i) {
    int j = g(i);
    if (st1.find(make_pair(j, i)) != st1.end()) {
        st1.erase(make_pair(j, i));
        inF[i] = 0;
        sum -= j;
    }
    if (st2.find(make_pair(j, i)) != st2.end()) st2.erase(make_pair(j, i));
    if (st1.size() < cur && !st2.empty()) {
        set<pair<int, int> > :: iterator it = st2.begin();
        int o = it->second;
        st2.erase(make_pair(g(o), o));
        st1.insert(make_pair(g(o), o));
        inF[o] = 1;
        sum += g(o);
    }
}

void solve(bool print) {
    if (!print) ans = 8e18;
    sum = 0;
    
    st1.clear();
    st2.clear();
    for (int i = 0; i < n; i++) is[i] = 0, inF[i] = 0;
    cur = w;
    for (int i = 0; i < n; i++) add(i);
    
    ll csum = 0;
    for (int i = 0; i <= n; i++) {
        if (i == pans && print) {
            cout << ans << endl;
            vector<char> s(n);
            for (int j = 0; j < n; j++) s[a[j].second] = '0' + (int)(is[j]) + (int)(inF[j]);
            for (int j = 0; j < n; j++) cout << s[j];
            cout << endl;
            return;
        }
        if (st1.size() == cur) {
            if (ans > sum + csum) {
                ans = sum + csum;
                pans = i;
            }
        }
        if (i == n) break;
        csum += a[i].first.first;
        del(i);
        is[i] = 1;
        add(i);
        cur--;
        if (cur < 0) break;
        if (st1.size() <= cur) continue;
        set<pair<int, int> > :: iterator it = st1.end(); it--;
        int o = it->second;
        del(o);
        add(o);
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    while (cin >> n >> w) {
        for (int i = 0; i < n; i++) {
            cin >> a[i].first.first >> a[i].first.second;
            a[i].first.second -= a[i].first.first;
            a[i].second = i;
        }
        sort(a, a + n, cmp);
        
        solve(0);
        solve(1);
    }
    
	return 0;
}