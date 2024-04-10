/*
The path you tread is narrow
And the drop is sheer and very high
The ravens all are watching
From a vantage point nearby
Apprehension creeping
Like a tube train up your spine
Will the tightrope reach the end
Will the final cuplet rhyme

And it's high time Cymbaline
It's high time Cymbaline
Please wake me

A butterfly with broken wings
Is falling by your side
The ravens all are closing in
There's nowhere you can hide
Your manager and agent
Are both busy on the phone
Selling colored photographs
To magazines back home

And it's high time Cymbaline
It's high time Cymbaline
Please wake me

The lines converging where you stand
They must have moved the picture plain
The leaves are heavy round your feet
You hear the thunder of the train
Suddenly it strikes you
That they're moving into range
And Doctor Strange is always changing size

And it's high time Cymbaline
It's high time Cymbaline
Please wake me

And it's high time Cymbaline
It's high time Cymbaline
Please wake me
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

const int N = 600031;

int n;
vector<int> g[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=2;i<=n;i++){
		int p;
		cin>>p;
		g[p].push_back(i);
	}

	for (int i=1;i<=n;i++){
		if (g[i].size()==0)
			continue;
		int cnt_leaves=0;
		for (int j=0;j<g[i].size();j++){
			int to=g[i][j];
			if (g[to].size()==0)
				++cnt_leaves;
		}
		if (cnt_leaves<3){
			cout<<"No"<<endl;
			return 0;
		}
	}

	cout<<"Yes"<<endl;

	cin.get(); cin.get();
	return 0;
}