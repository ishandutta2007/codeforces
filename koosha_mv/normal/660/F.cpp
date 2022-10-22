#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
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
#define int ll
 
const int N=2e5+9;
 
int n,x[N],y[N],sum,ans,a[N];
double s[N];
vector<int> cht;
 
double inter(int u,int v){
    return double(y[u]-y[v])/double(x[v]-x[u]);
}
 
main(){
    cin>>n;
    f(i,1,n+1) cin>>a[i];

    f_(i,n,1){
        a[i]+=a[i+1];
        sum+=a[i];
        x[i]=a[i];
        y[i]=sum-(n-i)*a[i];
        maxm(ans,sum);
        if(cht.size()){
            int l=0,r=cht.size(),mid;
            while(l+1<r){
                mid=(l+r)/2;
                if(inter(cht[mid-1],cht[mid])<=n-i) l=mid;
                else r=mid;
            }
            maxm(ans,sum-x[cht[l]]*(n-i)-y[cht[l]])
        }
        if(cht.size()==0 || mp(x[i],y[i])<mp(x[cht[cht.size()-1]],y[cht[cht.size()-1]])){
            while(cht.size() && (x[i]==x[cht[cht.size()-1]] || inter(i,cht[cht.size()-1])<=s[cht.size()-1]))
                cht.pop_back();
            if(cht.size()) s[cht.size()]=inter(i,cht[cht.size()-1]);
            cht.pb(i);
        }   
    }
    cout<<ans;
    
}