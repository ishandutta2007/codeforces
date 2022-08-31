/*
This pen
The cruelest blade
The power of
Merciless words to endear
With clinched fist clinched teeth
And burning words
I take my leave

Embers
Memories
Charred remnants
Of all that we had
The demise of all we were

Wisdom
Of futile years
Affinity
Ceasing this wintering of me
A final look
One last glance
And the burning words I take my leave

Embers
Memories
Charred remnants
Of all that we had
The demise of all we were
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

int tests,n,x;
int ar[N];
int ans;

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", sttextdout);
	ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>n>>x;
		for (int i=0;i<n;i++){
			cin>>ar[i];
		}
		sort(ar,ar+n);
		reverse(ar,ar+n);
		long long S=0;
		ans=0;
		for (int i=0;i<n;i++){
			S+=ar[i];
			if (S>=(i+1)*1ll*x)
				ans=i+1;
		}
		cout<<ans<<endl;
	}

	// cin.get(); cin.get();
	return 0;
}