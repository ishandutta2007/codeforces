#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+99;
 
ll n,q,a[N],b[N],t[2][N];
 
void build(){
    f(i,1,n+1){
        t[0][i+n-1]=t[1][i+n-1]=a[i];
    }
    f_(i,n-1,1){
        t[0][i]=min(t[0][i*2+0],t[0][i*2+1]);
        t[1][i]=max(t[1][i*2+0],t[1][i*2+1]);
    }
}
ll Mx(int l,int r){
	l--;
    ll mx=-1e18;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) maxm(mx,t[1][l++])
        if (r&1) maxm(mx,t[1][--r]);
    }
    //cout<<l<<" "<<r<<" : "<<mx<<endl;
    return mx;
}
ll Mn(int l,int r){
    l--;
    ll mn=1e18;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) minm(mn,t[0][l++])
        if (r&1) minm(mn,t[0][--r]);
    }
    return mn;
}
 
int main(){
    cin>>n>>q;
    f(i,1,n+1){
        cin>>a[i];
    }
    f(i,1,n+1){
        cin>>b[i];
        a[i]=b[i]-a[i];
        a[i]+=a[i-1];
        //cout<<a[i]<<" ";
    }cout<<endl;
    build();
    while(q--){
        int l,r;
        Gett(l,r);
        if(a[l-1]!=a[r] || Mn(l,r)<a[l-1]) cout<<-1<<'\n';
        else{
            cout<<Mx(l,r)-a[l-1]<<'\n';
        }
    }
}