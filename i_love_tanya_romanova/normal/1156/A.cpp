/*
I wanna be your misery
I wanna be the world you fear
I wanna be your emptiness
I wanna be the god who kills
I wanna be the christ who dies
Upon the fires
Of infamy
Can't you see it
Can you feel it

Until you call on the dark

Can't you see it now
How black your future will be
And every emissary that I send you
Will bleed

I wanna be your misery
I wanna be the world you fear
I wanna be the christ who dies
Upon the fires
Of infamy
Can you see it
Can't you feel it

Until you call on the dark
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
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 610031;

int n,ar[N],ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    for (int i=2;i<=n;i++){
    	if (ar[i]==1){
    		if (ar[i-1]==2)
    			ans+=3;
    		else
    			ans+=4;
    		continue;
    	}
    	if (ar[i]+ar[i-1]==5){
    		ans+=1234567;
    		continue;
    	}
    	if (ar[i]==2)
    		ans+=3;
    	else
    		ans+=4;
    }

    for (int i=1;i+2<=n;i++){
    	if (ar[i]==3&&ar[i+1]==1&&ar[i+2]==2)
    		--ans; // this one at least makes sense.
    }

    if (ans>123456)
    	cout<<"Infinite"<<endl;
    else
    {
    	cout<<"Finite"<<endl;
    	cout<<ans<<endl;
    }

//    cin.get(); cin.get();
    return 0;
}