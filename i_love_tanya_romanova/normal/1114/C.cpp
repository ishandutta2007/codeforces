/*
A seed is planted of a greater place
Where no wrongs shall ever be done
Where all dreams and wishes be granted
And our fears forever overcome
What can you say of limited life
Are you never satisfied?
With no uncertainty to tread
But me, Id rather be dead

At the end they promise one more chance at life
With a word, with a book, with their selfish rites
On and on await the ever burning light
Never take, never break, never leave the line
Keeping all of worth no matter what remains
When its time nothing more enough my eyes explain
Ever we endure the wisdom of mistakes
Never right, never wrong but always ours to make

If I met this maker
Id beg they listen well
To many histories gathered from this hell
Nothing could give purpose
To that Ive no desire
A prison of the soul
Eternal empire

Time irresolute will ever take its toll
Many ways, many words, each of us our own
Seeing past the veil with nothing more to learn
Given voice, given vote, I wish to not return
Service for reward the next life it can be
For this tide be here now a selfish act it seems
Rapture for oneself a greed to yet reject
Further on in my sight the universe connect

If I met this maker
Id beg they listen well
To many histories gathered from this hell
Nothing could give purpose
To that Ive no desire
A prison of the soul
Eternal empire

Pacified by a life restrained
Gone are shades that defined
Complacent the wicked friend
If this is life
I want no...

Empire, eternal empire,
I need no kingdom
Empire, eternal empire
I take the poison for the cure.

Past heavens gate, there is no escape
For the ages Ill have laid my head down
Feed me no concern, for this I have learned
Seeing forever all is mine to burn
All is mine to burn

Empire, eternal empire, I need no kingdom
Empire, eternal empire, I take the poison

If I met this maker
Id beg they listen well
To many histories gathered from this hell
Nothing could give purpose
To that Ive no desire
A prison of the soul
Eternal empire
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

long long n,b,ans;

long long eval(long long n,long long x){
	long long res=0;
	while (n){
		res+=n/x;
		n/=x;
	}
	return res;
}

vector<pair<long long, long long> > get_fact(long long x){
	vector<pair<long long, long long> > ret;
	for (long long i=2;i*i<=x;i++){
		if (x%i)
			continue;
		int cnt=0;
		while (x%i==0){
			x/=i;
			cnt++;
		}
		ret.push_back(make_pair(i,cnt));
	}
	if (x>1)
		ret.push_back(make_pair(x,1));
	return ret;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	cin>>n>>b;

	vector<pair<long long, long long> > V=get_fact(b);
	ans=2e18;

	for (int i=0;i<V.size();i++){
		long long here=eval(n,V[i].first);
		//cout<<here<<" "<<V[i].first<<endl;
		ans=min(ans,here/V[i].second);
	}
	cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}