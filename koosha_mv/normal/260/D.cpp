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
#define mp make_pair
const int N=1e5+99;
int n,x,y,p,cnt,ans[N][3],g;
vector<pair<int,int> > v1,v2;
int main(){
	cin>>n;
	f(i,1,n+1){
		cin>>x>>y;
		if(x) v2.pb(mp(i,y));
		else v1.pb(mp(i,y));
	}
	f(i,0,v1.size()){
		p--;g=1;
		while(g || v1[i].S || (i==v1.size()-1 && p<v2.size()-1)){
			p++,g=0;
			ans[cnt][0]=v1[i].F;
			ans[cnt][1]=v2[p].F;
			ans[cnt++][2]=min(v1[i].S,v2[p].S);
			int s=v1[i].S;
			v1[i].S-=min(v1[i].S,v2[p].S);
			v2[p].S-=min(s,v2[p].S);
		}
	}
	f(i,0,cnt)
		cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
}