/*
Captain America, are you off to fight the bad guys?
Hey, mighty Superman, can you save us from ourselves?
Hey, Mr. Universe, can you lift us up above this?
'Cause I'm just Iron Man, I'm a ghost within a shell

Take a look around
Just look around

They say the road to Hell is paved with good intentions
Why did they never mention what's real and in between?
It seems the path we're on was paved with blood and sorrow
No thought about tomorrow
Just part of the machine or so it seems
Yeah, so it seems

We're all living the dream
We're all living the dream

Hey there, Your Majesty, is there anyone above you?
It must be lonely when you're up there looking down
Hey, Lady Amnesty, there's no one that can judge you
We're all just broken toys beneath your crooked crown

Take a look around
Just look around

They say the road to Hell is paved with good intentions
Why did they never mention what's real and in between?
It seems the path we're on was paved with blood and sorrow
No thought about tomorrow
Just part of the machine or so it seems
Yeah, so it seems

We're all living the dream

Take a look around
Just look around

They say the road to Hell is paved with good intentions
Why did they never mention what's real and in between?
It seems the path we're on was paved with blood and sorrow
No thought about tomorrow
Just part of the machine or so it seems
Yeah, so it seems

We're all living the dream
We're all living the dream
We're all living the dream
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

const int N = 200031;

int tests,n,a[N],b[N];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=0;i<n;i++){
    		cin>>a[i];
    	}
    	for (int i=0;i<n;i++){
    		cin>>b[i];
    	}
    	sort(a,a+n);
    	sort(b,b+n);
    	for (int i=0;i<n;i++){
    		if (i)
    			cout<<" ";
    		cout<<a[i];
    	}
    	cout<<endl;
    	for(int i=0;i<n;i++){
    		if (i)
    			cout<<" ";
    		cout<<b[i];
    	}
    	cout<<endl;
    }
    //    cin.get(); cin.get();
    return 0;
}