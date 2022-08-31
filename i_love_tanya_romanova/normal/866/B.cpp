/*
Here's a new dance craze that's sweeping the nation
It's called the toxic waltz and it's causing devastation
You're jumping up and down like a psycho circus clown
Slamming with waltzers all the way around
You get caught up in the whip
You're thrown into a flip
You aim for someone's head
To stain the floor red
Give someone a kick
To prove you're truly sick
Bounce back from some blows
And blood runs out your nose

Flailing round and round
And you're injury bound
Waltz it up!
The pit is it!
You can take your chance
On this rough new dance
If you dare!
To dive in!
There are some that try
But they won't survive
They don't hit!
'Cause they're wimps!
And this exercise
Helps you brutalize
With us!
Exodus!

Everybody's doin' the toxic waltz
Kick your friend in the head and have a ball
Come on and do the toxic waltz
And slam your partner against the wall
Everybody's doin' the toxic waltz
Good friendly violent fun in store for all
Get up off your ass and toxic waltz
If you hit the floor you can always crawl!

Used to do the monkey, but now it's not cool
The twist and mash potato are no exception to the rule
So don't be a dunce and dance like a runt
Just throw your elbows with good friendly violent fun
Don't start to cry
If you get a black eye
Just dive back in
And give another try
But too much action
May leave you in traction
So you better get insurance
No matter your endurance!

Flailing round and round
And you're injury bound
Waltz it up!
The pit is it!
You can take your chance
On this rough new dance
If you dare!
To dive in!
There are some that try
But they won't survive
They don't hit!
'Cause they're wimps!
And this exercise
Helps you brutalize
With us!
Exodus!

Everybody's doin' the toxic waltz
Kick your friend in the head and have a ball
Come on and do the toxic waltz
And slam your partner against the wall
Everybody's doin' the toxic waltz
Good friendly violent fun in store for all
Get up off your ass and toxic waltz
If you hit the floor you can always crawl!

Get up on your feet
Don't look so obsolete
And thrash like an athlete!
Don't sit there on your ass
Don't look like you've got too much class
You'll be harassed!
You know we guarantee
This is the key
So rage or get the third degree!
You begin frontal assaults
And start your somersaults
And do the toxic waltz!
Do the toxic waltz!
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

int n;
long long S,a[N],b[N],s[N];
long long total_score,total_size,total_with_a;
long long ans;

vector<pair<long long, long long> > segs;

long long total_pitzas;

long long eval(long long pitz_type_a){
	long long max_a=pitz_type_a*S;
	long long min_a=total_size-(1ll*(total_pitzas-pitz_type_a)*S);
	if (min_a<0)
		min_a=0;
	long long fi,se,th;
	fi=min_a;
	se=max_a-min_a;
	th=total_size-max_a;

	//cout<<fi<<" "<<se<<" "<<th<<endl;

	/*for (int i=0;i<segs.size();i++)
	{
		cout<<segs[i].first<<" "<<segs[i].second<<endl;
	}
*/
	long long score=0;
	for (int i=0;i<segs.size();i++){
		int id=segs[i].second;
		long long am=s[id];
		while (am>0){
	//		cout<<i<<" "<<am<<" "<<fi<<" "<<se<<" "<<th<<endl;

			if (fi>0){
				long long take=min(fi,am);
				score+=a[id]*take;
				am-=take;
				fi-=take;
				continue;
			}
			if (se>0){
				long long take=min(se,am);
				score+=max(a[id],b[id])*take;
				am-=take;
				se-=take;
				continue;
			}
			if (th>0){
				long long take=min(th,am);
				score+=b[id]*take;
				am-=take;
				th-=take;
			}
		}
	}
	return score;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>S;

	for (int i=1;i<=n;i++){
		cin>>s[i]>>a[i]>>b[i];
		total_size+=s[i];
		segs.push_back(make_pair(a[i]-b[i],i));
	}

	sort(segs.begin(),segs.end());

	reverse(segs.begin(),segs.end());

	total_pitzas=total_size/S+(total_size%S>0);

	long long l,r;
	l=0;
	r=total_pitzas;

	while (l+3<r){
		long long mid1=l*2+r;
		long long mid2=l+r*2;
		mid1/=3;
		mid2/=3;
		if (eval(mid1)<eval(mid2))
			l=mid1;
		else
			r=mid2;
	}

	for (long long x=l;x<=r;x++)
		ans=max(ans,eval(x));

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}