/*
I have no name my face a blur
I speak only to answer them
White noise becomes a voice
I hear it constantly

I dare not break the circuit
I rest only for a short time
This time I promise I won't give up

I have no right to let it go
I have no right to do so

My vision now is incomplete
I am affected by the warmth
A change of tone unusual sound
Is this the time to decline

They control the circuit
The embodiment of what I've done
If I waver from this circle
A second pass and then I'm found
But he who walks behind me
He once saw the morning sun
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

const int N = 200031;

int n;
vector<int> v;

bool solver(int val){
	for (int i=0;i<val;i++){
		int ps=v.size()-val+i;
		if (v[ps]<=i)
			return false;
	}
	return true;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=0;i<n;i++){
    	int val;
    	cin>>val;
    	v.push_back(val);
    }

    sort(v.begin(),v.end());

    int l,r;
    l=1;
    r=n;
    while (l<r){
    	int mid=l+r+1;
    	mid/=2;
    	if (solver(mid))
    		l=mid;
    	else
    		r=mid-1;
    }

    cout<<l<<endl;

//    cin.get(); cin.get();
    return 0;
}