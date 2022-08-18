/*
There's a light in you
That tears me down to nothing
There's an angel in your eyes
There's a hope inside
That you can make it better
You see right through my disguise

When it rains it pours
And everybody stumbles
I won't let them bring you down

I won't let you down
When the seasons change
I won't go down
I'll fight through the pain
I'll be there right by your side
I'll never let them bring you down
When the seasons change

There's a hope in me
That I will die for something
Was there fire in my eyes
All this pain inside
Will it be this way forever
I can run but I can't hide

When it rains it pours
And everybody stumbles
I won't let them bring me down

I won't let you down
When the seasons change
I won't go down
I'll fight through the pain
I'll be there right by your side
I'll never let them bring you down
When the seasons change

When the seasons change
And we're in for colder weather
Look for me on the divide

I won't let you down
When the seasons change
I won't go down
I'll fight through the pain
I'll be there right by your side
I'll never let them bring you down
I won't let you down
When the seasons change
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

const int N = 600031;

int n,k;
string st;
int del[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>k;
	cin>>st;
	for (int i=0;i<26;i++){
		for (int j=0;j<st.size();j++){
			if (st[j]==i+'a'&&k>0){
				--k;
				del[j]=1;
			}
		}
	}

	for (int i=0;i<st.size();i++){
		if (del[i]==0)
			cout<<st[i];
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}