/*
For the love of god, will you bite your tongue
Before we make you swallow it
It's moments like this where silence is golden
(And then you speak)

No one wants to hear you
No one wants to see you
So desperate and pathetic
I'm begging you to spare me
The pleasure of your company

(When did the diamonds leave your bones?)

I'm burning down every bridge we make
I'll watch you choke on the hearts you break
I'm leaving out every word you said
Go to hell for heaven's sake

I'm burning down every bridge we make
I'll watch you choke on the hearts you break
I'm leaving out every word you said
Go to hell for heaven's sake

(Go to hell for heaven's sake)

No one wants to hear you (Save your breath)
No one wants to see you
So desperate and pathetic
You think that no one sees this
I think it's time you knew the truth

I'm burning down every bridge we make
I'll watch you choke on the hearts you break
I'm leaving out every word you said
Go to hell for heaven's sake

I'm burning down every bridge we make
I'll watch you choke on the hearts you break
I'm leaving out every word you said
Go to hell for heaven's sake

When did the diamonds leave your bones
Leave your bones

You're not a shepherd, you're just a sheep
I'll cut my depths of everyone you meet
Your own flesh with no bones
Feed them to the sharks
And throw them to the walls

I'm burning down every bridge we make
I'll watch you choke on the hearts you break
I'm leaving out every word you said
Go to hell for heaven's sake

I'm burning down every bridge we make
I'll watch you choke on the hearts you break
I'm leaving out every word you said
Go to hell for heaven's sake

Go to to hell for heaven's sake
Go to to hell for heaven's sake
Go to to hell for heaven's sake
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

const int N = 300031;

int n,ar[N],ans[N];
vector<pair<int,int> > order;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=0;i<n;i++){
		cin>>ar[i];
	}

	order.clear();
	for (int i=0;i<n;i++){
		order.push_back(make_pair(ar[i],i));
	}

	sort(order.begin(),order.end());
	for (int i=0;i<order.size();i++){
		int ps=order[i].second;
		int val=order[(i+1)%order.size()].first;
		ans[ps]=val;
	}

	for (int mask=1;mask+1<(1<<n);mask++){
		long long s1=0;
		long long s2=0;
		for (int i=0;i<n;i++){
			if (mask&(1<<i)){
				s1+=ar[i];
				s2+=ans[i];
			}
		}
		if (s1==s2){
			cout<<"SHIT"<<endl;
			while (true);
		}
	}

	for (int i=0;i<n;i++){
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}