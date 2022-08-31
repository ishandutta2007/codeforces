/*
I'm so fed up with everyone around me
(No one seems to care)
I'm just so far gone and nothing's gonna change
(I'll never be the same)

It's always do this, do that,
Everything they want to
I don't wanna live that way
Every chance they get they're always
Pushin' me away

It's never enough
No, it's never enough
No matter what I say
It's never enough
No, it's never enough
I'll never be what you want me to be

It's all so messed up and no one ever listens
(Everyone's deranged)
I'm just so fucked up and I'm never gonna change
(Wanna lay it all to waste)

They always say this, say that,
Nothing that you want to
I don't wanna live that way
Every chance they get they're always
Shovin' me aside

It's never enough
No, it's never enough
No matter what I say
It's never enough
No, it's never enough
I'll never be what you want me to be

I'm done!

In the end we're all just chalk lines on the concrete
Drawn only to be washed away
For the time that I've been given
I am what I am

I'd rather hate you
For everything you are
Than ever love you
For something you are not

I'd rather you hate me
For everything I am
Than have you love me
For something that I ain't

It's never enough
It's never enough
No matter what I say

It's never enough
No, it's never enough
No matter who I try to be

It's never enough
No, it's never enough
No matter how I try to taste

It's never enough
Never, never enough
I'll never be what you want me to be.
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
long long x;
long long fun(long long n){
	return n*(n+1)/2;
}

int main() {
	//freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		cin>>x;
		long long ans=0;
		for (long long i=1;fun(i)<=x;i=i*2+1){
			x-=fun(i);
			ans++;
		}
		cout<<ans<<endl;
	}
	//cin.get(); cin.get();
	return 0;
}