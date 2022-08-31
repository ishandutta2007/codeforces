/*
This is so hard for me
To find the words to say
My thoughts are standing still

Captive inside of me
All emotions start to hide
And nothing's getting through

Watch me,
Fading
I'm losing
All my instincts,
falling into darkness

Tear down these walls for me
Stop me from going under
You are the only one who knows
I'm holding back

It's not too late for me,
To keep from sinking further
(I'm trying to find my way out,
Tear down these walls for me now)

So much uncertainty
I don't like this feeling
I'm sinking like a stone

Each time I try to speak
There's a voice I'm hearing
And it changes everything

Watch me,
Crawl from
The wreckage
Of my silence
Conversation
Failing

Tear down these walls for me
Stop me from going under
You are the only one who knows
I'm holding back

It's not too late for me,
To keep from sinking further
(I'm trying to find my way out,
Take down these walls)

Everytime you choose to turn away
Is it worth the price you pay?
Is there someone who will wait for you
One more time? [x2]

Watch me,
Fading
I'm losing
All my instincts,
Falling into darkness

Tear down these walls for me
Stop me from going under
You are the only one who knows
I'm holding back

It's not too late for me,
To keep from sinking further
(I'm trying to find my way out,
Tear down these walls for me now)

Tear down these walls for me
It's not too late for me
Tear down these walls for me
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

const int N = 200031;

int tests,n,x,ans,mx;
int ar[N];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>x;
    	ans=2e9;
    	mx=0;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		if (ar[i]==x)
    			ans=1;
    		mx=max(mx,ar[i]);
    	}
    	int steps=x/mx+(x%mx>0);
    	if (steps==1)
    		steps=2;
    	ans=min(ans,steps);
    	cout<<ans<<endl;
    }

    //    cin.get(); cin.get();
    return 0;
}