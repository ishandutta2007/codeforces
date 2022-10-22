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
 
const int N=4e5+99;
 
int n,c,ans,a[N],b[N],t[N],mn[N];
vector<int> v;
 
int F(int x){
    x=v[x];
    return max(a[x],b[x]);
}
bool cmp(int i,int j){
    return min(a[i],b[i])<min(a[j],b[j]);
}
void check(){
    int mv=2*n+1;
    f(i,0,n){
        //cout<<a[v[i]]<<" "<<b[v[i]]<<endl;
        if(mv<F(i)){ cout<<-1; exit(0); }
        if(mn[i]<F(i)) minm(mv,F(i));
    }
}
int main(){
    cin>>n;
    f(i,0,n){
        cin>>a[i]>>b[i];
        v.pb(i);
        if(a[i]>b[i]) ans++;
        if((a[i]<=n)==(b[i]<=n)) return cout<<-1,0;
    }
    sort(v.begin(),v.end(),cmp);
    mn[0]=2*N;
    f(i,1,n)
        mn[i]=min(mn[i-1],F(i-1));
    check();
    f(i,0,n){
        int p=0;
        if(mn[i]<F(i)) p=1;
       // cout<<p<<endl;
        if(a[v[i]]<b[v[i]]) t[c+p]++;
        else t[c+p]--;
        if(min(mn[i],F(i))==2*n-i) c+=2;
    }    
    for(int i=0;i<2*n;i+=2) ans+=min(t[i],t[i+1]);
    cout<<ans;
}