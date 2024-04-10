#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=100005,SIGMA=26;

struct interval
{
	int l,r,p,id;
};

int sum[SIGMA][MAXN];
vector <int> pos[SIGMA],sg_xs[SIGMA];
vector <vector<int>> sg_fw[SIGMA],sg_bw[SIGMA];
vector <interval> a;
char s[MAXN];

bool cmp(const interval &a,const interval &b)
{
	return a.r!=b.r?a.r<b.r:a.l>b.l;
}

int cal(int l,int r)
{
	if (l>r)
		return 0;
	bool vis[SIGMA];
	memset(vis,0,sizeof(vis));
	for (int i=0;i<SIGMA;i++)
		if (sum[i][r]!=sum[i][l-1])
		{
			int il=sum[i][l-1],ir=sum[i][r]-1;
			int ret=sg_xs[i][ir]^sg_xs[i][il];
			if (sg_fw[i][il][pos[i][il]-l]==-1)
				sg_fw[i][il][pos[i][il]-l]=cal(l,pos[i][il]-1);
			ret^=sg_fw[i][il][pos[i][il]-l];
			if (sg_bw[i][ir][r-pos[i][ir]]==-1)
				sg_bw[i][ir][r-pos[i][ir]]=cal(pos[i][ir]+1,r);
			ret^=sg_bw[i][ir][r-pos[i][ir]];
			if (ret<SIGMA)
				vis[ret]=true;
		}
	for (int i=0;i<SIGMA;i++)
		if (!vis[i])
			return i;
	return SIGMA;
}

int main()
{
	//freopen("read.txt","r",stdin);
	scanf("%s",s+1);
	int l=strlen(s+1);
	for (int i=1;i<=l;i++)
		s[i]-='a';
	for (int i=0;i<SIGMA;i++)
	{
		for (int j=1;j<=l;j++)
		{
			sum[i][j]=sum[i][j-1];
			if (s[j]==i)
			{
				sum[i][j]++;
				pos[i].pb(j);
			}
		}
		sg_xs[i].resize(pos[i].size());
		sg_fw[i].resize(pos[i].size());
		int lst=0;
		for (int j=0;j<pos[i].size();j++)
		{
			sg_fw[i][j].resize(pos[i][j]-lst);
			for (int &x:sg_fw[i][j])
				x=-1;
			lst=pos[i][j];
		}
		sg_bw[i].resize(pos[i].size());
		lst=l+1;
		for (int j=(int)pos[i].size()-1;j>=0;j--)
		{
			sg_bw[i][j].resize(lst-pos[i][j]);
			for (int &x:sg_bw[i][j])
				x=-1;
			lst=pos[i][j];
		}
		for (int j=1;j<pos[i].size();j++)
			a.pb({pos[i][j-1]+1,pos[i][j]-1,i,j});
	}
	sort(a.begin(),a.end(),cmp);
	for (const auto &seg:a)
	{
		int g=cal(seg.l,seg.r);
		sg_xs[seg.p][seg.id]=sg_xs[seg.p][seg.id-1]^g;
	}
	int m;
	scanf("%d",&m);
	while (m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=cal(l,r);
		puts(ans?"Alice":"Bob");
	}
	return 0;
}