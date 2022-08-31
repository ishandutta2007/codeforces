/*
This morning I made the call
The one that ends it all
Hanging up, I wanted to cry
But dammit, this well's gone dry
Not for the money, not for the fame
Not for the power, just no more games
But now I'm safe in the eye of the tornado
I can't replace the lies, that let a 1000 days go
No more living trapped inside
In her way I'll surely die
In the eye of the tornado, blow me away

You'll grow to loathe my name
You'll hate me just the same
You won't need your breath
And soon you'll meet your death
Not from the years, not from the use
Not from the tears, just self abuse

Who's to say what's for me to say...be...do
Cause a big nothing it'll be for me
The land of opportunity
The golden chance for me
My future looks so bright
Now I think I've seen the light

Can't say what's on my mind
Can't do what I really feel
In this bed I made for me
Is where I sleep, I really feel
I warn you of the fate
Proven true to late
Your tongue twist perverse
Come drink now of this curse
And now I fill your brain
I spin you round again
My poison fills your head
As I tuck you into bed
You feel my fingertips
You won't forget my lips
You'll feel my cold breath
It's the kiss of death
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

int tests,n,k;
int ar[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k;
    	--k;
    	int total_jumps=0;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	for (int i=2;i<=n;i++){
    		if (ar[i]>ar[i-1])
    			++total_jumps;
    	}
    	//cout<<total_jumps<<"@"<<"@"<<k<<endl;
    	if (k==0){
    		if (total_jumps==0)
    			cout<<1<<endl;
    		else
    			cout<<-1<<endl;
    	}
    	else
    	{
    		int need=total_jumps/k+(total_jumps%k>0);
    		if (need==0)
    			++need;
    		cout<<need<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}