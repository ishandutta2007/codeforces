/*
Ascending from your fallen past
Life it's the same
Attending to a loneliness
For you, never

Through channels of uncertainty
A rise of denial
This sadness is positioning
As fortunes snares lay me down

In a dream despite
The air we breathe, serenity

Grip the dead hands of the last
Detritus invades
Indefinite the consequence
For you endeavour to
Aggravate uncertainty
A rise of denial
This passion wont forgive
And ill fortune tears you down

All that's been ignites
Suppressing me, serenity
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

const int N = 600031;

int tests,n,k;
int h[N];
int shit;
int le[N],ri[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k;
    	for (int i=1;i<=n;i++){
    		cin>>h[i];
    	}
    	le[1]=ri[1]=h[1];
    	shit=0;
    	for (int i=2;i<=n;i++){

    		int nle,nri;

    		nle=le[i-1]-k+1;
    		nri=ri[i-1]+k-1;
    		nle=max(nle,h[i]);
    		nri=min(nri,h[i]+k-1);
    		if (i==n)
    			nri=min(nri,h[i]);
    		if (nle>nri){
    			shit=1;
    		}
    		else
    		{
    			le[i]=nle;
    			ri[i]=nri;
    		}
    	}
    	if (shit){
    		cout<<"NO"<<endl;
    	}
    	else
    	{
    		cout<<"YES"<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}