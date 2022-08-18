/*
She came from the past
She was never meant to last
Her destiny was fatal
From the start
A messenger from hell
She cast a deadly spell
On all of those who dare
To cross her heart
Ain't no use in you trying to run
Fate has taken it's toll
Just one look and the damage is done
Burn your eyes
Turn your heart into stone
History foretold of a circle
Cast in gold
An evil seed of power
Sealed within
But fate has lent a hand
Destroyed the golden band
And freed her soul
To wash the land with sin
Ain't no use in you trying to run
Fate has taken it's toll
Just one look and the damage is done
Burn your eyes
Turn your heart into stone
She cast a deadly spell
She put a spell on you
She's got evil in her heart
Turn your heart into stone
Turn your heart into stone
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

const int N = 600031;

int n,k;
string st;
int am;
int total_size;

int done[531][531][11],knap[531][531][11];
vector<int> g[531];
int memo[531][531][11];
int subsize[N];

int have[531][11];
int C;
int dep[N];

int solve(int v,int dep_above,int to_put){

	//cout<<v<<" "<<dep_above<<" "<<to_put<<endl;

	if (done[v][dep_above][to_put])
		return memo[v][dep_above][to_put];
	done[v][dep_above][to_put]=1;

	for (int i=0;i<=g[v].size();i++){
		for (int j=0;j<=to_put;j++){
			knap[v][i][j]=-1e9;
		}
	}
	knap[v][0][0]=0;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		for (int already=0;already<=to_put;already++){
			for (int here=0;here+already<=to_put;here++){
				for (int in_root=0;in_root<=1;in_root++){
					int saved=knap[v][i][already];
					if (in_root)
						saved+=subsize[to]*(dep[to]-dep_above);
					if (in_root==1&&here==0)
						continue;
					if (in_root==1)
						saved+=solve(to,dep[to],here-1);
					else
						saved+=solve(to,dep_above,here);
					knap[v][i+1][already+here]=max(knap[v][i+1][already+here],saved);
				}
			}
		}
	}
	for (int i=0;i<=to_put;i++)
		memo[v][dep_above][to_put]=max(memo[v][dep_above][to_put],knap[v][g[v].size()][i]);
	return memo[v][dep_above][to_put];
}

void add(string st,int am){
	int ptr=0;
	for (int i=0;i<st.size();i++){
		int here=st[i]-'0';
		if (have[ptr][here]==0){
			++C;
			have[ptr][here]=C;
			g[ptr].push_back(C);
			dep[C]=dep[ptr]+1;
		}
		ptr=have[ptr][here];
		subsize[ptr]+=am;
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;

	for (int i=1;i<=n;i++){
		cin>>st;
		cin>>am;
		add(st,am);
		total_size+=st.size()*am;
	}

	int res=solve(0,0,k);
	cout<<total_size-res<<endl;

//	cin.get(); cin.get();
	return 0;
}