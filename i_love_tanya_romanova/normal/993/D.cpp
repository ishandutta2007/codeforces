/*
This is for the demented,
You are now represented.
Highly recommended
it's good to be tormented.

I wanna live like there's no tomorrow,
And I don't care what the people say.
They say I'm mad, and completely loco,
But I wouldn't have it any other way.

I went to see a respected doctor
To find out just what was wrong with me,
She made fun of my black shirts and music.
She took my money.

This is for the demented,
You are now represented.
Highly recommended,
It's good to be tormented.

We try to judge and diagnose you,
Your dreams and passions,
It's time to give them up.
You gotta fade into society.
Change, or else you're out of luck.

This is for the demented,
You are now represented.
Highly recommended,
It's good to be tormented.

Challenge unfairness, humanity,
One life's essential, you'll see, you will see.
Challenge unfairness, humanity,
One life's essential, you'll see, you will see.

Sometimes I feel like I'm the only one,
My head is racing,
But I don't want to come undone.
It's your life,
So make it your own,
Remember you're not alone.

This is for the demented, you are now, represented.
Highly recommended, it's good to be, tormented.

This is for the demented, you are now, represented.
Highly recommended, it's good to be, tormented.
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
#define prev asdgSHJsfgsdfhdsh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1200031;

int n;
long long dp[2][51][51][5055];
int a[55],b[55];
vector<pair<int,int> > order;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		cin>>b[i];
	}

	order.clear();
	for (int i=1;i<=n;i++){
		order.push_back(make_pair(a[i],b[i]));
	}
	sort(order.begin(),order.end());
	reverse(order.begin(),order.end());


	for (int from_prev=0;from_prev<=50;from_prev++){
		for (int from_this=0;from_this<=50;from_this++){
			for (int s=0;s<=5000;s++){
				dp[0][from_prev][from_this][s]=dp[1][from_prev][from_this][s]=1e18;
			}
		}
	}
	dp[0][0][0][0]=0;

	int l_cut=0;

	for (int i=0;i<order.size();i++){

		//cout<<i<<endl;

		for (int j=0;j<=i;j++){
			for(int q=0;q<=50;q++){
				for (int c=0;c<=i*100;c++){
					dp[1-i%2][j][q][c]=1e18;
				}
			}
		}

		//cout<<"@"<<" "<<i<<endl;

		for (int prv=0;prv<=l_cut;prv++){
			for (int ths=0;ths<=i-l_cut;ths++){
				int nw_prv=prv;
				int nw_ths=ths;
				if (i>0&&order[i].first!=order[i-1].first)
					nw_prv+=nw_ths,
					nw_ths=0;
				for (int tw=0;tw<=100*i;tw++){
					if (dp[i%2][prv][ths][tw]>1e15)
						continue;
					//cout<<i<<" "<<prv<<" "<<ths<<" "<<tw<<endl;
					// make new
					dp[1-i%2][nw_prv][nw_ths+1][tw+order[i].second]=min(dp[1-i%2][nw_prv][nw_ths+1][tw+order[i].second],
							dp[i%2][prv][ths][tw]+order[i].first);
					// add to old
					if (nw_prv>0)
						dp[1-i%2][nw_prv-1][nw_ths][tw]=
								min(dp[1-i%2][nw_prv-1][nw_ths][tw],dp[i%2][prv][ths][tw]);
				}
			}
		}

		if (i>0&&order[i].first!=order[i-1].first)
			l_cut=i;
	}


	long long ans=1e18;

	for (int prv=0;prv<=50;prv++){
		for (int here=0;here<=50;here++){
			for (int w=1;w<=5000;w++){
				long long min_cost=dp[n%2][prv][here][w];
				long long min_aver=min_cost*1000;
				min_aver=min_aver/w+(min_aver%w>0);
				ans=min(ans,min_aver);
			}
		}
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}