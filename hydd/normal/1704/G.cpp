#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> poly;
int T,n,m; ll a[410000],b[410000];
poly f,g,h; bool ok[410000];
int cnt; ll num[410000];
ll qpow(ll x,ll a,ll Mod){
    ll res=1;
    while (a){
        if (a&1) res=res*x%Mod;
        x=x*x%Mod; a>>=1;
    }
    return res;
}
struct Poly{
    int Mod,rev[1100000];
    void NTT(poly &a,int op){
        int n=a.size();
        for (int i=0;i<n;i++)
            if (i<rev[i]) swap(a[i],a[rev[i]]);
        for (int mid=1;mid<n;mid<<=1){
            ll w=qpow(3,(Mod-1)/(mid<<1),Mod);
            if (op!=1) w=qpow(w,Mod-2,Mod);
            for (int i=0;i<n;i+=(mid<<1)){
                ll omega=1;
                for (int j=0;j<mid;j++,omega=omega*w%Mod){
                    ll x=a[i+j],y=omega*a[i+j+mid]%Mod;
                    a[i+j]=(x+y)%Mod; a[i+j+mid]=(x-y+Mod)%Mod;
                }
            }
        }
        if (op!=1){
            ll inv=qpow(n,Mod-2,Mod);
            for (int i=0;i<n;i++) a[i]=inv*a[i]%Mod;
        }
    }
    void mulp(poly a,poly b,poly &c){
        int len=a.size()+b.size(),bit=0;
        while ((1<<bit)<len) bit++;

        int n=(1<<bit);
        for (int i=0;i<n;i++) rev[i]=((rev[i>>1]>>1)|((i&1)<<(bit-1)));

        a.resize(n); b.resize(n);
        NTT(a,1); NTT(b,1);
        c.resize(n);
        for (int i=0;i<n;i++) c[i]=1ll*a[i]*b[i]%Mod;
        NTT(c,-1);
    }
    void solve(int n,int m){
        reverse(g.begin(),g.end());
        ll s1=0,s2=0;
        for (int i=0;i<m;i++){
            s2+=g[m-1-i]*g[m-1-i]-g[m-1-i];
            s1+=f[i]*f[i]+f[i];
        }
        mulp(f,g,h);
        for (int i=0;i+m-1<n;i++){
            if ((s1+s2-2*h[i+m-1])%Mod) ok[i]=false;
            s1-=f[i]*f[i]+f[i]; if (i+m<n) s1+=f[i+m]*f[i+m]+f[i+m];
        }
        reverse(g.begin(),g.end());
    }
} A,B;
ll calc1(int x){
    if (!(x&1)) x--;
    return 1ll*(1+x)*(1+x)/4;
}
ll calc2(int x){
    if (x&1) x--;
    return 1ll*(2+x)*x/4;
}
ll calc(int l,int r){
    if (l>r) return 0;
    return 1ll*(l+r)*(r-l+1)/2;
}
int Ans[210000];
void print1(ll p){
    for (int i=0;i<n;i++) Ans[i]=0;
    ll x=a[p]-b[0];
    for (int i=0;i<=p;i++)
        if ((p-i+1)&1) x+=(p-i+1),Ans[i]^=1;
    for (int i=0;i<=p;i++)
        if (x>=(p-i+1)) x-=(p-i+1),Ans[i]^=1;
    assert(x==0); int ans=0;
    for (int i=0;i<n;i++) ans+=Ans[i];
    cout<<ans<<'\n';
    for (int i=0;i<n;i++)
        if (Ans[i]) cout<<i+1<<' ';
    cout<<'\n';
}
void print2(ll p,int d){
    for (int i=0;i<n;i++) Ans[i]=0;
    ll x=a[p]-b[0];
    for (int i=0;i<=p+1;i++)
        if ((p-i+1)&1) x+=(p-i+1),Ans[i]^=1;
    for (int i=0;i<=p+1;i++)
        if (d&&x>=(p-i+1)+calc(0,d-2)) x-=(p-i+1),d--,Ans[i]^=1;
    for (int i=0;i<m-2;i++)
        if (f[p+i]!=g[i]) Ans[p+i+2]^=1;
    assert(x==0&&d==0); int ans=0;
    for (int i=0;i<n;i++) ans+=Ans[i];
    cout<<ans<<'\n';
    for (int i=0;i<n;i++)
        if (Ans[i]) cout<<i+1<<' ';
    cout<<'\n';
}
void work(){
    cin>>n; for (int i=0;i<n;i++) cin>>a[i];
    cin>>m; for (int i=0;i<m;i++) cin>>b[i];

    f.clear(); g.clear(); h.clear();
    if (m>1){
        f.resize(n-2); g.resize(m-2);
        for (int i=0;i<n-2;i++) f[i]=a[i]+2*a[i+1]+a[i+2];
        for (int i=0;i<m-2;i++) g[i]=b[i]+2*b[i+1]+b[i+2];

        cnt=0;
        for (int i=0;i<n-2;i++){
            num[++cnt]=f[i];
            num[++cnt]=f[i]+1;
        }
        sort(num+1,num+cnt+1); cnt=unique(num+1,num+cnt+1)-num-1;
        for (int i=0;i<n-2;i++) f[i]=lower_bound(num+1,num+cnt+1,f[i])-num;
        for (int i=0;i<m-2;i++){
            int t=lower_bound(num+1,num+cnt+1,g[i])-num;
            if (num[t]==g[i]) g[i]=t; else g[i]=0;
        }
        for (int i=0;i+m-1<n;i++) ok[i]=true;
        A.solve(n-2,m-2); B.solve(n-2,m-2);
    }

    for (int i=0;i+m-1<n;i++)
        if (m==2||ok[i]){
            ll x=a[i]+calc1(i+1),y=a[i+1]-calc2(i+2);
            ll d=(b[0]+b[1])-(x+y);
            if (0<=d&&d<=i+2)
                if (x-calc(i+1-d+1,i+1)<=b[0]&&b[0]<=x-calc(0,d-1)){
                    print2(i,d);
                    return;
                }
        }
    cout<<"-1\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>T; A.Mod=998244353; B.Mod=1004535809;
    while (T--) work();
    return 0;
}