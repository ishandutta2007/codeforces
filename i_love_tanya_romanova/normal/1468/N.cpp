/*
I hold my breath and check the time
One minute no collapse
If you only knew what I would do for you
One thirty breathing lapse
We're going in my voice is thin
When I tell you to remember
That no one will find you
My promise from the heart
If we part my pulse will guide you through

Be still for a moment
Everything depends upon you
If you die I will die too
Once we were heroes
But everything has changed since then
Now they recognize you too

I stay too long something's wrong
You walk out of the picture
I hold my breath and check the time
One thirty I collapse
We went in my voice was thin
When I told you to remember

I'm the evidence
You passed the test and that's so good for you
O love will you read the letters I will send to you
Will I come along
Will they let me out to take the test
O love is the score enough for me to pass the test
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

long long tests,A,B,C,am1,am3,am2,am4,am5;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>A>>B>>C;
    	cin>>am1>>am2>>am3>>am4>>am5;
    	A-=am1;
    	B-=am2;
    	C-=am3;
    	int L=min(A,am4);
    	if (L>0){
    		A-=L;
    		am4-=L;
    	}
    	L=min(B,am5);
    	if (L>0){
    		B-=L;
    		am5-=L;
    	}
    	if (am4+am5<=C&&A>=0&&B>=0&&C>=0){
    		cout<<"YES"<<endl;
    	}
    	else
    		cout<<"NO"<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}