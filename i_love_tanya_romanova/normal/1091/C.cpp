/*
All has now been broken
On streets I dare not walk
Freedom is an illusion
I build my fences high
If there was something out there
I've learned not to expect
There's a hundred million reasons
Not to care

Don't bring it
Don't bring it
Don't bring your misery down on me

Don't bring it
Don't bring it
Don't bring your misery down on me
Wear misery's crown

As always in these matters
You broke the deal of deals
And wasted what was given
To revel in your mess
I gave up all for nothing
I tried my best and failed
There's a thousand million reasons
Never to share again

This is how it all begins
This is how it all begins

Don't bring it
Don't bring it
Don't bring your misery down on me

Don't bring it
Don't bring it
Don't bring your misery down on me
Wear misery's crown

This is how it all begins

Come now
Come now
Come now

Don't bring it
Don't bring it
Don't bring your misery down on me

Don't bring it
Don't bring it
Don't bring your misery down on me
Wear misery's crown
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

int n;
vector<int> divs;

long long eval(long long n,long long d){
	long long fi=0;
	long long la=d*(n/d-1);
	fi++;
	la++;
	long long cnt=n/d;
	return (fi+la)*cnt/2;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i*i<=n;i++){
    	if (n%i)
    		continue;
    	divs.push_back(i);
    	if (n/i!=i)
    		divs.push_back(n/i);
    }

    sort(divs.begin(),divs.end());
    reverse(divs.begin(),divs.end());

    for (int i=0;i<divs.size();i++){
    	if (i)
    		cout<<" ";
    	cout<<eval(n,divs[i]);
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}