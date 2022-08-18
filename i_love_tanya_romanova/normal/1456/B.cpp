/*
My prospects have become less promising
I find it hard to believe in anything
Seems I lost my world and so I lost my faith
And I can't go back to where I've been

A brand new day
It can't get worse
Hear myself say
It can't get worse

I have no lies or truth in what I say
There is no meaning
The words are numb and I am so afraid
There is no meaning

This is another chance or so I'm told
By those who can push themselves at any cost
They bless me with their fingers crossed
My youth is stolen, transformed and sold
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

int n,ar[N];
int pref[N];
int sum1,sum2;
int ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	pref[i]=(pref[i-1]^ar[i]);
    }

    ans=1e9;

    for (int interesting=1;interesting<n;interesting++){
    	for (int le=1;le<=50&&le<=interesting;le++){
    		for (int ri=1;ri<=50&&ri+interesting<=n;ri++){
    			sum1=(pref[interesting]^pref[interesting-le]);
    			sum2=(pref[interesting+ri]^pref[interesting]);
    			if (sum1>sum2){
    				ans=min(ans,le+ri-2);
    			}
    		}
    	}
    }

    if (ans>1e8)
    	ans=-1;

    cout<<ans<<endl;

    //cin.get(); cin.get();
    return 0;
}