#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int x; scanf("%d",&x); return x;
}
const int N=300010;
std::vector<int> ans[N],p1,p2;
int solve()
{
	static int a[N],Ans=0,n=read(),h=n,H[N];
	p1.clear(); p2.clear();
	fr(i,1,n) ans[i].clear();
	fr(i,1,n) a[i]=read();
	fd(i,n,1)
	{
//		printf("%d %d\n",i,a[i]);
		if(a[i]==1){ p1.push_back(i); ans[i].push_back(H[i]=h--); }
		if(a[i]==2){ if(p1.empty()) return 0; int p=p1[p1.size()-1]; p1.pop_back(); H[i]=H[p]; ans[i].push_back(H[i]); p2.push_back(i); }
		if(a[i]==3)
		{
			if(p1.empty()&&p2.empty()) return 0;
			int p; H[i]=h--;
			if(p2.empty()){ p=p1[p1.size()-1]; p1.pop_back(); }
			else { p=p2[p2.size()-1]; p2.pop_back(); }
			ans[p].push_back(H[i]); ans[i].push_back(H[i]);
			p2.push_back(i);
		}
//		printf("%d\n",i);
	}
	fr(i,1,n) Ans+=ans[i].size();
	printf("%d\n",Ans);
	fr(i,1,n) fr(j,0,ans[i].size()-1) printf("%d %d\n",ans[i][j],i);
	return 1;
}
int main()
{
	{
		if(!solve()) printf("-1\n");
	}
	return 0;
}