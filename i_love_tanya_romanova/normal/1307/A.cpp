/*
Look around,
Where do you belong
Don't be afraid,
You are not the only one

Don't let the day go by,
Don't let it end
Don't let a day go by in doubt,
The answer lies within

Life is short, so learn from your mistakes
And stand behind, the choices that you made
Face each day with both eyes open wide
And try to give, don't keep it all inside

Don't let the day go by
Don't let it end
Don't let a day go by, in doubt,
The answer lies within

You've got the future on your side
You've gonna be fine now
I know whatever you decide
You are gonna shine!!! (shinee)

Don't let the day go by
Don't let it end
Don't let a day go by, in doubt
You re ready to begin

Don't let a day go by in doubt
The answer lies within
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

const int N = 1100031;

int tests,n,d,ar[N];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>d;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	for (int i=2;i<=n;i++){
    		while (ar[i]>0&&d>=i-1){
    			ar[i]--;
    			ar[1]++;
    			d-=(i-1);
    		}
    	}
    	cout<<ar[1]<<endl;
    }

    //    cin.get(); cin.get();
    return 0;
}