/*
Out of school, feel like a fool
Nothing you learned but the rule
Don't you forget you were the pet
No love characters in stead

Your life goes on - your death has begun
Reputable you look - but you're on the hook

Unite with your work, use tie and shirt
Just because that's what they want
The system of strings are breakin' your wings
Ignorance will build you a throne

Your life goes on - your death has begun
Reputable you look - but you're on the hook

You keep reminding yourself
That life is just life when you're active
If you expect to be paid
You have to be fuckin' attractive
You're prong on your work
No time to relax in the grass
'Cause when shit turns to gold
The poor will be born without ass

Unite with your work, dragged in the dirt
Just because that's what they want
The system you ride, the system you fight
The system will beat your life

Your life goes on - your death has begun
Reputable you look - but you're on the hook

You keep reminding yourself
That life is just life when you're active
If you expect to be paid
You have to be fuckin' attractive
You're prong on your work
No time to relax in the grass
'Cause when shit turns to gold
The poor will be born without ass.
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

int tests,n,m,r,c;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m>>r>>c;
    	cout<<max(n-r,r-1)+max(m-c,c-1)<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}