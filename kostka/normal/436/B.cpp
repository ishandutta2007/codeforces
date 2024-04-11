//Bartek Kostka

//Don't bother looking.
//You are not prepared. 

#include "bits/stdc++.h"

using namespace std;

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

ST char tab[2*S3][2*S3];
ST int n, m, k;

bool onboard(int a, int b)
{
    //printf("%d %d\n", a, b);
    if(0<=a && a<n && 0<=b && b<m)
        return true;
    return false;
}

int go(int a)
{
    int wyn = 0;
    for(int i=0; i<n; i++)
    {
        //printf("%d %d %c\n", i, a-i, tab[i][a-i]);
        if(onboard(i, a-i) && tab[i][a-i]=='R')
            wyn++;
        if(onboard(i, a+i) && tab[i][a+i]=='L')
            wyn++;
        if(onboard(0, a) && tab[0][a]=='D')
            wyn++;
        if(onboard(2*i, a) && tab[2*i][a]=='U')
            wyn++;
    }
    return wyn;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<n; i++)
        scanf("%s", tab[i]);
    for(int i=0; i<m; i++)
        printf("%d ", go(i));
    return 0;
}