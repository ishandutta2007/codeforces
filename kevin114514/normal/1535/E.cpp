#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
int fa[300300][22];
int depth[300300];
//int root[300300];
int a[300300],c[300300];
bool deleted[300300];
int ancestor(int x,int num)
{
	int y=x;
	for(int i=19;i>=0;i--)
		if(num>=(1<<i)&&!deleted[fa[y][i]])
		{
			y=fa[y][i];
			num-=(1<<i);
		}
	return y;
}
int next_vertex(int from,int to)
{
	int delta=depth[to]-depth[from];
	return ancestor(to,delta-1);
}
int main()
{
	int q;
	cin>>q;
	cin>>a[0]>>c[0];
	for(int i=0;i<20;i++)
		fa[0][i]=-1;
	for(int i=1;i<=q;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int P,A,C;
			cin>>P>>A>>C;
			depth[i]=depth[P]+1;
			fa[i][0]=P;
			for(int j=1;j<20;j++)
				if(fa[i][j-1]==-1)
					fa[i][j]=-1;
				else	fa[i][j]=fa[fa[i][j-1]][j-1];
			a[i]=A;
			c[i]=C;
		}
		else
		{
			int v,w;
			cin>>v>>w;
			int x=ancestor(v,depth[v]);
			ll amo=0,cost=0;
//			int lest=x;
			while(x!=v)
			{
//				root[x]=lest;
				int mn=min(w,a[x]);
				w-=mn;
				a[x]-=mn;
				amo+=mn;
				cost+=1ll*mn*c[x];
				if(!a[x])
//					lest=next_vertex(x,v);
					deleted[x]=true;
				if(!w)
//				{
//					while(x!=v)
//					{
//						root[x]=lest;
//						x=next_vertex(x,v);
//					}
					break;
//				}
				x=next_vertex(x,v);
			}
//			root[v]=lest;
			int mn=min(w,a[v]);
			w-=mn;
			a[v]-=mn;
			amo+=mn;
			cost+=1ll*mn*c[v];
			cout<<amo<<" "<<cost<<endl;
		}
	}
	return 0;
}