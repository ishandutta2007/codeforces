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
const int N=1e5+99;
int n,t,m,mark[N],c;
vector<pair<int,int> > ans;
int main(){
	cin>>n>>m;
	if(m<n-1) return cout<<"Impossible",0;
	f(i,1,n+1){
		f(j,2,i){
			if(ans.size()>N){c=1;break;}
			if(__gcd(i,j)==1)
				ans.pb(mp(i,j));
		}
		if(c) break;
	}
	if(ans.size()<m-(n-1)) return cout<<"Impossible",0;
	cout<<"Possible"<<endl;
	f(i,0,n-1) cout<<1<<" "<<i+2<<endl;
	f(i,0,m-(n-1))	cout<<ans[i].F<<" "<<ans[i].S<<endl;
}