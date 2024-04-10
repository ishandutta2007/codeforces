/*
Beneath by breath you take
still you're gasping for air
miles and miles you move
into abyss you stare
running form the plight
mighty grip it's hold
and that hunger's hanging on
but never to the fold
with endurance
as the earth behind you burns
you can feel heat
keep your will and never turn
come on, follow closely
come on, end this slavery
come on, where you're going
any place but here
and you pray for more hope
so this will run its course
every day you move
handcuffs they lose their force
abandon all you know
so destitution hides
united in despair
still makes it harder to divide
With exhaustion
as the earth behind you melts
You can feel heat
But your need for living fails
A logical reason for being
Is quickly drifting away
People prove fiendishly greedy
Each time you try to believe
It's hard to be defiant
There's ways to kill the giant
Slaughtered by pins.
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

long long n,h,x1[N],x2[N],len[N],S[N];
int ptr;
long long ans;

long long get_between(int a,int b){
	long long res=x2[b]-x1[a];
	res-=S[b]-S[a-1];
	return res;
}

bool can_finish(int a,int b){
	long long R=get_between(a,b);
	return (R<h);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>h;

	for (int i=1;i<=n;i++){
		cin>>x1[i]>>x2[i];
		len[i]=x2[i]-x1[i];
		S[i]=S[i-1]+len[i];
	}

	ptr=1;

	for (int i=1;i<=n;i++){
		while (ptr<=n&&can_finish(i,ptr))
			++ptr;
		ans=max(ans,x2[ptr-1]+h-get_between(i,ptr-1)-x1[i]);
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}