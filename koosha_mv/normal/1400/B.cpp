#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

ll n,t,p,c,w,s,cntw,cnts;
ll ans=0;

ll calc(ll p,ll cntw,ll cnts){
    ll res=0,h=0;
    if(w>s){ swap(s,w),swap(cntw,cnts); h=1; }
    res=min(p/w,cntw);
    p-=res*w;
    res+=min(p/s,cnts);
    if(h) swap(s,w);
    return res;
}

int main(){
	cin>>t;
	f(q,0,t){
	    ans=0;
		cin>>c>>p>>cntw>>cnts>>w>>s;
		f(i,0,cntw+1)
		    if(i*w<=c)
		        maxm(ans,i+min(cnts,(c-i*w)/s)+calc(p,cntw-i,cnts-min(cnts,(c-i*w)/s)));
		cout<<ans<<'\n';
	}
}