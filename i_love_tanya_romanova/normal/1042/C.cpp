/*
Contemplating, isolating
And it's stressing me out
Different visions, contradictions
Why won't you let me out?

I need a way to separate yeah
But I promise you that I'll make sure you never forget me
(Never forget me)

Now that you want it
Now that you need it
I'm too far gone
You're trying to blame me
But I'm not breaking
I'm telling you, I'm bulletproof
Believe me, I'm bulletproof
You made me so bulletproof
And now I'm too far gone

You're addicted and so twisted
That it's freaking me out
Distant eyes, it's no surprise
You can't do anything now

I need a way to separate yeah
But I'm telling you that nothing will ever be the same

Now that you want it
Now that you need it
I'm too far gone
You're trying to blame me
But I'm not breaking
I'm telling you, I'm bulletproof
Believe me, I'm bulletproof
You made me so bulletproof
And now I'm too far gone

(Now that you want it)
(Now that you need it)
I'm too far gone
You're trying to blame me
But I'm not breaking
I'm telling you, I'm bulletproof
Believe me, I'm bulletproof
You made me so bulletproof
And now I'm too far gone
I'm telling you, I'm bulletproof
Believe me, I'm bulletproof
You made me so bulletproof
And now I'm too far gone
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

#define bs 998244353

const int N = 600000;

int n,ar[N];

vector<pair<int,int> > order;
int have_zero;

int neg,pos;

void zero_solver(){
	for (int i=2;i<=n;i++){
		cout<<1<<" "<<i<<" "<<1<<"\n";
	}
}

vector<pair<int,int> > pos_list,neg_list;
vector<int> list1,list2;
int totake[N];

void default_solver(){
	if (neg_list.size()%2)
		neg_list.pop_back();
	for (int i=0;i<pos_list.size();i++){
		totake[pos_list[i].second]=1;
	}
	for (int i=0;i<neg_list.size();i++){
		totake[neg_list[i].second]=1;
	}
	for (int i=1;i<=n;i++){
		if (totake[i])
			list1.push_back(i);
		else
			list2.push_back(i);
	}

	for (int i=1;i<list1.size();i++){
		cout<<1<<" "<<list1[i]<<" "<<list1[0]<<endl;
	}
	for (int i=1;i<list2.size();i++){
		cout<<1<<" "<<list2[i]<<" "<<list2[0]<<endl;
	}
	if (list2.size()){
		cout<<2<<" "<<list2[0]<<endl;
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		order.push_back(make_pair(ar[i],i));
		if (ar[i]==0)
			have_zero=1;
		if (ar[i]<0)
			neg++,
			neg_list.push_back(make_pair(ar[i],i));
		if (ar[i]>0)
			pos++,
			pos_list.push_back(make_pair(ar[i],i));
	}

	sort(neg_list.begin(),neg_list.end());

	if (neg==1&&pos==0){
		if (have_zero){
			zero_solver();
			return 0;
		}
		// should have zero, n>1
	}

	if (neg==0&&pos==0){
		zero_solver();
		return 0;
	}

	// at least 1 pos, or at least 2 neg -> have a solution; (or 1 neg with no zeros -> n>1)

	default_solver();


//	cin.get(); cin.get();
	return 0;
}