/*
Thought I could fake this thing alright
Thought it could somehow get me by
Watching the doctors as they slide
Needles into my eye

Thought I could finally get around
Laughable symptoms keep me down
Faces I see all keep me blind
And now theyre redemptions mine

Now that I cant exchange actions for words
Now that I found these inside fears the worst
Now that I know theres no place left to hide
Can I become all I thought I might

As the leaders who follow the path of whoever was standing round them
Call to say what Im missing and into a detail they always go
Dont believe them but offer condolences under the circumstances
All too often Im missing the spirit to fit in so call me out

Thought I could soundly sleep tonight
Positive clear and breathing right
Panic attacks, panic attacks me now
Seems like a fair redemption
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

const int N = 600000;

int tests,n;
vector<int> g[N];
int k,in_first[N];
int k2,in_second[N];
int QU;
int used[N];

void answer(int val){
	cout<<"C "<<val<<endl;
}

int dfs(int v){
	if (in_first[v])
		return v;
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		int there=dfs(to);
		if (there)
			return there;
	}
	return 0;
}

int queryB(int id){ // ask about id in tree B - where in A?
	cout<<"B "<<id<<endl;
	int val;
	cin>>val;
	return val;
}

int queryA(int id){ // ask about id in tree A - where in B?
	cout<<"A "<<id<<endl;
	int val;
	cin>>val;
	return val;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>n;
		for (int i=1;i<=n;i++){
			g[i].clear();
			used[i]=0;
		}
		for (int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		cin>>k;
		for (int i=1;i<=n;i++){
			in_first[i]=0;
		}
		for (int i=1;i<=k;i++){
			int val;
			cin>>val;
			in_first[val]=1;
		}
		cin>>k2;
		for (int i=1;i<=n;i++){
			in_second[i]=0;
		}
		for (int i=1;i<=k2;i++){
			int val;
			cin>>val;
			QU=val;
			in_second[val]=1;
		}

		int here=queryB(QU);
		if (in_first[here]){
			answer(here);
			continue;
		}

		int V=dfs(here);
		int his_id=queryA(V);
		if (in_second[his_id]){
			answer(V);
		}
		else
		{
			answer(-1);
		}
	}
//	cin.get(); cin.get();
	return 0;
}