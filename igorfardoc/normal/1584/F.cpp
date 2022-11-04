#include<bits/stdc++.h>
#define prev prev1
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi dp;
vector<vector<pair<int, int>>> prev;
vvi a;
vector<vvi> pos;
int n;

int calc(int val, int mask) {
    //cout << 1 << ' ' << val << ' ' << mask << endl;
    if(dp[val][mask] != -1) {
        //cout << 2 << endl;
        return dp[val][mask];
    }
    for(int i = 0; i < n; i++) {
        int am = ((mask >> i) & 1) + 1;
        if(am > pos[i][val].size()) {
            dp[val][mask] = 0;
            //cout << 2 << endl;
            return 0;
        }
    }
    //cout << 3 << endl;
    int ansmax = 1;
    int previ = 0;
    int prevmask = 0;
    for(int i = 0; i < pos[0][val][mask & 1]; i++) {
        int masknew = 0;
        int newval = a[0][i];
        //cout << newval << endl;
        if(pos[0][newval][0] != i) {
            masknew = 1;
        }
        bool ok = true;
        for(int j = 1; j < n; j++) {
            if(pos[j][newval].size() > 1 && pos[j][newval][1] < pos[j][val][(mask >> j) & 1]) {
                masknew ^= (1 << j);
            } else if(pos[j][newval].size() > 0 && pos[j][newval][0] < pos[j][val][(mask >> j) & 1]) {

            } else {
                ok = false;
                break;
            }
        }
        if(!ok) {
            continue;
        }
        if(calc(newval, masknew) + 1 > ansmax) {
            ansmax = calc(newval, masknew) + 1;
            previ = newval;
            prevmask = masknew;
        }
    }
    dp[val][mask] = ansmax;
    prev[val][mask] = {previ, prevmask};
    //cout << 2 << endl;
    return ansmax;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<string> s(n);
        a.assign(n, vi(0));
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            for(int j = 0; j < s[i].size(); j++) {
                if(s[i][j] >= 'a' && s[i][j] <= 'z') {
                    a[i].push_back(s[i][j] - 'a');
                } else {
                    a[i].push_back(s[i][j] - 'A' + 26);
                }
            }
        }
        dp.assign(52, vi(1 << n, -1));
        prev.assign(52, vector<pair<int, int>>(1 << n));
        pos.assign(n, vvi(52, vi(0)));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < a[i].size(); j++) {
                pos[i][a[i][j]].push_back(j);
            }
        }
        int maxi = -1;
        int maxmask = -1;
        int ans = -1;
        for(int i = 0; i < 52; i++) {
            for(int mask = 0; mask < (1 << n); mask++) {
                if(calc(i, mask) > ans) {
                    ans = calc(i, mask);
                    maxi = i;
                    maxmask = mask;
                }
            }
        }
        cout << ans << '\n';
        vi res;
        int nowans = ans;
        while(nowans > 0) {
            //cout << maxi << ' ' << maxmask << endl;
            res.push_back(maxi);
            int newi = prev[maxi][maxmask].first;
            int newmask = prev[maxi][maxmask].second;
            maxi = newi;
            maxmask = newmask;
            --nowans;
        }
        for(int i = (int)res.size() - 1; i >= 0; i--) {
            if(res[i] < 26) {
                cout << (char)('a' + res[i]);
            } else {
                cout << (char)('A' + res[i] - 26);
            }
        }
        cout << '\n';
    }
}