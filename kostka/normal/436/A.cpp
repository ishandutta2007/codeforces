//Bartek Kostka

//Don't bother looking.
//You are not prepared. 

#include "bits/stdc++.h"

using namespace std;

#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define MP make_pair
#define PB push_back
#define FT first
#define SD second
#define SZ(x) ((int)((x).size()))
#define TAKE(a) int (a); scanf("%d",&(a));
#define TAKE2(a,b) int (a),(b); scanf("%d %d",&(a),&(b));
#define TAKE3(a,b,c) int (a),(b),(c); scanf("%d %d %d",&(a),&(b),&(c));
#define DEBUG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define DEBUGV(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS TAKE(ttt)while(ttt--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define MAXI(a,b) (a)=max((a),(b));
#define MINI(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);
#define ST static
#define IN inline
#define PII pair<int,int>
#define LL long long
#define VI vector<int>
#define VII vector < PII >
#define LD long double
ST IN void WRITE(int a) { printf("%d\n",a); }
ST IN void WRITE2(int a, int b) { printf("%d %d\n", a, b); }
const int S9 = 1000000007, S6 = 1000007, S5 = 100007, S4 = 10007, S3 = 1007 , S2 = 107;
const double E2 = 0.01, E4 = 0.0001, E6 = 0.000001, E8 = 0.00000001;

VII V[2];
bool eaten[2][2*S4];

int wybierzmaks(int a, int x)
{
	int maks = 0, maksi = -1;
	for(int i=0; i<SZ(V[a]); i++)
		if(eaten[a][i]==0)
		{
			if(-V[a][i].first >= maks && V[a][i].second <= x)
			{
				maks = -V[a][i].first;
				maksi = i;
			}
		}
	if(maksi==-1)
		return -1;
	else
	{
		eaten[a][maksi] = 1;
		return maks;
	}
}

int start(int a, int x)
{
	for(int i=0; i<20007; i++)
	{
		eaten[0][i] = 0;
		eaten[1][i] = 0;
	}
	int b = 1-a, wyn = 0;
	while(true)
	{
		int p = wybierzmaks(a,x);
		if(p != -1)
		{
			x += p;
			wyn++;	
		}
		else
			break;
		int q = wybierzmaks(b,x);
		if(q != -1)
		{
			x += q;
			wyn++;	
		}
		else
			break;
	}
	return wyn;
}

int main()
{
	TAKE2(n,x);
	for(int i=0; i<n; i++)
	{
		TAKE3(a,b,c);
		V[a].push_back(make_pair(-c,b));
	}
	sort(ALL(V[0]));
	sort(ALL(V[1]));
	printf("%d\n", max(start(0,x), start(1,x)));
	return 0;
}