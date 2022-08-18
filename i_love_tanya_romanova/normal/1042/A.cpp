/*
Legs are tied, these hands are broken
Alone I try with words unspoken
Silent cry, a breath is frozen
With blinded eyes, I fear myself

It's burning down, it's burning high
When ashes fall, the legends rise
We burn it out a mile wide
When ashes fall, the legends rise

Throat is dry, my vision's fading
I'm paralyzed and left here waiting
Taking time, just one step forward
Won't lose my mind, I'm here to stay

It's burning down, it's burning high
When ashes fall, the legends rise
We burn it out a mile wide
When ashes fall, the legends rise

Whoa (Legends rise)
Whoa (Legends rise)

(Legends rise)

(You gonna do something about it or just stand there and bleed?)

(Legends rise)

It's burning down, it's burning high
When ashes fall, the legends rise
We burn it out a mile wide
When ashes fall, the legends rise

Whoa (Legends rise)
Whoa (Legends rise)
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

const int N = 600000;

int n,m,mx,a[N];
int ans1,ans2;

long long eval(int x){
	long long res=0;
	for (int i=1;i<=n;i++){
		res+=x-a[i];
	}
	return res;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}

	ans1=mx;
	ans2=mx+m;
	while (eval(ans1)<m)
		++ans1;

	cout<<ans1<<" "<<ans2<<endl;

//	cin.get(); cin.get();
	return 0;
}