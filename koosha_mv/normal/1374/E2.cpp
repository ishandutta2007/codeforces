#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+99;
 
int n,k,m,x,y,p0,p1,p2,b0,b1,b2,b3,a[N];
vector<pair<ll,int> > v0,v1,v2,v3;
ll ans=1e18,sum;
 
void calc(int x){
	if(p0<v0.size()-1) p0++,sum+=v0[p0].F;
	if(p0<v0.size()-1) p0++,sum+=v0[p0].F;
	if(k-x>=int(v1.size()) || k-x>=int(v2.size()) || x+v2.size()+v1.size()+v0.size()-3<m || x+max((k-x),0)*2>m) return ;
	while(x+p1+p2+p0>m){
		if(p0 && (p1==max(k-x,0) || v0[p0]>=v1[p1]) && (p2==max(k-x,0) || v0[p0]>=v2[p2]))
			sum-=v0[p0--].F;
		else{
			if(p1==max(k-x,0) || (p2!=max(k-x,0) && v2[p2].F>=v1[p1].F)){
				while(p2==max(k-x,0)) n=1;
				sum-=v2[p2--].F;
			}
			else
				sum-=v1[p1--].F;
		}
	}
	//cout<<x<<" : "<<p0<<" "<<p1<<" "<<p2<<" ANS : "<<sum+v3[x].F<<endl;
	if(sum+v3[x].F<ans)
		ans=sum+v3[x].F,b0=p0,b1=p1,b2=p2,b3=x;
}
 
int main(){
	cin>>n>>m>>k;
	v1.pb(mp(0,0)),v2.pb(mp(0,0)),v3.pb(mp(0,0)),v0.pb(mp(0,0));
	f(i,0,n){
		gett(a[i]);
		Gett(x,y);
		if(x==1 && y==1)
			v3.pb(mp(a[i],i+1));
		if(x==1 && y==0)
			v1.pb(mp(a[i],i+1));
		if(x==0 && y==1)
			v2.pb(mp(a[i],i+1));	
		if(x==0 && y==0)
			v0.pb(mp(a[i],i+1));		
	}
	p0=v0.size()-1,p1=v1.size()-1,p2=v2.size()-1;
	sort(v0.begin(),v0.end());
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	sort(v3.begin(),v3.end());
	f(i,1,v0.size()) sum+=v0[i].F;
	f(i,1,v1.size()) sum+=v1[i].F;
	f(i,1,v2.size()) sum+=v2[i].F;
	f(i,1,v3.size()) v3[i].F+=v3[i-1].F;
	f(i,0,v3.size())
		calc(i);
	if(ans==1e18) return cout<<-1,0;
	cout<<ans<<endl;
	f(i,1,b0+1) cout<<v0[i].S<<" ";
	f(i,1,b1+1) cout<<v1[i].S<<" ";
	f(i,1,b2+1) cout<<v2[i].S<<" ";
	f(i,1,b3+1) cout<<v3[i].S<<" ";
}