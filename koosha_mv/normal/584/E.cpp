#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=2005;
int n,p[N],s[N],a[N],x,cnt,mark[N],jvb;
vector<pair<int,int> > ans;
vector<vector<int> > dor;
vector <int> v;
void dfs(int x,int c){
	dor[c].pb(x);
	mark[x]=1;
	if(mark[p[x]]==0)
		dfs(p[x],c);
}
void solve(int x){
	int an=dor[x].size()-1,mx=dor[x][0],an2;
	f(i,1,dor[x].size()){
		if(dor[x][i]>mx)
			mx=dor[x][i],an=i-1;
	}
	for(int i=(an+1)%dor[x].size();i<N;i=(i+1)%dor[x].size()){
		if(dor[x][i]<=dor[x][an]){
			an2=i-1;
			break;
		}
	}
	if(an2==-1) an2=dor[x].size()-1;
	ans.pb(make_pair(dor[x][an],dor[x][an2]));
	vector<int> v1,v2;
	if(an>an2)
		swap(an,an2);
	swap(dor[x][an],dor[x][an2]);
	f(i,an,an2)
		v1.pb(dor[x][i]);
	for(int i=an2;i!=an;i=(i+1)%dor[x].size())
		v2.pb(dor[x][i]);
	dor.pb(v1);
	dor.pb(v2);
}
int main(){
	cin>>n;
	f(i,1,n+1)
		cin>>p[i];
	f(i,1,n+1){
		cin>>x;
		a[x]=i;
	}
	
	f(i,1,n+1){
		p[i]=a[p[i]];
		jvb+=abs(i-p[i]);
	}
	f(i,1,n+1){
		if(mark[i]==0){
			dor.pb(v);
			dfs(i,cnt);
			cnt++;
		}
	}
	f(i,0,dor.size()){
		if(dor[i].size()>1)
			solve(i);
	}
	cout<<jvb/2<<endl<<ans.size()<<endl;
	f(i,0,ans.size())
		cout<<ans[i].F<<" "<<ans[i].S<<endl;
}