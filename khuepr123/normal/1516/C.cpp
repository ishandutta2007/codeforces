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
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;
map<int, int> mp;
int od = 0;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int gd = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        gd = __gcd(a[i], gd);
    }
    int sam = 0;
    for(int i = 1; i <= n; i++){
        a[i] = a[i] / gd;
        sam += a[i];
        if(a[i] % 2) od = i;
    }
    if(sam % 2){
        cout << "0\n"; return 0;
    }
    mp[0] = 0;
    for(int i = 1; i <= n; i++){
        vector<int> g;
        for(auto itr = mp.begin(); itr != mp.end(); ++itr){
            g.pb(itr->fi + a[i]);
        }
        for(auto i : g){
            mp[i] = 0;
        }
    }
    if(mp.find(sam / 2) == mp.end()){
        cout << "0\n"; return 0;
    }
    else{
        cout << "1\n" << od; return 0;
    }
}