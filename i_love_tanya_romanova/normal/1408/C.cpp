/*
Tremble you weakings, cower in fear
I am your ruler, land, sea and air
Immense in my girth, erect I stand tall
I am nuclear murderer I am Polaris
Ready to pounce at the touch of a button
My systems locked in on military gluttons
I rule on land, air and sea
Pass judgement on humanity
Winds blow from the bowels of hell
Will we give warnings, only time will tell
Satan rears his ugly head, to spit into the wind
I spread disease like a dog
Discharge my payload a mile high
Rotten egg air of death wrestles your nostrils
Launch the Polaris, the end doesn't scare us
When will this cease
The warheads will all rust in peace
Bomb shelters filled to the brim
Survival such a silly whim
World leaders sell missiles cheap
Your stomach turns, your flesh creeps

High priests of holocaust, fire from the sea
Nuclear winter spreading disease
The day of final conflict
All pay the price
The third world war
Rapes peace, takes life
Back to the start, talk of the part
When the Earth was cold as ice
Total dismay as the sun passed away
And the days where black as night

Eradication of Earth's
Population loves Polaris
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

const int N = 200031;

int tests,n;
double l;
int ar[N];
double time_left[N],time_right[N];
vector<double> events;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>l;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	for (int i=1;i<=n;i++){
    		time_left[i]=time_left[i-1]+(ar[i]-ar[i-1])*1.0/i;
    	}
    	time_right[n+1]=0;
    	ar[n+1]=l;
    	for (int i=n;i;--i){
    		time_right[i]=time_right[i+1]+(ar[i+1]-ar[i])*1.0/(n-i+1);
    	}
    	events.clear();
    	events.push_back(0);
    	events.push_back(0);
    	for (int i=1;i<=n;i++){
    		if (time_left[i]<time_right[i]){
    			events.push_back(time_left[i]);
    		}
    		else
    		{
    			events.push_back(time_right[i]);
    		}
    	}
    	sort(events.begin(),events.end());
    	for (int i=1;i<events.size();i++){
    		l-=(events[i]-events[i-1])*i;
    	}
    	cout.precision(15);
    	//cout<<l<<"@"<<events.back()<<" "<<events.size()<<endl;
    	cout<<fixed<<events.back()+l/events.size()<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}