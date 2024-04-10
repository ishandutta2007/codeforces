/*
Seven deadly sins
Seven ways to win
Seven holy paths to hell
And your trip begins

Seven downward slopes
Seven bloodied hopes
Seven are your burning fires,
Seven your desires...

I am he the bornless one
The fallen angel watching you
Babylon, the scarlet whore
I'll infiltrate your gratitude
Don't you dare to save your son
Kill him now and save the young ones
Be the mother of a birth strangled babe
Be the devils own, Lucifer's my name

Moonchild - hear the mandrake scream
Open the seventh seal
Moonchild - You'll be mine soon child
Moonchild - take my hand tonight

I count the heads of those unborn
The accursed ones I'll find them all
If you die by your own hand
As a suicide you shall be damned
And if you try to save your soul
I will torment you - you shall not grow old
With every second and passing breath
You'll be so alone your soul will bleed to death

The twins they are exhausted, seven is the night
Gemini is rising as the red lips kiss to bite
Seven angels seven demons battle for his soul
When Gabriel lies sleeping, this child was born to die

One more dies one more lives
One baby cries One mother grieves
For all the sins you will commit
You'll beg forgiveness and none I'll give
A web of fear shall be your coat
To clothe you in the night
A lucky escape for you youngman
But I see you damned in endless night.
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

bool is_good(int mask,int sz){
	set<int> S;
	vector<int> V;
	for (int i=0;i<(1<<sz);i++){
		if (mask&(1<<i)){
			S.insert(i);
			V.push_back(i);
		}
	}
	for (int i=0;i<V.size();i++){
		if (S.find(V[i]^((1<<sz)-1))==S.end())
			return false;
	}
	for(int i=0;i<V.size();i++){
		for (int j=i+1;j<V.size();j++){
			if (S.find(V[i]&V[j])==S.end())
				return false;
		}
	}
	return true;
}

void show_set(int mask,int n){
	cout<<"---"<<endl;
	for (int i=0;i<(1<<n);i++){
		if (mask&(1<<i)){
			for (int j=n-1;j>=0;j--){
				if (i&(1<<j))
					cout<<1;
				else
					cout<<0;
			}
			cout<<endl;
		}
	}
}

int len,n;
string st[N];
int used[N];
int C;

void dfs(int v){
	used[v]=1;
	//cout<<v<<endl;
	++C;
	for (int i=0;i<len;i++){
		if (used[i])
			continue;
		int can_move=1;
		for (int j=0;j<n;j++){
			if (st[j][v]!=st[j][i])
				can_move=0;
		}
		if (can_move)
			dfs(i);
	}
}

long long dp[1031][1031],BELL[1031];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	/*
	// MATH IS MAGIC
	for (int n=1;n<=10;n++){
		int cnt=(1<<n);
		cout<<n<<":"<<endl;
		for (int mask=1;mask<(1<<cnt);mask++){
			if (is_good(mask,n)){
				show_set(mask,n);
			}
		}
	}
	*/

	dp[1][1]=1;
	for (int i=1;i<=1000;i++){
		for (int j=0;j<=1000;j++){
			if (dp[i][j]==0)
				continue;
			dp[i+1][j+1]+=dp[i][j];// new set
			dp[i+1][j]+=dp[i][j]*j;
			dp[i+1][j+1]%=bs;
			dp[i+1][j]%=bs;
		}
	}

	for (int i=1;i<=1000;i++){
		for (int j=1;j<=1000;j++){
			BELL[i]+=dp[i][j];
			BELL[i]%=bs;
		}
	/*	if (i<10)
			cout<<i<<" "<<BELL[i]<<endl;*/
	}

	cin>>len>>n;
	for (int i=0;i<n;i++){
		cin>>st[i];
	}

	long long ans=1;

	for (int i=0;i<len;i++){
		if (used[i])
			continue;
		C=0;
		dfs(i);
		//cout<<i<<"@"<<endl;
		//cout<<C<<endl;
		ans*=BELL[C];
		ans%=bs;
	}

	cout<<ans<<endl;


	cin.get(); cin.get();
	return 0;
}