#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
int l, r;

map<ii, int> mp;

void kil(ii pr){
    if(mp[pr] == 0) mp.erase(pr);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        mp.clear();
        int ans = 0;
        cin >> n >> l >> r;
        for1(i, 1, l){
            cin >> a[i];
            mp[ii(a[i], 0)]++;
        }
        for1(i, 1, r){
            cin >> a[i];
            mp[ii(a[i], 1)]++;
        }
        auto itr = mp.begin();
        while(itr != mp.end()){
            if(mp.find(ii((itr->fi).fi, 1 - (itr->fi).se)) == mp.end()) ++itr;
            else{
                ii pr = ii((itr->fi).fi, 1 - (itr->fi).se);
                mp[itr->fi]--;
                mp[pr]--;
                kil(pr);
                l--;
                r--;
                n -= 2;
                if(mp[itr->fi] == 0){
                    auto itt = itr;
                    ++itr;
                    kil(itt->fi);
                }
            }
        }
        bool fake = 0;
        if(l < r){
            swap(l, r);
            fake = 1;
        }
        int cn[2];
        cn[1] = 0; cn[0] = 0;
        // l >= r
        for(auto itr = mp.begin(); itr != mp.end(); ++itr){
            int bak = ((itr->fi).se xor fake);
            cn[bak] += (itr->se / 2);
        }
        // left and right and prleft and prright
        int dis = (l - r) / 2;
        dis = min(dis, cn[0]);
        l -= dis * 2;
        cn[0] -= dis;
        ans += dis;
        
        cout << ans + l << endl;
    }
}