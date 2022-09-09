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

//#define int li

int n, m;
int matrix[505][505];
int spir[505][505][255];
int sums1[505][505];
int sums2[505][505];

int sum1(int i, int l, int r)
{
    return sums1[i][r]-((l>0)?sums1[i][l-1]:0);
}
int sum2(int i, int l, int r)
{
    return sums2[i][r]-((l>0)?sums2[i][l-1]:0);
}

void solve()
{  
    cin>>n>>m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin>>matrix[i][j];
    for (int i=0; i<n; i++)
    {
        sums1[i][0]=matrix[i][0];
        for (int j=1; j<m; j++)
            sums1[i][j]=sums1[i][j-1]+matrix[i][j];
    }
    for (int i=0; i<m; i++)
    {
        sums2[i][0]=matrix[0][i];
        for (int j=1; j<n; j++)
            sums2[i][j]=sums2[i][j-1]+matrix[j][i];
    }
    int ans=-(1<<30);
    for (int i=n-3; i>=0; i--)
        for (int j=m-3; j>=0; j--)
        {
            spir[i][j][1]=sum1(i, j, j+1)+sum2(j+2, i, i+1)+sum1(i+2, j, j+2);
            ans=max(ans, spir[i][j][1]);
            if (i+4>=n || j+4>=m)
                continue;
            spir[i][j][2]=sum1(i, j, j+3)+sum2(j+4, i, i+3)+sum1(i+4, j, j+4)+sum2(j, i+2, i+3)+sum1(i+2, j+1, j+2);
            ans=max(ans, spir[i][j][2]);
            //cout<<ans<<endl;
            for (int k=3; 2*k+i<n && 2*k+j<m; k++)
            {
                spir[i][j][k]=spir[i+2][j+2][k-2]+sum1(i, j, j+2*k-1)+sum2(j+2*k, i, i+2*k-1)+sum1(i+2*k, j, j+2*k)+sum2(j, i+2, i+2*k-1)+sum1(i+2, j+1, j+1);
                ans=max(ans, spir[i][j][k]);
            }
        }
    cout<<ans;
}