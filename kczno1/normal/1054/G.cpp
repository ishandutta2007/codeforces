#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=2000+5;
int n,m;
bitset<N>S[N];bool exist[N];
int fa[N];
char s[N][N];int cnt[N];
bool con[N][N];int con_cnt[N];
void del(int i)
{
	rep(x,1,n)
	if(S[x][i]&&exist[x])
	{
		S[x][i]=0;
		rep(y,1,n)
		if(exist[y]&&y!=x&&!con[x][y])
		{
			con_cnt[x]+=(con[x][y]=(S[y]&S[x])==S[x]);
		}
	}
}
bool work()
{
	cin>>n>>m;
	rep(i,1,n){S[i].reset();exist[i]=1;}
	rep(i,1,m)
	{
		scanf("%s",s[i]+1);
		cnt[i]=0;
		rep(x,1,n)
		if(s[i][x]=='1')
			++cnt[i];
		if(cnt[i]>1)		
		rep(x,1,n)
		if(s[i][x]=='1')S[x][i]=1;
	}
	rep(i,1,n)
	{
		con_cnt[i]=0;
		rep(j,1,n)
		if(j!=i)
			con_cnt[i]+=(con[i][j]=(S[j]&S[i])==S[i]);
	}
	rep(tmp,1,n-1)
	{
		int x=0;
		rep(i,1,n)
		if(exist[i]&&con_cnt[i]){x=i;break;}
		if(!x)return 0;
		exist[x]=0;
		rep(y,1,n)
		if(con[x][y])
		{
			fa[x]=y;
			break;
		}
		rep(y,1,n)
		if(con[y][x])
		{
			con[y][x]=0;
			--con_cnt[y];
		}
		rep(i,1,m)
		if(S[x][i])
		{
			if(--cnt[i]==1)del(i);
		}
	}
	return 1;
}

int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	if(!work())puts("NO");
	else
	{
		puts("YES");
		rep(x,1,n)
		if(!exist[x])printf("%d %d\n",x,fa[x]);
	}
}