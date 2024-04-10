/*
Deafening
Quiet
That falls on
Blind hearts
Unspoken
Implicit
These words so

Faithless
Are the lies that
Bind us
With truth
Disclosed by silence
A fragile trust
Weathered and lost

Time may dull
But will never heal
Scars hewn by
Unspoken deception
And wordless honesty

Leaving nothing
But a broken life
A shattered lie
And all we had
Lost

Time may dull
But will never heal
Scars hewn by
Unspoken deception
And wordless honesty
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

int tests,n,p[N],c[N];

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", sttextdout);
	ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>p[i]>>c[i];
		}
		int ok=1;
		for (int i=1;i<=n;i++){
			if (p[i]-c[i]<p[i-1]-c[i-1])
				ok=0;
			if (c[i]<c[i-1])
				ok=0;
		}
		if (ok)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	// cin.get(); cin.get();
	return 0;
}