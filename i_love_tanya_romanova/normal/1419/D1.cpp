/*
No one gets left behind, another fallen soul
No one gets left behind, another broken home
No one gets left behind, we stand and fight together
No one gets left behind, or we all die alone

Politicians bathing their greed
No idea how to be all they can be

Have you no honor? Have you no soul?
What is it your dying for? do you really even know?
Have you no backbone? Have you no spine?
Whatever happened to No one gets left behind

No one gets left behind, I know you made it up
No one gets left behind, It's war for money
No one gets left behind, Drink from the golden cup
No one gets left behind, Your time is coming

Play your wargames with other people's lives
It should be you on the front line

Have you no honor? Have you no soul?
What is it your dying for? do you really even know?
Have you no backbone? Have you no spine?
Whatever happened to No one gets left behind
No one gets left behind, I know you made it up
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

	while (ptr<order.size()&&order[ptr]==memo)
		++ptr;

	/*cout<<how_many<<endl;
	for (int i=1;i<=n;i++){
		cout<<ar[i]<<" ";
	}
	cout<<ptr<<endl;*/
	for (int i=2*how_many+1;i>=1;i-=2){
		if (ptr==order.size()){
			fallback();
			return;
		}
		ar[i]=order[ptr];
		used[ptr]=1;
		++ptr;
	}
	/*for (int i=1;i<=n;i++){
		cout<<ar[i]<<" ";
	}
	cout<<" at"<<how_many<<endl;
	*/
	ptr=0;
	for (int i=how_many*2+2;i<=n;i++){
		while (used[ptr])
			++ptr;
		ar[i]=order[ptr];
		used[ptr]=1;
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