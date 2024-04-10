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
int n, m; int a[maxN], b[maxN]; bool chk[maxN];
map<int, int> mp; int cnt;

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> m; mp.clear(); cnt = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            mp.insert(pair<int, int>(a[i], 1));
        }
        for(int j = 1; j <= m;  j++){
            cin >> b[j];
            if(mp[b[j]] == 1) cnt++;
        }
        cout << cnt << endl;
    }
}