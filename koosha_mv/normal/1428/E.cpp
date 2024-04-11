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
const ll inf=1e18;
 
int n,k,a[N],b[N];
ll sum,ans;
set<pair<ll,int> > s1,s2;
 
ll calc(int x,int k){
    if(k==0 || x<k) return inf;
    ll res=0;
    int c=x/k;
    res+=1ll*c*c*k;
    res+=(x%k)*(c*2+1);
    return res;
}
void add(int x){
    s1.insert(mp(calc(a[x],b[x]-1)-calc(a[x],b[x]),x));
    s2.insert(mp(calc(a[x],b[x])-calc(a[x],b[x]+1),x));
}
void del(int x){
    s1.erase(mp(calc(a[x],b[x]-1)-calc(a[x],b[x]),x));
    s2.erase(mp(calc(a[x],b[x])-calc(a[x],b[x]+1),x));
}
void do_it(pair<ll,int> p1,pair<ll,int> p2){
    ans+=p1.F-p2.F;
        
    del(p1.S);
    b[p1.S]--;
    add(p1.S);
    
    del(p2.S);
    b[p2.S]++;
    add(p2.S);
}
 
int main(){
    cin>>n>>k;
    int copy=k;
    k-=n;
    f(i,0,n){
        gett(a[i]);
        b[i]=1+min(k,a[i]-1);
        k-=min(k,a[i]-1);
        ans+=calc(a[i],b[i]);
    }
    if(n==1) return cout<<calc(a[0],copy),0;
    
    f(i,0,n)
        add(i);
    while(1){
        pair<ll,int> a,b,c,d;
        a=*s1.begin();
        s1.erase(a);
        b=*s1.begin();
        
        c=*s2.rbegin();
        s2.erase(c);
        d=*s2.rbegin();
        if(a.F<c.F && a.S!=c.S)
            do_it(a,c);
        else{
            if(a.F<d.F && a.S!=d.S)
                do_it(a,d);
            else{
                if(b.F<c.F && b.S!=c.S)
                    do_it(b,c);
                else
                    break;
            }
        }
    }
    cout<<ans;
}