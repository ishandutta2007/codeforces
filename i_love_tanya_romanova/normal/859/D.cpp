/*
The darkest past
Forever could last
Beneath the sanctity I pray
For honestys sake

Never sail the lie
When its scorn is brought to life
Forever sacrifice the flame

The die is cast
The circle one less
Through brief insanity I pray
For honestys sake

Never say deny
When its scorn is brought to life
Forever Sacrifice the flame

So heartless so
Careless dreams torment the soul

So dark the souls
Spare us dreams torment the soul
*/

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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 500031;

int n;
double chance[200][200];
double chance_alive[200][200];
double best_ev[200][200];

bool same_branch(int a,int b,int c)
{
	return (a>>c)==(b>>c);
}

double res_for_pair[200][200];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=0;i<(1<<n);i++){
		for (int j=0;j<(1<<n);j++){
			cin>>chance[i][j];
			chance[i][j]*=0.01;
		}
	}

	for (int i=0;i<(1<<n);i++)
	{
		chance_alive[0][i]=1.0;
	}

	for (int lev=1;lev<=n;lev++){
		for (int i=0;i<(1<<n);i++)
		{
			for (int j=0;j<(1<<n);j++)
			{
				res_for_pair[i][j]=0;
			}
		}

			for (int my_pick1=0;my_pick1<(1<<n);my_pick1++){
				for (int my_pick2=0;my_pick2<(1<<n);my_pick2++)
				{
					if (!same_branch(my_pick1,my_pick2,lev))
						continue;
					if (same_branch(my_pick1,my_pick2,lev-1))
						continue;
					for (int i=0;i<(1<<n);i++)
					{
						if (!same_branch(i,my_pick1,lev))
							continue;
						for (int j=0;j<(1<<n);j++)
						{
							if (!same_branch(j,my_pick1,lev))
								continue;
							if (same_branch(i,j,lev-1))
								continue;
							double here=best_ev[lev-1][my_pick1]+best_ev[lev-1][my_pick2];
							if (i==my_pick1)
								here+=(1<<lev)*0.5;
							here*=chance_alive[lev-1][i]*chance_alive[lev-1][j]*chance[i][j];
							res_for_pair[my_pick1][my_pick2]+=here;
					//		cout<<lev<<" "<<i<<" "<<j<<" "<<my_pick1<<" "<<my_pick2<<" "<<here<<endl;
						}
					}
				}
			}

		for (int i=0;i<(1<<n);i++)
		{
			for(int j=0;j<(1<<n);j++)
			{
				if (!same_branch(i,j,lev))
					continue;
				if (same_branch(i,j,lev-1))
					continue;
				chance_alive[lev][i]+=chance_alive[lev-1][i]*chance_alive[lev-1][j]*chance[i][j];
			}
		}

		/*for (int i=0;i<(1<<n);i++)
		{
			for (int j=0;j<(1<<n);j++)
			{
				cout<<res_for_pair[i][j]<<" ";
			}
			cout<<endl;
		}*/


		/*for (int i=0;i<(1<<n);i++)
		{
			cout<<chance_alive[lev][i]<<" ";
		}
		cout<<endl;
*/
		for (int i=0;i<(1<<n);i++)
		{
			for (int j=0;j<(1<<n);j++)
			{
				best_ev[lev][i]=max(best_ev[lev][i],res_for_pair[i][j]);
			}
		}
	}

	double ans=0;
	for (int i=0;i<(1<<n);i++)
		ans=max(ans,best_ev[n][i]);
	cout.precision(12);
	cout<<fixed<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}