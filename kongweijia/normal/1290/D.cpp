#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int maxn=300000;
//head
int n,k; 


int CNT;
int ask(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	char s[5]; scanf("%s",s);
	CNT++;
	return s[0]=='Y';
}

void reset()
{	
	printf("R\n");
	fflush(stdout);
}

void answer(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}

VI dfs(int l,int r)
{	
	if(r-l+1==k)
	{
		reset();
		VI A;
		rep(i,l,r) if(ask(i)==0) A.pb(i);
		return A;
	}
	int mid=(l+r)>>1;
	VI A,L=dfs(l,mid),R=dfs(mid+1,r);
	VI tmp,BR;
	for(auto x: L) tmp.pb(x);
	for(auto x: R) tmp.pb(x);
	BR=R;

	//printf("## %d %d\n",l,r);
	set<int> gg;
	while(L.size())
	{
		VI tt;
		int c=max(k/2,1);
		while(L.size() && c--)
		{
			tt.pb(L.back()); L.pop_back();
		}
		R=BR;
		
		while(R.size())
		{
			reset();
			int c=max(k/2,1);
			while(R.size() && c--)
			{
				int x=R.back(); R.pop_back();
				if(ask(x)==1) gg.insert(x);
			}
			for(auto x: tt)
			{
				if(ask(x)==1) gg.insert(x);
			}
			c=max(k/2,1);
			while(R.size() && c--)
			{
				int x=R.back(); R.pop_back();
				if(ask(x)==1) gg.insert(x);
			}
		}
	}
	//printf("?? %d %d\n",l,r);
	//for(auto x: gg) printf("! %d\n",x);
	for(auto x: tmp) if(gg.find(x)==gg.end()) A.pb(x);
	return A;
}

int main()
{
	scanf("%d%d",&n,&k);
	VI A=dfs(1,n);
	answer(A.size());
	//printf("%d\n",CNT);
	return 0;
}