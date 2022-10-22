#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1009;
ll n,m,k,kn[1009][2],r,x,y,ans[N],p,l,mid,e=1e12;
vector<pair<int,int> > c[N];
binary_search(int x,int y){
	l=-1,r=min(c[x].size(),c[y].size());
	while(l+1<r){
		mid=(l+r)/2;
		if(c[x][mid].S==c[y][mid].S)
			l=mid;
		else
			r=mid;
	}
	return r;
}
int main(){
	cin>>n>>m>>k;
	f(i,1,n+1)
		Get(kn[i][0],kn[i][1]);
	f(i,1,m+1){
		get(r);
		Get(x,y);
		f(j,1,n+1){
			if((kn[j][0]-x)*(kn[j][0]-x)+(kn[j][1]-y)*(kn[j][1]-y)<=r*r){
				ans[j]++;
				c[j].pb(make_pair(e-r,i));
			}
		}
	}
	f(i,1,n+1)
		sort(c[i].begin(),c[i].end());
	f(i,0,k){
		Get(x,y);
		p=binary_search(x,y);
		cout<<ans[x]+ans[y]-(p*2)<<endl;
	}
}