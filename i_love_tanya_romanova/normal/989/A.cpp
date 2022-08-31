/*
I don't care for this world anymore
I just want to live my own fantasy
Fate has brought me to these shores
What was meant to be is now happening

I've found that I like this living in danger
Living on the edge it feels... it makes me feel as one
Who cares now what's right or wrong it's reality
Killing so we survive wherever we may roam
Wherever we may hide we've got to get away

I don't want existence to end
We must prepare ourselves for the elements
I just want to feel like we're strong
We don't need a code of morality

I like all the mixed emotion and anger
It brings out the animal the power you can feel
And feeling so high on this much adrenalin
Excited but scary to believe what we've become

Saints and sinners
Something within us
We are lord of the flies

Saints and sinners
Something willing us
To be lord of the flies
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1200031;

int ok=0;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	string st;
	cin>>st;
	for (int c=1;c+1<st.size();c++){
		vector<char> v;
		v.push_back(st[c-1]);
		v.push_back(st[c]);
		v.push_back(st[c+1]);
		sort(v.begin(),v.end());
		if (v[0]=='A'&&v[1]=='B'&&v[2]=='C')
			ok=1;
	}

	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

//	cin.get(); cin.get();
	return 0;
}