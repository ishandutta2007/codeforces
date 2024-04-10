#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e5+5,M=1e6+5,U=7000+5,L=400;
bool miu[U];bitset<U>w[L];
vector<int>yin[U];
bitset<U>g[N];

void init(int n)
{
	rep(i,1,n)
	for(int j=i;j<=n;j+=i)yin[j].push_back(i);
	rep(i,1,n)miu[i]=1;
	for(int i=2,g;g=i*i,g<=n;++i)
	for(int j=g;j<=n;j+=g)miu[j]=0;	
	rep(i,1,L-1)
	rep(j,1,n/i)w[i][i*j]=miu[j];
//	int mx=0;
//	rep(i,1,n)mx=max(mx,int(yin[i].size()));
//	cerr<<mx<<endl;
}

int main()
{
#ifdef kcz	
	freopen("1.in","r",stdin);
#endif
	init(7000);
	int n,m;
	cin>>n>>m;
	static char ans[M];int top=0;
	while(m--)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if(op==4)
		{
			int v;
			scanf("%d",&v);
			bool a=0;
			if(v>=L)
			{
				for(int i=7000/v;i;--i)
				if(miu[i])a^=g[x][v*i];
			}
			else
			{
				a=(g[x]&w[v]).count()%2;
			}
			ans[++top]='0'+a;
		}
		else
		if(op==1)
		{
			int v;
			scanf("%d",&v);
			g[x].reset();
			for(auto i:yin[v])g[x][i]=1;
		}
		else
		{
			int y,z;
			scanf("%d%d",&y,&z);
			if(op==2)g[x]=g[y]^g[z];
			else g[x]=g[y]&g[z];
		}
	}
	printf("%s\n",ans+1);
}