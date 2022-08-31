/*
You get me up, then we both get down
We roll all night makin' heavy sounds
I'm all tied up on your bed
I'd rather be inside your head

Don't do this, do it like that oh yeah
You've hit the spot, give it all you got
I don't care

I'll teach you a lesson
That you won't forget
Why don't you save your breath
'Cause I'm gonna love ya' to death

I'm comin' to the point, I can't hold back
Then you ease off with your attack
You're the best I've had if you please
You never stop, you great big tease

Don't do this, do it like that oh yeah
You've hit the spot, give it all you got
I don't care

I'll teach you a lesson
That you won't forget
Why don't you save your breath
'Cause I'm gonna love ya' to death

You can take me places, I thought I'd never go
And when you turn your love on me
Baby you're the star of the show

You can take me places, I thought I'd never go
And when you turn your love on me
Baby you're the star of the show

I'll teach you a lesson
That you won't forget
Why don't you save your breath
'Cause I'm gonna love ya' to death
*/

#pragma GCC optimize("Ofast")
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

const long long bs = 1000000007;

const int N = 500031;

int tests,n,m;
string st;

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m;
    	int cntsharp=0;
    	int cntzero=0;
    	for (int i=1;i<=n;i++){
    		cin>>st;
    		for (int j=0;j<st.size();j++){
    			if (st[j]=='0')
    				cntzero++;
    			else
    				cntsharp++;
    		}
    	}
    	long long ways=pw(2,cntsharp);
    	if (cntzero==0)
    		ways=ways+bs-1;
    	ways%=bs;
    	cout<<ways<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}