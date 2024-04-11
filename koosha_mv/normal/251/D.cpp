#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e5+9,Lg=62;
 
ll n,xr,a[N],mask[Lg],ans[N];
vector<int> v,p;
 
void maXor(){
    ll res=0,Mask=0;
    f(i,0,n){
        ll x=a[i];
        f(j,0,v.size())
            minm(x,x^a[v[j]]);
        if(x){
            int l=v.size();
			v.pb(i),mask[l]|=(1LL<<l);
			f(j,0,l)
				if (a[i]>(a[i]^a[v[j]])){
					a[i]^=a[v[j]];
					mask[l]^=mask[j];
				}
        }
    }
    f(i,0,v.size())
        if(res<(res^a[v[i]]))
            res=res^a[v[i]],Mask^=mask[i];
    f(i,0,Lg)
        if(Mask&(1ll<<i))
            ans[v[i]]=1;
}
 
int main(){
    cin>>n;
    f(i,0,n){ 
        cin>>a[i]; 
        xr^=a[i]; 
    }
    f(i,0,Lg)
        if(xr&(1ll<<i))
            p.pb(i);
    f(i,0,Lg)
        if(!(xr&(1ll<<i)))
            p.pb(i);
    f(i,0,n){
        ll x=0;
        f(j,0,Lg)
            if(a[i]&(1ll<<p[j]))
                x|=(1ll<<j);
        a[i]=x;
    }
    maXor();
    f(i,0,n) cout<<ans[i]+1<<" ";
}