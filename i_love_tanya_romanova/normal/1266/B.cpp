/*
Never too soon to be through
Being cool too much too soon
Too much for me too much for you
You're gonna loose in time
Every turn looking to burn
Some never learn live and learn
Stop your searching for a curse
Before you end up in a hearse
Don't be afraid to show your friends
That you hurt inside inside
Pain's part of life don't hide behind your false pride
It's a lie your lie
Don't slip away and don't forget
I'll give you more than you can get
It's so lonely when you don't even know
Yourself come to me
If you see me getting mighty
If you see me getting high
Knock me down
I'm not bigger than life
I'm tired of being untouchable
I'm not above the love
I'm part of you and you're part of me
Why did you go away
Too late to tell you how i feel
I want you back but i get real
Can you hear my falling tears
Making rain where you lay
Finding what you're looking for
Can end up being such a bore
I pray for you most every day
My love's with you now fly away
If you see me getting mighty
If you see me getting high
Knock me down
I'm not bigger than life
It's so lonely when you don't even know yourself
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

const int N = 500031;

int tests;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	long long need;
    	cin>>need;
    	long long per_cube=0;
    	for (int i=1;i<=6;i++)
    		per_cube+=i;
    	per_cube-=7;

    	if (need<=14){
    		cout<<"NO"<<endl;
    		continue;
    	}
    	long long full_cubes=(need-14)/14;
    	long long rem=need-full_cubes*14;
    	if (rem>=14+1&&rem<=14+6)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }

    //    cin.get(); cin.get();
    return 0;
}