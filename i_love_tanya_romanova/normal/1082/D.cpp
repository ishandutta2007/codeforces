/*
I feel unhappy
I feel so sad
I lost the best friend
That I ever had

She was my woman
I loved her so
But it's too late now
I've let her go

I'm going through changes
I'm going through changes

We shared the years
We shared each day
In love together
We found a way

But soon the world
Had its evil way
My heart was blinded
Love went astray

I'm going through changes
I'm going through changes

It took so long
To realize
That I can still hear
Her last goodbyes

Now all my days
Are filled with tears
Wish I could go back
And change these years

I'm going through changes
I'm going through changes
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

const int N = 200031;

int n;
int deg[N],in_chain[N];
int s_deg;
vector<int> leaves,non_leaves;
vector<pair<int,int> > ans;

int get_free(){
	for (int i=1;i<=n;i++){
		if (in_chain[i]==1&&deg[i]>0){
			return i;
		}
	}
	return -1;
}

void add_edge(int a,int b){
	deg[a]--;
	deg[b]--;
	ans.push_back(make_pair(a,b));
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	// n>=3;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>deg[i];
		s_deg+=deg[i];
		if (deg[i]==1)
			leaves.push_back(i);
		else
			non_leaves.push_back(i),
			in_chain[i]=1;
	}

	if (s_deg<2*n-2){
		cout<<"NO"<<endl;
		return 0;
	}

	int Ans=non_leaves.size()-1;

	if (leaves.size()>0)
		Ans++;
	if (leaves.size()>1)
		Ans++;

	cout<<"YES"<<" "<<Ans<<endl;
	for (int i=1;i<non_leaves.size();i++){
		add_edge(non_leaves[i-1],non_leaves[i]);
	}

	for (int i=0;i<leaves.size();i++){
		if (i==0)
			add_edge(leaves[i],non_leaves[0]);
		else if (i==1)
			add_edge(leaves[i],non_leaves[non_leaves.size()-1]);
		else
		{
			int p=get_free();
			add_edge(leaves[i],p);
		}
	}


	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}

//	cin.get(); cin.get();
	return 0;
}