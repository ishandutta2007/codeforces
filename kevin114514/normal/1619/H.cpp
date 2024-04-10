#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
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
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
const int B=300;
int prv[100100],nxt[100100],nxtb[100100];
int Nxtb(int x)
{
	for(int i=0;i<B;i++)
		x=nxt[x];
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>nxt[i];
		prv[nxt[i]]=i;
	}
	for(int i=1;i<=n;i++)
		nxtb[i]=Nxtb(i);
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int x,y;
			cin>>x>>y;
			prv[nxt[x]]=y;
			prv[nxt[y]]=x;
			swap(nxt[x],nxt[y]);
			int px=Nxtb(x),py=Nxtb(y);
			for(int i=0;i<B;i++)
			{
				nxtb[x]=px;
				nxtb[y]=py;
				x=prv[x];
				y=prv[y];
				px=prv[px];
				py=prv[py];
			}
		}
		else
		{
			int x,l;
			cin>>x>>l;
			for(int i=0;i<l/B;i++)
				x=nxtb[x];
			for(int i=0;i<l%B;i++)
				x=nxt[x];
			cout<<x<<endl;
		}
	}
	return 0;
}