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

vector <string> A;

int main()
{
    int l0 = 0, l1 = 0, lz = 0, i = 0;
    string x;
    cin >> x;
    for(i=0; x[i]; i++)
    {
        if(x[i]=='1')
            l1++;
        if(x[i]=='0')
            l0++;
        if(x[i]=='?')
            lz++;
    }
    int n = l0 + l1 + lz;
    if(n%2)
    {
        if(l0 + lz > l1)
            A.PB("00");
        if(l1 + lz > l0 + 1)
            A.PB("11");
    }
    else
    {
        if(l0 + lz > l1 + 1)
            A.PB("00");
        if(l1 + lz > l0 + 1)
            A.PB("11");        
    }
    int k = n / 2;
    if (l0 + lz >= k && l0 <= k ) 
    {
      int n0 = k - l0;
      int n1 = lz - n0;
      if ((x[n-1] == '?' && n0 > 0) || x[n-1] == '0' )
        A.PB("10");
      if ((x[n-1] == '?' && n1 > 0) || x[n-1] == '1' )
        A.PB("01");
    }
    sort(ALL(A));
    FOREACH(it, A)
        cout << *it << "\n";
    return 0;
}