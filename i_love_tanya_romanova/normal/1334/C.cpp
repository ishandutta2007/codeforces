/*
Indifference
The stale sound of apathy
Twelve months
And we thin to nothing

We choke
On bitter words
We would never say
This span of autumns
Brought no change

Apparitions
Hollow voice
Ghost of us
Twelve months and
How frail this autumn leaves

I choke
On bitter words
I would never say
This span of autumns
Never changed
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

const int N = 500031;

int tests;
int n;
long long a[N],b[N],ar2[N];

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", sttextdout);
	ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>n;
		for (int i=0;i<n;i++){
			cin>>a[i]>>b[i];
		}
		for (int i=0;i<n;i++){
			ar2[i]=a[i]-b[(i+n-1)%n];
			if (ar2[i]<0)
				ar2[i]=0;
		}

		long long total_shots=0;
		for (int i=0;i<n;i++){
			total_shots+=ar2[i];
		}
		long long ans=1e18;
		for (int i=0;i<n;i++){
			long long here=total_shots-ar2[i]+a[i];
			ans=min(ans,here);
		}
		cout<<ans<<endl;
	}

	// cin.get(); cin.get();
	return 0;
}