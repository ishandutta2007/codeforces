/*
Don't try to tell us what is right for us
We don't give a fuck anyway
Don't try to steal imagination from us
Things we believe and we will never betray, never betray

Those who have the power to
Suck us dry - throw us away
Those who never could create
Destroy the music of today

Those devoid of any feeling
Those who make the compromise
Betray themselves to make a deal
Sell their soul at any price

Sounds without feeling, energy or aggression
From money hungry brains and not from the heart
Fortune, fame and glory are their obsession
Salesmen, deaf to music, blind to art

No honesty, just sterility
A cautious sound they make without creativity
It's still the same as another age
When they took the words of truth and put them to a flame

No more
Love us or hate us
No more
Love us or hate us

Some have eyes and still can't see
Their plastic noise is anything but music to me
Mechanized and computerized
Switch off your brain and make sounds that dehumanize

No more
Love us or hate us
No more
Love us or hate us

Don't try to take our dreams away from us
We will never be like you
Love us or hate us, it doesn't matter to me
We don't want to be a part of this sick society

Those who have a passion to
Will never change our way of life
We may not think the way you do
But we know that we are right
Those who want to form a world
Of trends and monotony
Have to do it without us
'Cause we always will be free
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

long long n,t,A[N],x[N];
vector<long long> order;

long long max_a[N];

long long B[N],C[N];

int get_kth(int which,int banned){
	if (banned>which)
		return which;
	return which+1;
}

bool verify(){
	for (int i=1;i<=n;i++){
		int should_match=x[i];
		//cout<<"@"<<should_match<<" "<<A[i]<<" "<<B[should_match]<<endl;
		if (B[should_match]<A[i]+t)
			return false;
		if (should_match==n)
			continue;
		int which=get_kth(should_match,i);
		//cout<<i<<" "<<which<<"@"<<B[should_match]<<" "<<t<<" "<<A[which]<<endl;
		if (A[which]<=B[should_match]-t) // can move it
			return false;
	}
	return true;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>t;

	for (int i=1;i<=n;i++){
		cin>>A[i];
	}

	for (int i=1;i<=n;i++){
		cin>>x[i];
		order.push_back(x[i]);
	}

	// matching.
	sort(order.begin(),order.end());

	for (int i=0;i<order.size();i++){
		if (order[i]<i+1){
			cout<<"No"<<endl;
			return 0;
		}
	}

	// greedy on B

	for (int i=1;i<=n;i++){
		if (x[i]>i){
			C[i]++;
			C[x[i]]--;
		}
	}

	int cnt=0;
	for (int i=1;i<=n;i++){
		cnt+=C[i];
		if (cnt>0)
			B[i]=A[i+1]+t;
		else
			B[i]=A[i]+t;
		if (i>1)
			B[i]=max(B[i],B[i-1]+1);
	}

	if (!verify()){
		cout<<"No"<<endl;
		return 0;
	}

	cout<<"Yes"<<endl;

	for (int i=1;i<=n;i++){
		if (i>1)
			cout<<" ";
		cout<<B[i];
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}