// In the name of god
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <bits/stdc++.h>
#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()
using namespace std;

template <typename T>
T next_int() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if(ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return p * x;
}

string next_token() {
    char ch;
    string ans = "";
    do { ch = getchar(); } while(ch <= ' ');
    while(ch > ' ') {
        ans += ch;
        ch = getchar();
    }
    return ans;
}

const long long INF = (long long)1e18;
const int INFINT = (int)1e9 + 227 + 1;
const int maxn = (int)1e6 + 227 + 1;
const int MOD = (int)1e9 + 7;
const long double EPS = 1e-9;

long long bin_pow(long long a, long long b) {
    if(!b) return 1;
    long long ans = bin_pow(a, b / 2);
    ans = ans * ans;
    if(b % 2) ans = ans * a;
    return ans;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    set<pair<int, int> > q;
    vector<vector<int> > ans;
    for(int i = 0; i < n; i++) {
        int a = next_int<int>();

        set<pair<int, int> > :: iterator it = q.lower_bound(make_pair(a, 0));
        if(i == 0 || it == q.begin()) {
            ans.push_back(vector<int>(1, a));
            q.insert(make_pair(a, ans.size() - 1));
        } else {
            it--;

            pair<int, int> temp = *it;
            q.erase(it);
            ans[temp.second].push_back(a);
            q.insert(make_pair(a, temp.second));
        }
    }

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        puts("");
    }

    return 0;
}