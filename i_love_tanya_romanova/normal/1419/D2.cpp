/*
Perched alone he sits there broken
An elder man with storm clouds setting in his eyes
He counts the sands of time, remembering days gone by
it's seemed like yesterday before it washed away

Hey don't wait for me there, just find your own way
Hey don't wait for me there, I'll be there soon enough

A widows life ticks out like clock work
A thousand tears she's cried a hundred times before
But now that he is gone, she's ready to move on
It all just fell away, it seems like yesterday

Hey don't wait for me there, just find your own way
Hey don't wait for me there, I'll be there soon enough

I'll be there soon enough
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

int n;
int ar[N];
vector<int> order;

int eval(){
	int ret=0;
	for (int i=2;i<n;i++){
		if (ar[i]<ar[i-1]&&ar[i]<ar[i+1])
			++ret;
	}
	return ret;
}

int used[N];

void fallback(){
	for (int i=1;i<=n;i++){
		ar[i]=order[i-1];
	}
}

multiset<int> S;
multiset<int>::iterator it;

void get_assignment(int how_many){
	if (how_many*2>=n)
	{
		fallback();
		return;
	}
	for (int i=0;i<=order.size();i++){
		used[i]=ar[i]=0;
	}
	int ptr=0;
	int memo=-1;
	for (int i=2;i<=2*how_many;i+=2){
		ar[i]=order[ptr];
		used[ptr]=1;
		memo=ar[i];
		++ptr;
	}

	multiset<int> S;
	for (int i=0;i<order.size();i++){
		if (used[i]==0)
			S.insert(order[i]);
	}

	for (int i=1;i<=2*how_many+1;i+=2){
		int thold=0;
		if (i>1)
			thold=max(thold,ar[i-1]);
		if (i<2*how_many+1)
			thold=max(thold,ar[i+1]);
		int val;
		it=S.lower_bound(thold+1);
		if (it==S.end()){
			fallback();
			return ;
		}
		val=(*it);
		S.erase(it);
		ar[i]=val;
	}
	for (int i=how_many*2+2;i<=n;i++){
		it=S.begin();
		int val;
		val=(*it);
		S.erase(it);
		ar[i]=val;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		order.push_back(ar[i]);
	}
	sort(order.begin(),order.end());

	int l,r;
	l=0;
	r=n/2;
	while (l<r){
		int mid=l+r+1;
		mid/=2;
		get_assignment(mid);
		int X=eval();
		//cout<<X<<"@"<<mid<<endl;
		if (X>=mid)
			l=mid;
		else
			r=mid-1;
	}

	get_assignment(l);

	cout<<eval()<<endl;
	for (int i=1;i<=n;i++){
		if (i>1)
			cout<<" ";
		cout<<ar[i];
	}
	cout<<endl;

	//cin.get(); cin.get();
	return 0;
}