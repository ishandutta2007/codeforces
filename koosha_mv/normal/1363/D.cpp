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

const int N=1020;

int n,t,k,mx,mid,l,r,y,an,u,ans,mark[N],e[N];
vector<int> v[N];
string s;

bool check(int x){
	cout<<"? "<<x;
	f(i,1,x+1) cout<<" "<<i;
	cout<<endl;
	cin>>y;
	if(y<mx) return 1;
	else return 0;
}
void read(){
	f(i,0,k){
		v[i].clear();
		cin>>y;
		f(j,0,y){
			cin>>u;
			mark[u]=i;
			v[i].pb(u);
		}
	}
}
void solve(){
	fill(e,e+n+10,0);
	f(i,0,v[an].size())
		e[v[an][i]]=1;
	cout<<"? "<<n-v[an].size();
	f(i,1,n+1) if(e[i]==0) cout<<" "<<i;
	cout<<endl;
	cin>>ans;
}

int main(){
	cin>>t;
	while(t--){
		an=-1;
		cin>>n>>k;
		fill(mark,mark+n+2,-1);
		read();
		cout<<"? "<<n;
		f(i,1,n+1) cout<<" "<<i;
		cout<<endl;
		cin>>mx;
		l=0,r=n;
		while(l+1<r){
			mid=(l+r)/2;
			if(check(mid)) l=mid;
			else r=mid;
		}
		an=mark[r];
		if(an!=-1) solve();
		cout<<"!";
		f(i,0,k)
			cout<<" "<<(i==an ? ans : mx);
		cout<<endl;
		cin>>s;
	}
}