/*
Do you like it heavy
Do you love it mean
Do you want it dirty
We don't play it clean

Standing in the spotlight
Ceiling to the floor
I can see you rockin'
Let me hear you roar

Turn it up
Tear it down
Hammering through
Can you feel the sound

Any day, Any night
Midnight madness
Dynamite

If you want it
Come and get it
Do you want it
Come and get it

Can you feel the power
Blinded by the light
Keep on goin' crazy
Burnin' up the night

Shouting out together
Boiling like the sun
Metal lives forever
Blazing on and on

Turn it up
Tear it down
Hammering through
Can you feel the sound

Any day, Any night
Midnight madness
Dynamite

If you want it
Come and get it
Do you want it
Come and get it

Do you like it heavy
Do you love it loud

If you want it
Come and get it
Do you want it
Come and get it
*/

#pragma GCC optimize("Ofast")
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

const long long bs = 1000000007;

const int N = 100031;

int tests,n,already_there[N],ar[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	bool has_negative=0;
    	for (int i=0;i<=100;i++){
    		already_there[i]=0;
    	}
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		if (ar[i]>0)
    			already_there[ar[i]]=1;
    		if (ar[i]<0)
    			has_negative=1;
    	}
    	for (int i=1;i<=200;i++){
    		if (already_there[i]==0){
    			ar[n+1]=i;
    			++n;
    		}
    	}
    	if (has_negative){
    		cout<<"NO"<<endl;
    		continue;
    	}
    	cout<<"YES"<<endl;
    	cout<<n<<endl;
    	for (int i=1;i<=n;i++){
    		if (i>1)
    			cout<<" ";
    		cout<<ar[i];
    	}
    	cout<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}