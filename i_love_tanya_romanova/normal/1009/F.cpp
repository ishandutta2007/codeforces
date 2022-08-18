/*
Dreamt up a new word today
With my ignorance I gave it meaning
Who was I to know?
To say it is to know it
To hear it is to believe, is to believe

I dreamt the world would end
I was not wrong
To doubt, to discredit
The other words I've heard before
From inside a shell pretending

It's all you've shown your faith
And what you've always known
So lay your trust in the unthinkable
It's time to justify your lesser faith

It's all your faith has shown
And all you'll ever know
Why do you matter, you're insignificant
How can you justify your lesser faith?

Oh!
To know it is to fear it
To feel it is to say no, is to say no
To the blazing highs and lows
I know I'll fail
To break, to cast it down
You take your lead
From a staff that must be broken in two

It's all your faith has shown
And all you'll ever know
Why do you matter, you're insignificant
How can you justify your lesser faith?
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

#define bs 998244353

const int N = 1000031;

int n;
vector<int> g[N];
vector<int > sons[N];
int subsize[N];

int used[N];

map<int,int > S[N];
int ptr[N];
int ans[N];
map<int,int >::iterator it;

int mx_val[N],mx_id[N];

void merge_sets(int a,int b){
	for (it=S[a].begin();it!=S[a].end();it++){
		int id=(*it).first;
		int am=(*it).second;
		am+=S[b][id];
		if (mx_val[b]<am||mx_val[b]==am&&mx_id[b]>id){
			mx_val[b]=am;
			mx_id[b]=id;
		}
		S[b][id]=am;
	}
}

void merge(int a,int b){ // b to a
//	cout<<a<<" "<<b<<" "<<S[ptr[a]].size()<<" "<<S[ptr[b]].size()<<endl;
	if (S[ptr[a]].size()<S[ptr[b]].size()){
		merge_sets(ptr[a],ptr[b]);
		swap(ptr[a],ptr[b]);
//		cout<<a<<" "<<b<<" "<<S[ptr[a]].size()<<" "<<S[ptr[b]].size()<<endl;
	}
	else
	{
		merge_sets(ptr[b],ptr[a]);
	}
}


void dfs(int v,int dep){
	used[v]=1;
	subsize[v]=1;
	ptr[v]=v;
	S[ptr[v]][dep]=1;
	mx_val[ptr[v]]=1;
	mx_id[ptr[v]]=dep;

	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to,dep+1);
		merge(v,to);
		sons[v].push_back(to);
	}
	ans[v]=mx_id[ptr[v]]-dep;

}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1,0);

	for (int i=1;i<=n;i++){
		cout<<ans[i]<<"\n";
	}

//	cin.get(); cin.get();
	return 0;
}