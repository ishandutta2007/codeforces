#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:32000000")
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <int> vi;
typedef vector <li> vli;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
#endif
        int t=1;
        while (t--)
                solve ();
        return 0;
}
//caution: is int really int? 
#define int li //    !
int n, m, k;
struct sub
{
        li a, b; int c; int id;
        sub () {a=0; b=0; c=0;}
        sub (li A, li B, int C) { a=A; b=B; c=C; }
        void scan () { cin>>a>>b>>c; }
        bool operator < ( const sub B ) const { return c<B.c || (c==B.c && id<B.id); }
};
sub a[60];
li dp[60][60][200];
pair < pi, int > pred[60][60][200];
void solve ()
{
        cin>>n>>m>>k;
        for (int i=1; i<=m; i++)
        {
                a[i].scan(); a[i].id=i;
        }
        sort (a+1, a+m+1);
        dp[0][0][0]=1LL;
        for (int last=1; last<=m; last++)
                for (int add=0; add<=a[last].b-a[last].a; add++)
                {
                        dp[1][last][add]=add+a[last].a;
                        pred[1][last][add]=mp ( mp (0, 0), 0 );
                }
        for ( int pos=1; pos<n; pos++ )
                for (int last=1; last<=m; last++)
                        for ( int add=0; add<=100; add++ )
                                if (dp[pos][last][add])
                                {
                                        int curans=dp[pos][last][add];
                                        int points=add+a[last].a;
                                        for ( int next=last+1; next<=m; next++ )
                                                if ( a[next].c>a[last].c )
                                        {
                                                int nextpt=points+k;
                                                if ( nextpt>=a[next].a && nextpt<=a[next].b )
                                                {
                                                        int now=dp[pos+1][next][nextpt-a[next].a];
                                                        if ( curans+nextpt>now )
                                                        {
                                                                dp[pos+1][next][nextpt-a[next].a]=curans+nextpt;
                                                                pred[pos+1][next][nextpt-a[next].a]=mp ( mp (pos, last), add );
                                                        }
                                                }
                                                nextpt=points*k;
                                                if ( nextpt>=a[next].a && nextpt<=a[next].b )
                                                {
                                                        int now=dp[pos+1][next][nextpt-a[next].a];
                                                        if ( curans+nextpt>now )
                                                        {
                                                                dp[pos+1][next][nextpt-a[next].a]=curans+nextpt;
                                                                pred[pos+1][next][nextpt-a[next].a]=mp ( mp (pos, last), add );
                                                        }
                                                }
                                        }
                                }
                int ans=0;
                pair < pi, int > answer;
                for (int last=1; last<=m; last++)
                        for ( int add=0; add<=100; add++ )
                                if ( dp[n][last][add]>ans )
                                {
                                        ans=dp[n][last][add];
                                        answer=mp (mp ( n, last),  add );
                                }
                //cout<<"ans = "<<ans<<endl;
                if (ans==0)
                {
                        cout<<"NO";
                        return;
                }
                vector < pair <int, int> > anss;
                int pos=n;
                while ( answer.first.first )
                {
                        anss.pb ( mp (a[answer.first.second].id, answer.second+a[answer.first.second].a) );
                        answer=pred[answer.first.first][answer.first.second][answer.second]; 
                }
                cout<<"YES\n";
                for (int i=(int)anss.size()-1; i>=0; i--)
                {
                        cout<<anss[i].first<<' '<<anss[i].second<<endl;
                }
}