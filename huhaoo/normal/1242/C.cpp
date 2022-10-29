/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-11-06 23:37:59
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define i64 long long
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#include<map>
#include<vector>
#include<assert.h>
const int K=18,N=5010;
#define pii pair<i64,i64>
map<i64,pii> m;
i64 k,n[N],s[N],S,a[K][N],vis[K][N];
pii nex[K][N];
vector<pii> ch[(1<<16)|10];
pii ans[K];
vector<pii> A;
int pre[(1<<16)|10],f[(1<<16)|10],g[(1<<16)|10],cnt;
int main()
{
	k=read();
	fr(i,1,k)
	{
		n[i]=read();
		fr(j,1,n[i])
		{
			s[i]+=(a[i][j]=read());
			m[a[i][j]]=pii(i,j);
		}
		S+=s[i];
	}
	if(S%k!=0)
	{
		printf("No\n");
		return 0;
	}
	S/=k;
	fr(i,1,k)
		fr(j,1,n[i])
			if(!vis[i][j])
			{
				i64 I=i,J=j,flag=0;
				cnt++;
				while(!vis[I][J])
				{
					vis[I][J]=cnt;
					if(!m.count(S-(s[I]-a[I][J])))
					{
						flag=1;
						break;
					}
					nex[I][J]=m[S-(s[I]-a[I][J])];
					i64 _I=I,_J=J;
					I=nex[_I][_J].first;
					J=nex[_I][_J].second;
					assert(I<=k&&J<=n[I]&&I>=1&&J>=1);
				}
				if(flag||vis[I][J]!=cnt)
					continue;
				i64 eI=I,eJ=J;
				A.clear();
				do
				{
					A.push_back(pii(I,J));
					i64 _I=I,_J=J;
					I=nex[_I][_J].first;
					J=nex[_I][_J].second;
				}
				while(I!=eI||J!=eJ);
				i64 op=0,F=0;
				for(auto i:A)
					if(op&(1<<(i.first-1)))
						F=1;
					else
						op|=1<<(i.first-1);
				if(!F&&!g[op])
				{
					g[op]=1;
					fr(i,0,A.size()-1)
						ch[op].push_back(A[i]);
				}
			}
	f[0]=1;
	fr(i,1,(1<<k)-1)
		for(int j=i;j;j=(j-1)&i)
			if(g[j]&&f[i-j])
			{
				f[i]=1;
				pre[i]=j;
				break;
			}
	int th=(1<<k)-1;
	if(f[th])
	{
		printf("Yes\n");
		while(th)
		{
			int k=pre[th];
			fr(i,0,ch[k].size()-2)
				ans[ch[k][i+1].first]=pii(a[ch[k][i+1].first][ch[k][i+1].second],ch[k][i].first);
			int ed=ch[k].size()-1;
			ans[ch[k][0].first]=pii(a[ch[k][0].first][ch[k][0].second],ch[k][ed].first);
			th^=k;
		}
		fr(i,1,k)
			printf("%I64d %I64d\n",ans[i].first,ans[i].second);
	}
	else
		printf("No\n");
	return 0;
}