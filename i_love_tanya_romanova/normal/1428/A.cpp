/*
Rain washes away all tracks, last life signs immersed in the floods
The water devouring civilization, humanity eliminated and swallowed by the earth

Suddenly you hear a scream, suddenly there is a voice
So you are not alone
There is some hope, there is some faith

You are running lonely through this world
You see no light, there are no shadows, no one to talk to, nobody here to help you

Suddenly you hear a scream, suddenly there is a voice
So you are not alone
There is some hope, there is some faith

A scream, a voice, some hope, some faith
A scream, a voice, some hope, some faith

Suddenly you hear a scream, suddenly there is a voice
So you are not alone
There is some hope, there is some faith

A scream, a voice, a hope, some faith
So you are not alone
You are not alone
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

int tests,x1,y1,x2,y2,ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>x1>>y1>>x2>>y2;
    	if (x1==x2||y1==y2){
    		cout<<abs(x1-x2)+abs(y1-y2)<<endl;
    	}
    	else
    	{
    		ans=abs(x1-x2)+abs(y1-y2)+2;
    		cout<<ans<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}