/*
Such a lonely day
And it's mine
The most loneliest day of my life

Such a lonely day
Should be banned
It's a day that I can't stand

The most loneliest day of my life
The most loneliest day of my life

Such a lonely day
Shouldn't exist
It's a day that I'll never miss
Such a lonely day
And it's mine
The most loneliest day of my life

And if you go, I wanna go with you
And if you die, I wanna die with you

Take your hand and walk away

The most loneliest day of my life
The most loneliest day of my life
The most loneliest day of my life
Life

Such a lonely day
And it's mine
It's a day that I'm glad I survived
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

int tests,n,ar[N];

int solver(){
	int mx=0;
	int cnt=0;
	for (int i=1;i<=n*2;i++){
		if (ar[i]==0)
			++cnt;
		else
			--cnt;
		mx=max(mx,cnt);
	}
	//cout<<"@"<<mx<<endl;
	return mx;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=1;i<=n*2;i++){
    		ar[i]=0;
    	}
    	for (int i=1;i<=n;i++){
    		int val;
    		cin>>val;
    		ar[val]=1;
    	}

    	int count_max=solver();
    	for (int i=1;i<=n;i++){
    		swap(ar[i],ar[n*2-i+1]);
    	}
    	int count_min=solver();
    	count_min=n-count_min;
    	//cout<<count_min<<"@"<<"  "<<count_max<<endl;
    	if (count_max>count_min)
    		cout<<0<<endl;
    	else
    		cout<<count_min-count_max+1<<endl;
    }


    //cin.get(); cin.get();
    return 0;
}