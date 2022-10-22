#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define int long long
#define PI 3.141592653589793238462643383279502884
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, m; ll b[maxN], a[maxN]; int chk[maxN]; int dis[maxN]; int mxd[maxN]; bool kil[maxN]; int mn; int cursor;
int ray[maxN]; int cnt; int l, r;
int mark;

void tcin(){ // typical cin
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}
void tcin2(){
    cin >> n >> m;; for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m ;i++){
        cin >> b[i];
    }
}
void typre(){ // typical reset
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0; dis[i] = n + 1; mxd[i] = n + 1; kil[i] = 0;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        tcin(); typre();
        for(int i = 1; i <= n; i++){
            if(!chk[a[i]]){
                chk[a[i]] = i;
                mxd[a[i]] = i;
            }
            else{
                mxd[a[i]] = max(mxd[a[i]], i - chk[a[i]]);
                chk[a[i]] = i;
            }
        }
        for(int i = 1; i <= n; i++){
            if(chk[a[i]]){
                mxd[a[i]] = max(mxd[a[i]], n + 1 - chk[a[i]]);
            }
        }
        // mxd done
        ray[0] = 0; mxd[0] = n + 1;
        cursor = 1; ray[1] = n + 1; cnt = 1;
        for(int i = 1; i <= n; i++){
            if(mxd[i] > n){
                continue;
            }
            ray[1] = i; mn = mxd[i]; break;
        }
        for(int i = ray[1] + 1; i <= n; i++){
            if(mxd[i] >= mn){
                kil[i] = 1;
            }
            else{
                mn = mxd[i]; cnt++; ray[cnt] = i;
            }
        }
        mxd[0] = n + 1;
        for(int i = n; i > 0; i--){
            if(kil[i]){continue;}
            while(cursor < mxd[i]){
                cout << -1 << " "; cursor++; // cursor mark the minimum
            }
            mark = i; break; // mark mark the current space for development
        }
        for(int i = cnt; i > 0; i--){
            while(cursor < mxd[ray[i - 1]]){
                cout << ray[i] << " "; cursor++;
            }
        }
        cout << '\n';
    }
}