
#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 700031;

int n,m;
unsigned int can[70][550][20][2],can_t[70][550][20][2];
unsigned int one = 1;
int have_edge[550][550];
long long longest_from[70][660][3];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=0;i<m;i++)
		{
			int a,b,tp;
			cin>>a>>b>>tp;
			--a;
			--b;
			have_edge[a][tp]=1;
			can[0][a][b/32][tp]|=(one<<(b%32));
			can_t[0][b][a/32][tp]|=(one<<(a%32));
		}

	for (int lev=1;lev<=60;lev++)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				for (int tp=0;tp<2;tp++)
				{
					for (int q=0;q<=n/32;q++)
					{
						if (can[lev-1][i][q][tp]&can_t[lev-1][j][q][tp^1])
						{
							can[lev][i][j/32][tp]|=(one<<(j%32));
							can_t[lev][j][i/32][tp]|=(one<<(i%32));
						}
					}
				}
			}
		}
	}

	bool can_inf=0;

	for (int i=0;i<=0;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (can[60][i][j/32][0]&(one<<(j%32)))
			{
				can_inf=1;
			}
		}
	}

	if (can_inf)
	{
		cout<<-1<<endl;
		return 0;
	}

	/*int longest_level=-1;

	for (int lev=0;lev<=60;lev++)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (can[lev][i][j][0]&(one<<(j%32)))
					longest_level=lev;
			}
		}
	}
*/
	for (int i=0;i<=60;i++)
	{
		for (int j=0;j<n;j++)
		{
			for (int q=0;q<2;q++)
			{
				longest_from[i][j][q]=-1;
			}
		}
	}

	for (int i=0;i<n;i++)
	{
		for (int start_tp=0;start_tp<=1;start_tp++)
		{
			longest_from[0][i][start_tp]=0;
			if (have_edge[i][start_tp])
				longest_from[0][i][start_tp]=1;
		}
	}

	for (int lev=1;lev<=60;lev++)
	{
		for (int i=0;i<n;i++)
		{
			for (int start_tp=0;start_tp<=1;start_tp++)
			{
				longest_from[lev][i][start_tp]=longest_from[lev-1][i][start_tp]; // <(1<<lev)/2
				for (int to=0;to<n;to++)
				{
					if (can[lev-1][i][to/32][start_tp]&(one<<(to%32)))
					{
						longest_from[lev][i][start_tp]=max(longest_from[lev][i][start_tp],
								(1ll<<(lev-1))+longest_from[lev-1][to][1^start_tp]);
					}
				}
			}
		}
	}

	long long ans=longest_from[60][0][0];
	if (ans>1000000000000000000ll)
		ans=-1;
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}