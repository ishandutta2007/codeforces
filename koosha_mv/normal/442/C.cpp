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

const int N=1e6+99;

int n,x,t=1,mx,cnt,mark[N];
ll ans;
vector<int> a[N];

int main(){
	cin>>n;
	f(i,1,n+1){ cin>>x; a[x].pb(i); maxm(mx,x);}
	mark[a[mx][a[mx].size()-1]]=1;
	a[mx].pop_back();
	f_(i,mx,1){
		cnt=0;
		f(k,0,a[i].size()){
			cnt++;
			if(t>1) cnt++;
			cnt-=mark[a[i][k]-1]+mark[a[i][k]+1];
			mark[a[i][k]]=1;
			t++;
		}
		ans+=cnt*i;
	}
	cout<<ans;
}