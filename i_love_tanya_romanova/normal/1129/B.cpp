/*
Somebody give me some light
And not punch in the dark
Somebody show me the end
And I try to push a start
I'm trying to figure out
A better way, a better answer
But I keep finding all the problems
I've been looking after

You can't wander through the world
With nothing but a smile
I'll take your tongue for words
And use it to instill denial
Don't get close
You don't know me
And you'll never know
Chivalry, will get you somewhere
Rivalry, will take you there

Don't get close
You don't know me
And you'll never know
Chivalry, will get you somewhere
Rivalry, will take you there
Maybe I should look away
Before I really miss
Maybe I should pick the time
Before I pick the place
I bet you all the things
That you emulate, you penalize
But I don't wanna go
Before you learn to finalize

Don't get close
You don't know me
And you'll never know
Chivalry, will get you somewhere
Rivalry, will take you there
Don't get close
You don't know me
And you'll never know
Chivalry, will get you somewhere
Rivalry

You assist the plot
My vision's overshot
I have the best confection
I was gone for all the lessons
Who coined these words I use
Stay out and be abused
I didn't want to be
The undeniable source of everything

Don't get close
Don't get close
Don't get close
Don't get close
Don't get close
You'd better stay away
Don't get close
You'd better stay away
Don't get close
You'd better stay away
Don't get close
You'd better stay away

Need change, watching all the conflicts
Constrict, push the fist in, squeeze it
I can not resist, claws and fist
Remember, remember
You take the rivalries
And never make much sense
I have the worst possession
What I want is so insensitive
Stay out and be abused
Cause this is so confused
I only want to be
Left alone, and rot away

Don't get close
Don't get close
Don't get close
Don't get close
Don't get close
You'd better stay away
Don't get close
You'd better stay away
Don't get close
You'd better stay away
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

const int N = 210031;

int sum,k;

int n,ar[N];
int S;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>k;
    // her answer : last
    // my answer : sum * n
    // sum*n-last=k
    // sum < last

    sum=1;
    while (sum*2000-k<=sum){
    	++sum;
    }

    n=2000;
    ar[n]=sum*2000-k;

    sum-=ar[n];
    for (int i=n-1;i>=1;--i){
    	int here=max(sum,-1000000);
    	ar[i]=here;
    	sum-=here;
    }

    cout<<n<<endl;

    for (int i=1;i<=n;i++){
    	if (i>1)
    		cout<<" ";
    	cout<<ar[i];
    	S+=ar[i];
    }

    cout<<endl;

    //cout<<S*n<<" "<<ar[n]<<" "<<S*n-ar[n]<<endl;

//    cin.get(); cin.get();
    return 0;
}