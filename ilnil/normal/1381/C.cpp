#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e5+5,mo=1e9+7;
int t,n,x,y,mx,nd;
int a[N],ans[N];
vector<int>col[N],cnt[N],p;
bool same[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	for(;t--;){
		cin>>n>>x>>y;
		fo(i,0,n+1)col[i].clear(),cnt[i].clear(),same[i]=0;
		fo(i,1,n)cin>>a[i],col[a[i]].pb(i);
		fo(i,1,n+1)cnt[col[i].size()].pb(i);
		mx=n+1;
		for(int i=x;i;--i){
			while(mx>0&&cnt[mx].empty())--mx;
			int c=cnt[mx].back();
			ans[col[c].back()]=c;
			same[col[c].back()]=1;
			col[c].pop_back();
			cnt[mx].pop_back();
			cnt[mx-1].pb(c);
		}
		while(mx>0&&cnt[mx].empty())--mx;
		if(mx*2>n*2-x-y){
			printf("NO\n");
			continue;
		}
		p.clear();
		fo(i,1,n+1)p.insert(p.end(),col[i].begin(),col[i].end());
		nd=n-y;
		fo(i,0,n-x-1){
			ans[p[i]]=a[p[(i+(n-x)/2)%(n-x)]];
			if(ans[p[i]]==a[p[i]])
				ans[p[i]]=cnt[0][0],--nd;
		}
		for(int i=1;nd;++i)
			if(!same[i]&&ans[i]!=cnt[0][0])
				ans[i]=cnt[0][0],--nd;
		printf("YES\n");
		fo(i,1,n)printf("%d ",ans[i]);
		printf("\n");
	}
}