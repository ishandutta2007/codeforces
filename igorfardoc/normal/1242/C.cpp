#include<bits/stdc++.h>
#define maxa 1000000000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int k;
vvi a;
vi dp;
unordered_map<int, int> where;
vector<ll> now;
vi c, p;
ll need = 0;

bool rec(int mask) {
    if(dp[mask] != -1) {
        return dp[mask];
    }
    if(mask == 0) {
        dp[mask] = 1;
        return 1;
    }
    int fir;
    for(int i = 0; i < k; i++) {
        if((mask >> i) & 1) {
            fir = i;
            break;
        }
    }
    if(mask == (1 << fir)) {
        if(need == now[fir]) {
            dp[mask] = 1;
            p[fir] = fir;
            c[fir] = a[fir][0];
            return 1;
        }
        dp[mask] = 0;
        return 0;
    }
    for(int i = 0; i < a[fir].size(); i++) {
        int take = a[fir][i];
        int nowid = fir;
        c[fir] = take;
        ll needhere = need - (now[fir] - take);
        int ok = mask;
        while(true) {
            if(needhere > maxa || needhere < -maxa) {
                break;
            }
            auto it = where.find(needhere);
            if(it == where.end()) break;
            int id1 = it->second;
            if(!((ok >> id1) & 1)) break;
            ok ^= (1 << id1);
            p[id1] = nowid;
            c[id1] = needhere;
            nowid = id1;
            if(id1 == fir) {
                //cout << fir << ' ' << take << ' ' << needhere << endl;
                //p[fir] = id1;
                if(needhere == take && rec(ok)) {
                    dp[mask] = 1;
                    return 1;
                } else {
                    break;
                }
            }
            needhere = need - (now[id1] - needhere);
        }
    }
    dp[mask] = 0;
    return 0;
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
    cin >> k;
    a.resize(k);
    where.reserve(300000);
    ll sum = 0;
    now.assign(k, 0);
    for(int i = 0; i < k; i++) {
        int n;
        cin >> n;
        a[i].resize(n);
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            sum += a[i][j];
            now[i] += a[i][j];
            where[a[i][j]] = i;
        }
    }
    if(sum % k != 0) {
        cout << "No";
        return 0;
    }
    need = sum / k;
    dp.assign(1 << k, -1);
    c.resize(k);
    p.resize(k);
    if(!rec((1 << k) - 1)) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    for(int i = 0; i < k; i++) {
        cout << c[i] << ' ' << p[i] + 1 << '\n';
    }
}