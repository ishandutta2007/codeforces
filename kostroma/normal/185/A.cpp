#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
#include <memory.h>

using namespace std;

/*
CAUTION: IS INT REALLY INT, BUT NOT LONG LONG?
REAL SOLTION AFTER MAIN FUNCTION
*/

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve();
int main() 
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

#define int li

int n;
int mod=1000000007;

int step[100][2][2];

void solve()
{  
    step[0][0][0]=step[0][1][1]=3;
    step[0][0][1]=step[0][1][0]=1;
    for (int i=1; i<100; i++)
    {
        for (int w=0; w<2; w++)
            for (int j=0; j<2; j++)
                for (int k=0; k<2; k++)
                    step[i][w][j]+=step[i-1][w][k]*step[i-1][k][j], step[i][w][j]%=mod;
    }
    
    cin>>n;
    
    vector < vector <int> > ans;
    ans.resize(2);
    ans[0].resize(2);
    ans[1].resize(2);
    ans[0][0]=ans[1][1]=1;
    int u=0;
    while (n)
    {
        if (n & 1)
        {
            vector < vector <int> > res;
            res.resize(2);
            res[0].resize(2);
            res[1].resize(2);
            for (int w=0; w<2; w++)
                for (int j=0; j<2; j++)
                        for (int k=0; k<2; k++)
                            res[w][j]+=ans[w][k]*step[u][k][j], res[w][j]%=mod;
            ans=res;
        }
        u++;
        n>>=1;
    }
    int answer=ans[0][0];
    cout<<answer;
}