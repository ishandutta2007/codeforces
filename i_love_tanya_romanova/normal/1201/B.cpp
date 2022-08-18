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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int n;
long long S;
vector<int> v;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=0;i<n;i++){
    	int val;
    	cin>>val;
    	v.push_back(val);
    	S+=val;
    }

    sort(v.begin(),v.end());

    if (S%2){
    	cout<<"NO"<<endl;
    }
    else if (v.back()>S-v.back())
    	cout<<"NO"<<endl;
    else
    	cout<<"YES"<<endl;

//    cin.get(); cin.get();
    return 0;
}