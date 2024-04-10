#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
map<int, int> mp;

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; mp.clear();
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        int mx = 0;
        for(auto itr = mp.begin(); itr != mp.end(); ++itr){
            mx = max(mx, itr->se);
        }
        cout << mx << endl;
    }
}