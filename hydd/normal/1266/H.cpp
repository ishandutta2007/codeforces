#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,b[65],r[65];
ll qpow(ll x,ll a,ll Mod){
    ll res=1;
    while (a){
        if (a&1) res=(__int128)res*x%Mod;
        x=(__int128)x*x%Mod; a>>=1;
    }
    return res;
}
struct Equation{
    ll Mod,a[65][185],z[65],w[65],x[65];
    void Gauss(){
        for (int i=1;i<=n;i++){
            if (!a[i][i]){
                int k=-1;
                for (int j=i+1;j<=n;j++)
                    if (a[j][i]) k=i;
                if (k==-1) return;
                swap(a[i],a[k]);
            }
            ll inv=qpow(a[i][i],Mod-2,Mod);
            for (int k=i;k<=n+n+n;k++) a[i][k]=(__int128)a[i][k]*inv%Mod;
            for (int j=1;j<=n;j++){
                if (i==j) continue; ll val=Mod-a[j][i];
                for (int k=i;k<=n+n+n;k++) a[j][k]=(a[j][k]+(__int128)val*a[i][k])%Mod;
            }
        }
    }
    void Build(ll m){
        Mod=m;
        for (int i=1;i<=n;i++){
            a[i][i]+=2; a[i][n+i]++; a[i][n+n+i]--;
            for (int j=1;j<=n;j++){
                if (r[j]==i) a[i][j]--;
                if (b[j]==i) a[i][j]--,a[i][n+j]--;
            }
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n+n+n;j++)
                a[i][j]=(Mod+a[i][j])%Mod;
        Gauss();
    }
    ll query(int v,string s){
        for (int i=1;i<=n;i++){
            z[i]=(s[i]=='R');
            w[i]=0;
        }
        w[1]--; w[v]++; w[1]=(Mod+w[1])%Mod;
        ll res=0;
        for (int i=1;i<=n;i++){
            x[i]=0;
            for (int j=1;j<=n;j++) x[i]=(x[i]+(__int128)a[i][n+j]*z[j]+(__int128)a[i][n+n+j]*w[j])%Mod;
            res=((__int128)res+x[i]+x[i]+Mod-z[i])%Mod;
        }
        return res;
    }
} A,B;
int vis[65],now;
ll calc(int v,string s){
    ll x=A.query(v,s),y=B.query(v,s);
    for (int i=1;i<=n;i++){
        if (A.x[i]!=B.x[i]||A.x[i]<A.z[i]) return -1;
        if (A.x[i]){
            int u=i; now++;
            while (vis[u]!=now) vis[u]=now,u=(s[u]=='R'?r[u]:b[u]);
            if (vis[v]!=now) return -1;
        }
    }
    return x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n; n--;
    for (int i=1;i<=n;i++) cin>>b[i]>>r[i];
    A.Build(9000000000000000041);//9e18+41
    B.Build(9000000000000000053);//9e18+53
    cin>>q; int v; string s;
    while (q--){
        cin>>v>>s; s=" "+s;
        cout<<calc(v,s)<<'\n';
    }
    return 0;
}