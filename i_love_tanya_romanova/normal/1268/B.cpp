/*
It's the same in every country
When you say you're leaving
Left behind the loved ones
Waiting silent in the hall
Where you're going lies adventure
others only dream of
Red and green light this is real
and so you go to war

For the passion, for the glory
For the memories, for the money
You're a soldier, for your country
What's the difference, all the same

Far away from the land of our birth
We fly a flag in some foreign earth
We sailed away like our fathers before
These colours don't run from cold bloody war

Here is no one that will save you
Going down in flames
No surrender certain death
You look it in the eye
On the shores of tyranny you

Crashed the human wave
Paying for my freedom with your
Lonely unmarked graves

For the passion, for the glory
For the memories, for the money
You're a soldier, for your country
What's the difference, all the same

Far away from the land of our birth
We fly a flag in some foreign earth
We sailed away like our fathers before
These colours don't run from cold bloody war
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

long long n,black,white;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	int val;
    	cin>>val;
    	if (i%2==1)
    		black+=val/2,
			white+=val-val/2;
    	else
    		white+=val/2,
			black+=val-val/2;
    }

    cout<<min(black,white)<<endl;

    //    cin.get(); cin.get();
    return 0;
}