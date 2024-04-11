#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
ll a,b,c,d,t0,t1,kh,g;
string ans;
int main(){
	cin>>a>>b>>c>>d;
	t0=sqrt(a*2)+1;
	t1=sqrt(d*2)+1;

	if(a==0){
		if(b || c) t0=1;
		else{
			if(t1*(t1-1)!=d*2) return cout<<"Impossible",0;
			f(i,0,t1) cout<<'1';
			return 0;
		}
	}
	if(d==0){
		if(b || c) t1=1;	
		else{
			if(t0*(t0-1)!=a*2) return cout<<"Impossible",0;
			f(i,0,t0) cout<<'0';
			return 0;
		}
	}
	if(t0*(t0-1)!=a*2) return cout<<"Impossible",0;
	if(t1*(t1-1)!=d*2) return cout<<"Impossible",0;
	if(b+c!=t0*t1) return cout<<"Impossible",0;
	g=t1-((b%t0>0)+(b/t0));
	f(i,0,g) ans+='1';
	f(i,0,t0) ans+='0';
	f(i,0,t1-g) ans+='1';
	if(b%t0>0){
		swap(ans[g+b%t0],ans[g+t0]);
	}
	cout<<ans;
}