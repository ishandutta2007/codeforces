#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define iii pair<int, ii>
#define se second
#define fi first

map<int, ii> mp;
int n;
ii a[200005];
int sum;

signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].fi;
    for(int i = 1; i <= n; i++) a[i].se = i;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            sum = a[i].fi + a[j].fi;
            if(mp.find(sum) != mp.end()){
                if(a[i].se == mp[sum].fi || a[i].se == mp[sum].se || a[j].se == mp[sum].fi || a[j].se == mp[sum].se) continue;
                cout << "YES\n";
                cout << a[i].se << " " << a[j].se << " ";
                cout << mp[sum].fi << " " << mp[sum].se;
                return 0;
            }
            mp[sum] = make_pair(a[i].se, a[j].se);
        }
    }
    cout << "NO\n";
}