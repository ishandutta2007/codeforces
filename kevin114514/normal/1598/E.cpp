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
void die(string S){puts(S.c_str());exit(0);}
set<int> Blocked[2020];
ll ans;
int dot;
bool grid[1010][1010];
void update(int x,int y,int a,int b)
{
	if(grid[x][y])
	{
//		grid[x][y]=0;
//		dot--;
		Blocked[a].erase(b);
		auto it1=Blocked[a].lower_bound(b),it2=it1;
		it2--;
		int prv=b-*it2;
		int nxt=*it1-b;
		ans+=prv*nxt;
	}
	else
	{
//		grid[x][y]=1;
//		dot++;
		auto it1=Blocked[a].lower_bound(b),it2=it1;
		it2--;
		int prv=b-*it2;
		int nxt=*it1-b;
		ans-=prv*nxt;
		Blocked[a].insert(b);
	}
}
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
	{
		Blocked[i].insert(-1);
		int nn=n-i;
		Blocked[i].insert(min(2*nn-1,(min(nn-1,m)+min(nn-1,m-1)+1)));
	}
	for(int i=0;i<m;i++)
	{
		Blocked[i+n].insert(-1);
		int nm=m-i;
		Blocked[i+n].insert(min(2*nm-1,(min(nm-1,n)+min(nm-1,n-1)+1)));
	}
	for(int i=0;i<n+m;i++)
	{
		auto it1=Blocked[i].begin(),it2=it1;
		it2++;
//		cout<<i<<" "<<*it2-*it1-1<<endl;
		ans+=1ll*(*it2-*it1-1)*(*it2-*it1)/2;
	}
	dot=n*m;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		int n1,n2,n3,n4;
		if(x<y)
		{
			n1=n+y-x-1;
			n2=x+y-n1+n;
			n3=n+y-x;
			n4=x+y-n3+n;
			update(x,y,n1,n2);
			update(x,y,n3,n4);
		}
		else if(x>y)
		{
			n1=x-y-1;
			n2=x+y-n1;
			n3=x-y;
			n4=x+y-n3;
			update(x,y,n1,n2);
			update(x,y,n3,n4);
		}
		else
		{
			n1=0,n3=n;
			n2=x+y-n1;
			n4=x+y-n3+n;
			update(x,y,n1,n2);
			update(x,y,n3,n4);
		}
		dot+=grid[x][y];
		grid[x][y]^=1;
		dot-=grid[x][y];
//		cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<endl;
		cout<<ans-dot<<endl;
	}
	return 0;
}