/*
I see reflections in the water
Autumn colours, summer's daughter
And as as the year is growing older
I see winter on my shoulder
I stand in the haze
Watching stormy ripples grow on my own
Never knew your needed
Till I found myself standing here alone

And in the water, such a sad face
Slowly drowning, such a sad face
If only I could change the seasons
Like a poet, I've my reasons
It started to snow in the middle of July
Wonder why
Never did understand you
My sorrow is hanging in the grey sky

In the summer days we flew to the sun
On melting wings
But the seasons changed to fast
Leave us all behind
Blind

But then the stone fell on the water
Putting end to summer's daughter
And me, I turn away remembering
All the seasons, such a sad thing
It started to rain in the middle of the sun
Winter's begun

Never did understand you
My sorrow is hanging in the grey sky

In the summer days we flew to the sun
On melting wings
But the seasons changed to fast
Leave us all behind
Blind
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

long long n,m,cnt_with[N],C[N];

long long ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;

	for (int i=0;i<m;i++){
		cnt_with[i]=n/m+(n%m>i);
	}

	cnt_with[0]--;
	cnt_with[n%m]++;

	for (int i=0;i<m;i++){
		int here=i*i%m;
		C[here]+=cnt_with[i];
	}

	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			if ((i+j)%m==0){
				ans+=1ll*C[i]*C[j];
			}
		}
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}