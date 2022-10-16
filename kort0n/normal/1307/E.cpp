#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
const ll mod = 1000000007;
ll N, M;
vector<ll> s;
vector<ll> num, lnum, lIndex, rIndex;
vector<vector<ll>> cow;
ll ans1 = 0;
ll ans = 0;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    s.resize(N);
    num.resize(N);
    lnum.resize(N);
    cow.resize(N);
    lIndex.resize(N);
    rIndex.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> s[i];
        s[i]--;
        num[s[i]]++;
    }
    for(int i = 0; i < M; i++) {
        int s, h;
        cin >> s >> h;
        s--;
        //cerr << i << " " << s << " " << h << endl;
        if(num[s] < h) {
            i--;
            M--;
            continue;
        }
        cow[s].push_back(h);
    }
    for(int i = 0; i < N; i++) {
        lIndex[i] = 0;
        rIndex[i] = cow[i].size();
        if(cow[i].empty()) continue;
        sort(cow[i].begin(), cow[i].end());
    }
    for(ll l = 0; l <= N; l++) {
        bool flag = false;
        if(l == 0) flag = true;
        if(l > 0) {
            lnum[s[l-1]]++;
        }
        ll nownum = 0;
        ll nowans = 1;
        for(int i = 0; i < N; i++) {
            if(cow[i].empty()) continue;
            while(lIndex[i] < cow[i].size()) {
                if(cow[i][lIndex[i]] > lnum[i]) break;
                lIndex[i]++;
            }
            ll rnum = num[i] - lnum[i];
            //cerr << l << " " << i << " " << lnum[i] << " " << rnum << endl;
            while(rIndex[i] > 0) {
                if(cow[i][rIndex[i]-1] <= rnum) break;
                //cerr << "out: " << l << " " << i << " " << rIndex[i] << " " << cow[i][rIndex[i]-1] << endl;
                rIndex[i]--;
            }
            //cerr << l << " " << i << " " << lIndex[i] << " " << rIndex[i] << endl;
            if(l > 0 and lIndex[i] > 0 and cow[i][lIndex[i]-1] == lnum[i] and s[l-1] == i) {
                flag = true;
                ll factor = rIndex[i];
                if(rIndex[i] >= lIndex[i]) factor--;
                if(factor == 0) {
                    nownum++;
                } else {
                    nownum += 2;
                    nowans *= factor;
                    nowans %= mod;
                }
            } else {
                ll num1 = lIndex[i];
                ll num2 = rIndex[i];
                if(num1 > num2) {
                    swap(num1, num2);
                }
                if(num2 == 0) {
                    continue;
                } else {
                    ll factor = num1 * (num2 - 1);
                    if(factor == 0) {
                        nownum++;
                        nowans *= (num1 + num2);
                        nowans %= mod;
                    } else {
                        nownum += 2;
                        nowans *= factor;
                        nowans %= mod;
                    }
                }
            }
        }
        //cerr << "end: " << l << " " << flag << " " << nownum << " " << nowans << endl;
        if(!flag) continue;
        chmax(ans1, nownum);
    }
    for(int i = 0; i < N; i++) {
        lIndex[i] = 0;
        rIndex[i] = cow[i].size();
        if(cow[i].empty()) continue;
        sort(cow[i].begin(), cow[i].end());
    }
    for(int i = 0; i < N; i++) lnum[i] = 0;
    for(ll l = 0; l <= N; l++) {
        bool flag = false;
        if(l == 0) flag = true;
        if(l > 0) {
            lnum[s[l-1]]++;
        }
        ll nownum = 0;
        ll nowans = 1;
        for(int i = 0; i < N; i++) {
            if(cow[i].empty()) continue;
            while(lIndex[i] < cow[i].size()) {
                if(cow[i][lIndex[i]] > lnum[i]) break;
                lIndex[i]++;
            }
            ll rnum = num[i] - lnum[i];
            //cerr << l << " " << i << " " << lnum[i] << " " << rnum << endl;
            while(rIndex[i] > 0) {
                if(cow[i][rIndex[i]-1] <= rnum) break;
                //cerr << "out: " << l << " " << i << " " << rIndex[i] << " " << cow[i][rIndex[i]-1] << endl;
                rIndex[i]--;
            }
            //cerr << l << " " << i << " " << lIndex[i] << " " << rIndex[i] << endl;
            if(l > 0 and lIndex[i] > 0 and cow[i][lIndex[i]-1] == lnum[i] and s[l-1] == i) {
                flag = true;
                ll factor = rIndex[i];
                if(rIndex[i] >= lIndex[i]) factor--;
                if(factor == 0) {
                    nownum++;
                } else {
                    nownum += 2;
                    nowans *= factor;
                    nowans %= mod;
                }
            } else {
                ll num1 = lIndex[i];
                ll num2 = rIndex[i];
                if(num1 > num2) {
                    swap(num1, num2);
                }
                if(num2 == 0) {
                    continue;
                } else {
                    ll factor = num1 * (num2 - 1);
                    if(factor == 0) {
                        nownum++;
                        nowans *= (num1 + num2);
                        nowans %= mod;
                    } else {
                        nownum += 2;
                        nowans *= factor;
                        nowans %= mod;
                    }
                }
            }
        }
        //cerr << "end: " << l << " " << flag << " " << nownum << " " << nowans << endl;
        if(!flag) continue;
        if(nownum != ans1) continue;
        ans += nowans;
        ans %= mod;
    }
    cout << ans1 << " " << ans << endl;
    return 0;
}