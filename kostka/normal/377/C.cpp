//Bartek Kostka

//Don't bother looking.
//You are not prepared. 

#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>

using namespace std;

#define d(X) //printf("####\n"); X printf("####\n");
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
#define VII vector < pii >
#define LD long double
ST IN void WRITE(int a) { printf("%d\n",a); }
ST IN void WRITE2(int a, int b) { printf("%d %d\n", a, b); }
const int S9 = 1000000007, S6 = 1000007, S5 = 100007, S4 = 10007, S3 = 1007 , S2 = 107;
const double E2 = 0.01, E4 = 0.0001, E6 = 0.000001, E8 = 0.00000001;

ST int tab[S2], akc[27], dp[1<<20], m;

IN ST int foo(int mas, int tura)
{
	if(tura == m)
		return 0;
	if(dp[mas] != S9)
		return dp[mas];
	if(abs(akc[tura])==1)
	{
		int res = -S9;
		FOR(i,m)
		{
			if((1<<i) & mas)
			{
				if(akc[tura]>0)
					MAXI(res, tab[i] + foo(mas ^ (1<<i), tura+1))
				else
					MAXI(res, foo(mas ^ (1<<i), tura+1))
			}
		}
		d(
			pisz2(mas, res);
		)
		return dp[mas]	= res;
	}
	else
	{
		int res = S9;
		FOR(i,m)
			if((1<<i) & mas)
			{
				if(akc[tura]>0)
					MINI(res, -tab[i] + foo(mas ^ (1<<i), tura+1))
				else
					MINI(res, foo(mas ^ (1<<i), tura+1))
			}
		d(
			pisz2(mas, res);
		)
		return dp[mas]	= res;
	}
}

int main()
{
	TAKE(n);
	FOR(i,n)
		scanf("%d", &tab[i]);	
	sort(tab, tab + n);
	reverse(tab, tab + n);
	scanf("%d", &m);
	FOR(i,m)
	{
		char p;
		scanf(" %c %d", &p, &akc[i]);
		if(p=='b')
			akc[i] *= -1;
	}
	FOR(mas,1<<m)
		dp[mas] = S9;
	foo((1<<m) - 1,0);
	d(
		FOR(mas,1<<m)
			WRITE(dp[mas]);
	)
	WRITE(dp[(1<<m)-1]);
	return 0;
}