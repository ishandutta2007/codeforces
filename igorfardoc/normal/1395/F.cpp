#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int maxb, minb, maxn, minn, maxs, mins;
    maxb = -INF;
    maxn = -INF;
    maxs = -INF;
    minb = INF;
    minn = INF;
    mins = INF;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int bhere = 0;
        int nhere = 0;
        int shere = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == 'B') {
                ++bhere;
                ++shere;
            } else {
                ++nhere;
                --shere;
            }
        }
        maxb = max(maxb, bhere);
        maxs = max(maxs, shere);
        maxn = max(maxn, nhere);
        minb = min(minb, bhere);
        mins = min(mins, shere);
        minn = min(minn, nhere);
    }
    //cout << minb << ' '  << maxb << ' ' << minn <<  ' ' << maxn << ' '  << mins << ' ' << maxs << endl;
    int l = -1;
    int r = 1000000;
    int optn = -1;
    int optb = -1;
    while(r - l > 1) {
        int m = (l + r) / 2;
        bool can = false;
        for(int b2 = 0; b2 <= 500000; b2++) {
            if(maxb - b2 > m || b2 - minb > m) {
                continue;
            }
            /*if(b2 == 1 && m == 1) {
                cout << 1234 << endl;
            }*/
            int rn2 = minn + m;
            int ln2 = maxn - m;
            if(ln2 > rn2) {
                continue;
            }
            rn2 = min(rn2, m - maxs + b2);
            if(rn2 < ln2) {
                continue;
            }
            ln2 = max(ln2, b2 - m - mins);
            if(rn2 < ln2 || rn2 < 0 || (b2 == 0 && rn2 == 0)) {
                continue;
            }
            optb = b2;
            optn = rn2;
            can = true;
            break;
        }
        if(can) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
    for(int i = 0; i < optb; i++) {
        cout << 'B';
    }
    for(int i = 0; i < optn; i++) {
        cout << 'N';
    }
}