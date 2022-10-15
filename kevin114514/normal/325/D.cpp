#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PLL pair<ll, ll>
#define STR string
#define MP make_pair
#define Fst first
#define Snd second
using namespace std;
int n,m,q;
bool a[3010][3010];
int res=0;
PII par[3010][6010];
int siz[3010][6010];
vector< pair<PII,PII> > v;
PII pare(int x,int y)
{
	return par[x][y]==MP(x,y) ? MP(x,y) : pare(par[x][y].Fst,par[x][y].Snd);
}
inline void join(int x,int y,int xi,int yi)
{
	//cout <<x+1<<" "<<y+1<<" "<<xi+1<<" "<<yi+1<<" ##\n";
	PII p=pare(x,y),pi=pare(xi,yi);
	if(p==pi)
		return ;
	x=p.Fst,y=p.Snd,xi=pi.Fst,yi=pi.Snd;
	if (siz[x][y]<siz[xi][yi]) swap(x,xi),swap(y,yi);
	v.push_back(MP(MP(x,y),MP(xi,yi)));
	par[xi][yi]=MP(x,y),siz[x][y]+=siz[xi][yi];
}
inline void apart(int x,int y,int xi,int yi)
{
	par[xi][yi]=MP(xi,yi),siz[x][y]-=siz[xi][yi];
}
inline void add(int x,int y)
{
	a[x][y]=1,v.resize(0);
	for (int i=-1;i<=1;i++)
	{
		for (int j=-1;j<=1;j++)
		{
			if (!i && !j) continue;
			int xi=x+i,yi=y+j;
			if (xi<0 || xi>=n || !a[xi][(yi==-1 ? m-1 : (yi==m ? 0 : yi))]) continue;
			if (yi<0) join(x,y+m,xi,yi+m),join(x,y,xi,yi+m+m);
			else if (yi==m) join(x,y,xi,yi),join(x,y+m,xi,yi-m);
			else join(x,y,xi,yi),join(x,y+m,xi,yi+m);
		}
	}
	if (pare(x,y)!=pare(x,y+m))
	{
		//cout <<x+1<<" "<<y+1<<" ##\n";
		res++;
		return;
	}
	a[x][y]=0;
	for (int i=(int)v.size()-1;i>=0;i--)
		apart(v[i].Fst.Fst,v[i].Fst.Snd,v[i].Snd.Fst,v[i].Snd.Snd);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=0;i<n;i++)
		for (int j=0;j<m*2;j++) par[i][j]=MP(i,j),siz[i][j]=1;
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y),x--,y--;
		add(x,y);
	}
	printf("%d",res);
	return 0;
}