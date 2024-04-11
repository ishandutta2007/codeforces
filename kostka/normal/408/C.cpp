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
#include<utility>

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

int a, b, a2, b2, c2;

VII podziel(int x2)
{
    VII X;
    for(int i=1; i*i<x2; i++)
    {
        int tmp = sqrt(x2 - i*i);
        if(tmp*tmp + i*i == x2)
            X.PB(MP(i,tmp));
    }
    return X;
}

int odl(int a, int b, int c, int d)
{
    return (c-a)*(c-a)+(d-b)*(d-b);
}

bool sprawdz(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if(x1==x2 || x2==x3 || x1==x3 || y1==y2 || y1==y3 || y2==y3)
        return false;
    int a1 = odl(x1,y1,x2,y2);
    int b1 = odl(x2,y2,x3,y3);
    int c1 = odl(x3,y3,x1,y1);
    bool czy = 0;
    if(a1==a2 && b1==b2 && c1==c2)
        czy = 1;
    if(a1==b2 && b1==a2 && c1==c2)
        czy = 1;
    if(a1==c2 && b1==b2 && c1==a2)
        czy = 1;
    if(a1==a2 && b1==c2 && c1==b2)
        czy = 1;
    if(a1==b2 && b1==c2 && c1==a2)
        czy = 1;
    if(a1==c2 && b1==a2 && c1==b2)
        czy = 1;
    if(czy)
    {
        puts("YES");
        WRITE2(x1, y1);
        WRITE2(x2, y2);
        WRITE2(x3, y3);
    }
    return czy;
}

int main()
{
    scanf("%d%d", &a, &b);
    a2 = a*a;
    b2 = b*b;
    c2 = a2+b2;
    VII pa = podziel(a2);
    VII pb = podziel(b2);
    VII pc = podziel(c2);
    FOREACH(ta, pa)
        FOREACH(tb, pb)
        {
            if(sprawdz((*ta).FT, -(*ta).SD, (*tb).SD, (*tb).FT, 0, 0))
                return 0;
            if(sprawdz((*ta).SD, -(*ta).FT, (*tb).FT, (*tb).SD, 0, 0))
                return 0;
            if(sprawdz((*ta).FT, -(*ta).SD, (*tb).FT, (*tb).SD, 0, 0))
                return 0;
            if(sprawdz((*ta).SD, -(*ta).FT, (*tb).SD, (*tb).FT, 0, 0))
                return 0;
        }
    puts("NO");
    return 0;
}