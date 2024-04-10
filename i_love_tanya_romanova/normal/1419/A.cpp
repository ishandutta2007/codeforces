/*
It's stranger than fiction,
How you decay
It must be so lonely,
Lost within your ways

You're born alone,
You die alone
The rest is yours
To fill the gap
The world goes on,
Without you here
The just of,
Just collapse

Is this what you wanted to be?
Alone standing by yourself
Is this all you wanted to be?
Or was that a cry for help?

By yourself
By yourself
By yourself

Verbal grenades,
You throw inane
I can't believe
You'd stoop so low
Of all the things,
You took away
I miss my mind
The most

Is this what you wanted to be?
Alone standing by yourself
Is this all you wanted to be?
Or was that a cry for help?

By yourself
By yourself
By yourself

Is this what you wanted to be?
Alone standing by yourself
Is this all you wanted to be?
Or was that a cry for help?

Is this what you wanted to be?
Alone standing by yourself
Is this all you wanted to be?
Or was that a cry for help!?

It's stranger than fiction,
How you decay
It must be so lonely,
Lost within your ways
*/

#pragma GCC optimize("O3")
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

#define bs 1000000007

const int N = 100031;

int tests;
string st;
int c[20][20];

int main() {
	//freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>st;
		cin>>st;
		for (int i=0;i<2;i++){
			for (int j=0;j<2;j++){
				c[i][j]=0;
			}
		}
		for (int i=0;i<st.size();i++){
			c[i%2][st[i]%2]++;
		}
		if (st.size()%2==1){ // odd last
			if (c[0][1])
				cout<<1<<endl;
			else
				cout<<2<<endl;
		}
		else
		{
			if (c[1][0])
				cout<<2<<endl;
			else
				cout<<1<<endl;
		}
	}
	//cin.get(); cin.get();
	return 0;
}