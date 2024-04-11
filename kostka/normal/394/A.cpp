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

int main()
{
    string x;
    cin >> x;
    int a=0;
    while(x[a] != '+')
        a++;
    int b=0;
    while(x[a+b+1] != '=')
        b++;
    int c=0;
    while(x[a+b+c+2])
        c++;
    if(a+b==c)
    {
        cout << x;
        return 0;
    }
    int n = x.size();
    if(a+b+1==c-1)
    {
        cout << "|";
        for(int i=0; i<n-1; i++)
            cout << x[i];
        return 0;
    }
    if(a+b-1==c+1)
    {
        if(a>1)
        {
            for(int i=1; i<n; i++)
                cout << x[i];
            cout << "|";
            return 0;
        }
        else if(b>1)
        {
            for(int i=0; i<a; i++)
                cout << "|";
            cout << "+";
            for(int i=0; i<b-1; i++)
                cout << "|";
            cout << "=|";
            for(int i=0; i<c; i++)
                cout << "|";
            return 0;            
        }
    }
    cout << "Impossible";
    return 0;
}