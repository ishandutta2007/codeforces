/*
The only truth I've ever heard
Is the truth I've spoken myself
A pack of lies is all I get from anybody else
Experience shows that I'm right
Deceit is the only game insight
So be careful what you choose to believe

You can't believe in nothing
Insane to trust in anything
So I don't trust in no one but myself

You can't believe in nothing
Insane to trust in anything
So I don't trust in no one but myself

What happened to your honesty
Did it take a back seat to your greed
Forgotten cause you've found out
You need to live a lie
And if you question why you have
A future without security
Just fear and lies and terror
No one can tell you why

You can't believe in nothing
Insane to trust in anything
So I don't trust in no one but myself

You can't believe in nothing
Insane to trust in anything
So I don't trust in no one but myself

Synthetic creatures ordered and numbered
Unsympathic to everyone
Death of intelligence and emotions
Preordained from death to day one

Lost trust in the future
Lost faith in prophecies
Lost truth in government promises
Lost hope for honesty

You can't believe in nothing
Insane to trust in anything
So I don't trust in no one but myself

You can't believe in nothing
Insane to trust in anything
So I don't trust in no one but myself
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1100031;

int tests;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

	cin>>tests;
	for (;tests;--tests){
		string a,b,c;
		cin>>a>>b>>c;
		int ok=1;
		for (int i=0;i<a.size();i++){
			if (a[i]==c[i]||b[i]==c[i])
				continue;
			ok=0;
		}
		if (ok)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}

    //    cin.get(); cin.get();
    return 0;
}