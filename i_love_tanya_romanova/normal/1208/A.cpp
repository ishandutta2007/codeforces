/*
Sometimes I need to remember just to breathe
Sometimes I need you to stay away from me
Sometimes I'm in disbelief I didn't know
Somehow I need you to go

Don't stay
Forget our memories
Forget our possibilities
What you were changing me into
(Just give me myself back and)
Don't stay
Forget our memories
Forget our possibilities
Take all your faithlessness with you
Just give me myself back and
Don't stay

Sometimes I feel like I trusted you too well
Sometimes I just feel like screaming at myself
Sometimes I'm in disbelief I didn't know
Somehow I need to be alone

Don't stay
Forget our memories
Forget our possibilities
What you were changing me into
(Just give me myself back and)
Don't stay
Forget our memories
Forget our possibilities
Take all your faithlessness with you
Just give me myself back and
Don't stay

I don't need you anymore, I don't want to be ignored
I don't need one more day of you wasting me away
I don't need you anymore, I don't want to be ignored
I don't need one more day of you wasting me away

With no apologies

Don't stay
Forget our memories
Forget our possibilities
What you were changing me into
(Just give me myself back and)
Don't stay
Forget our memories
Forget our possibilities
Take all your faithlessness with you
Just give me myself back and
Don't stay

Don't stay

Don't stay
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

const int N = 200000;

int tests,n,a,b,f[N];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>a>>b>>n;
    	if (n%3==0){
    		cout<<a;
    	}
    	if (n%3==1){
    		cout<<b;
    	}
    	if (n%3==2){
    		cout<<(a^b);
    	}
    	cout<<endl;
    }
//    cin.get(); cin.get();
    return 0;
}