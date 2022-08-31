/*
The yesterday we loved speak of tomorrow.
The burden of man is that time never takes a pause.
We live from Monday to Sunday but we forget what it means.
Then a ghost comes to visit and we tell stories from tabloids.

Call all your friends,
Watch fake photos
From a made up vacation.
Speaking in tongues about ancient artifacts.

We steal from beggars and ask for understanding
We lie, rape, steal and murder to make tonights headlines

Thanks
Nat
Trust the system,
Make your contribution,
Smile, applaud, love, hail.
The weaker you get the stronger they become.

Listen in silence,
Hear a voice.
How far are we ready to take this?

Listen in silence,
Hear a voice.
Before it all crumbles.

Lie, rape, steal and murder,
Smile, applaud, love, hail.

Gather in front of the TV.
Exploding sympathy.
The weatherman, our trust,
Our punctual company.

We steal from beggars and ask for understanding,
We lie, rape, steal and murder to make tonights headlines

Trust the system,
Make your contribution,
Smile, applaud, love, hail.
The weaker you get the stronger they become.

Listen in silence,
Hear a voice.
How far are we ready to take this?

Listen in silence,
Hear a voice.
Before it all crumbles.

Lie, rape, steal and murder, smile, applaud, love, hail.

Listen in a silence, hear a voice
How far are we ready to take this?
Listen in silence, hear a voice
Before it all crumbles
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

const int bs = 1000000007;

const long long N = 200031;

int tests,n;
long long ar[N],answ,ans[N];

long long eval(long long ps){
	if (ps>n)
		return 0;
	return ans[ps];
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	answ=0;
    	for (int i=n;i>=1;--i){
    		ans[i]=eval(i+ar[i])+ar[i];
    		answ=max(answ,ans[i]);
    	}
    	cout<<answ<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}