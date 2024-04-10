/*
"What you don't know" the legend goes "can't hurt you"
If you only want to live and die in fear
They tell us to believe just half of what we see
And absolutely nothing that we hear

Resist the twist to truth no matter what the cost
Supplant the rights with wrongs inside our heads
Outlawing all the questions to the answers
That no one likes when someone ends up dead

Dystopia
Dystopia
Dystopia
Dystopia

"What you don't know" the legend goes "can't hurt you"
If you only want to live and die in a cage
There's panic and there's chaos, rampant in the streets
Where useless thoughts of peace are met with rage

Demoralized and overmastered people think
The quickest way to end a war is lose
Dictatorship ends starting with tyrannicide
You must destroy the cancer at it's root

Dystopia
Dystopia
Dystopia
Dystopia
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

const int N = 300031;

int n,k,x,ar[5031];

long long dp[5031][5031];

int L[5031];

long long sparse[20][5031];

long long get(int l,int r){
	int span=r-l+1;
	span=L[span];
	return max(sparse[span][l],sparse[span][r-(1<<span)+1]);
}

void build_sparse(int lev){
	for (int i=1;i<=n;i++){
		sparse[0][i]=dp[lev][i];
	}
	for (int lev=1;lev<15;lev++){
		for (int i=1;i+(1<<lev)-1<=n;i++){
			sparse[lev][i]=max(sparse[lev-1][i],sparse[lev-1][i+(1<<lev)/2]);
		}
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	for (int i=2;i<=5000;i++){
		L[i]=L[i/2]+1;
	}

	cin>>n>>k>>x;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}

	for (int lev=1;lev<=x;lev++){
		for (int i=1;i<=n;i++){
			dp[lev][i]=-1e18;
		}
	}

	for (int i=1;i<=k;i++){
		dp[1][i]=ar[i];
	}

	for (int lev=2;lev<=x;lev++){

		build_sparse(lev-1);
		for (int i=2;i<=n;i++){
			int ps=max(1,i-k);
	//		cout<<ps<<" "<<i-1<<" "<<get(ps,i-1)<<endl;
			dp[lev][i]=get(ps,i-1)+ar[i];
		}
	}

	long long ans=-1e18;
	for (int i=n-k+1;i<=n;i++){
		ans=max(ans,dp[x][i]);
	}

	if (ans<0)
		ans=-1;

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}