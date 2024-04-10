/*
My clothes don't fit and I have no point of view
I got a bad reputation but I don't believe it's true
I had something going but I blew it down the can
Not exactly what I planned
I'm a ramshackle man
That's what I am

I look like a joker but I feel like a one eyed jack
Shuffling around never get to the top of the park
I said to the dealer put the ace in my hand
But he couldn't give a damn
I'm a ramshackle man
That's what I am

I sit down thinking bout the things I have to do
I start out fine then I pick up something new
Stumbled through the door that's how it all began
Now it's buried in the sand
I'm a ramshackle man
That's what I am

The stars shine bright when the boys come out to play
Never feeling more than I'm feeling right here today
I used to be fresh but now I'm second hand
I do what I can
I'm a ramshackle man
That's what I am
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
#define hash asdgasdgasdgdfrywewery

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1100031;

int tests;

long double C,T;

vector<pair<int,int> > order;
int a[N],p[N];
int n;

long double PW[131];

long double dp[2][131][1301];

long double solver(long double t,long double learning){
	long double my_skill=learning*C+1;
	t=t/my_skill;
	return t+learning;
}

bool capable_of(int problems_solved,int my_score){

	if (dp[n%2][problems_solved][my_score]>1e16)
		return false;
	long double time_needed=0;
	time_needed=dp[n%2][problems_solved][my_score];
	// let's use ternary, I suck at derivatives
	long double l,r;
	l=0;
	r=T;
	for (int iter=1;iter<=200;iter++){
		long double mid1=l*2+r;
		long double mid2=l+r*2;
		mid1/=3;
		mid2/=3;
		long double T1=solver(time_needed,mid1);
		long double T2=solver(time_needed,mid2);
		if (T1<T2)
			r=mid2;
		else
			l=mid1;
	}
	long double best_sum=solver(time_needed,l); // pure waste of time
	best_sum+=10*problems_solved; // plus movies
	//cout<<problems_solved<<" "<<my_score<<" "<<best_sum<<" "<<l<<" "<<time_needed<<endl;
	if (best_sum<=T+1e-6){
		return true;
	}
	return false;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	PW[0]=10.0/9; // already 0.9 at first problem
	for (int i=1;i<=100;i++){
		PW[i]=PW[i-1]*10.0/9;
	}

	/*for (int i=0;i<=10;i++){
		cout<<PW[i]<<"@"<<1.0/pow(0.9,i+1)<<endl;
	}
	cout<<endl;
*/

	cin>>tests;
	for (;tests;--tests){
		cin>>n;
		cin>>C>>T;
		for (int i=1;i<=n;i++){
			cin>>a[i]>>p[i];
		}
		order.clear();
		for (int i=1;i<=n;i++){
			order.push_back(make_pair(a[i],i));
		}
		sort(order.begin(),order.end());
		reverse(order.begin(),order.end());

		for (int i=0;i<=1;i++){
			for (int j=0;j<=100;j++){
				for (int q=0;q<=1000;q++){
					dp[i][j][q]=1e18;
				}
			}
		}

		dp[0][0][0]=0;
		for (int i=0;i<order.size();i++){
			int id=order[i].second;
			for (int taken=0;taken<=i;taken++){
				for (int cur_sum=0;cur_sum<=10*taken;cur_sum++){
					dp[1-i%2][taken][cur_sum]=min(dp[1-i%2][taken][cur_sum],dp[i%2][taken][cur_sum]);
					if (dp[i%2][taken][cur_sum]>1e16) // can get 1e6 skill and cover 1e5 real time as 1e11.
						continue;
					long double need_here=a[id]*PW[taken];
					int new_score=cur_sum+p[id];
					dp[1-i%2][taken+1][new_score]=min(dp[1-i%2][taken+1][new_score],dp[i%2][taken][cur_sum]+need_here);
				}
			}
		}

		//cout<<dp[n%2][2][7]<<endl;

		int ans=0;

		for (int i=1;i<=n;i++){
			for (int j=n*10-1;j>=0;j--){
				dp[n%2][i][j]=min(dp[n%2][i][j],dp[n%2][i][j+1]);
			}
		}

		//cout<<dp[n%2][3][1]<<endl;

		for (int problems_solved=1;problems_solved<=n;problems_solved++){
			int l,r;
			l=0;
			r=problems_solved*10;
			while (l<r){
				int mid=l+r+1;
				mid/=2;
				if (capable_of(problems_solved,mid))
					l=mid;
				else
					r=mid-1;
			}
			ans=max(ans,l);
		}
		cout<<ans<<endl;
	}


//	cin.get(); cin.get();
	return 0;
}