#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
/*
BE CAREFUL: ISN'T INT EQUAL TO LONG LONG?

REAL SOLUTION AFTER MAIN FUNCTION
*/
#define mp make_pair
#define pb push_back
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
void solve();
int main ()
{
#ifdef _DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}
#define int li
unsigned long long INF=1LL<<63;
int n, m, k;
int p[200][200];
pi q[20000];
unsigned long long dp[300][300];
string s;
bool done[400];
void solve ()
{
        cin>>n>>m>>k;
        s.resize(m+n+10);
        for ( int i=0; i<n; i++ )
                for (int j=0; j<m; j++)
                {
                        cin>>p[i][j];
                        q[p[i][j]]=mp (i+1, j+1);
                }
        s[2]='(';
        done[2]=true;
        s[n+m]=')';
        done[n+m]=true;
        for ( int j=1; j<=n*m; j++ )
        {
                pi now=q[j];
                int cur=now.first+now.second;
                if ( done[cur] )
                        continue;
                s[cur]='(';
                done[cur]=true;
                memset (dp, 0, sizeof dp);
                dp[2][1]=1;
                for ( int pos=2; pos<n+m; pos++ )
                        for (int bal=0; bal<=pos-1; bal++)
                        {
                                if ( done[pos+1] )
                                {
                                        if ( s[pos+1]=='(' )
										{
												if (dp[pos][bal]<INF && dp[pos][bal]+dp[pos+1][bal+1]>=0 && dp[pos][bal]+dp[pos+1][bal+1]<INF)
                                                dp[pos+1][bal+1]+=dp[pos][bal];
												else 
													dp[pos+1][bal+1]=INF;
										}
                                        else 
                                                if (bal>0)
													if (dp[pos][bal]<INF && dp[pos][bal]+dp[pos+1][bal-1]>=0 && dp[pos][bal]+dp[pos+1][bal-1]<INF)
                                                        dp[pos+1][bal-1]+=dp[pos][bal];
													else 
														dp[pos+1][bal+1]=INF;
                                }
                                else 
                                {
									if (dp[pos][bal]<INF && dp[pos][bal]+dp[pos+1][bal+1]>=0 && dp[pos][bal]+dp[pos+1][bal+1]<INF)
                                        dp[pos+1][bal+1]+=dp[pos][bal];
									else 
										dp[pos+1][bal+1]=INF;
                                        if (bal>0)
											if (dp[pos][bal]<INF && dp[pos][bal]+dp[pos+1][bal-1]>=0 && dp[pos][bal]+dp[pos+1][bal-1]<INF)
                                                dp[pos+1][bal-1]+=dp[pos][bal];
											else 
												dp[pos+1][bal+1]=INF;
                                }
                        }
                int var=dp[n+m][0];
                if ( k>var )
                {
                        k-=var;
                        s[cur]=')';
                }
                else 
                        s[cur]='(';
        }

        for ( int i=0; i<n; i++ )
        {
                for (int j=0; j<m; j++)
                        cout<<s[i+j+2];
                cout<<endl;
        }
}