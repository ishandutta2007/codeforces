/*
It has been many years since I was thrown into the cell
My sentence was electrocution when the gavel fell
The clock is slowly getting closer to that final time
Strapped into the chair and punished for false crimes

My last meal is getting colder
But I have no appetite
I look down the hall at the impending doom
That waits for me this very night
My last rites are read by the pastor
As if I had rights from the start
I'm moments away before they strap me in
And voltage will flow through my heart

The warden straps me in
Flashes me a twisted grin
No last words for me to say
I know my life will end
For something that I never did
Death is just a switch away

A victim's family cheers
A killer has been free for years
I'm punished for another's crimes
My time is finally up
I guess I'm just a victim
of the wrong place at the wrong time

The Ripper runs wild through the streets
While I sit here inside a cell
A judicial system's deadly mistake
A psychopath out free to kill
Poor lawyers and poor evidence
And witnesses appeared and lied
These fools will take years to see their mistakes
And I will be long gone and fried

Mental Shock
All appeals denied
Mental Shock
It's me they want to die
Mental Shock
Nothing lasts forever
Mental Shock
Until they pull the lever

The current shoots through as I begin to convulse
A fate that should be for somebody else
Electrified brain shoots straight through the eyes
And justice is served while innocence dies
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

int tests,n,m;
int w[N];
int cycles,ans;

int get (int x){
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

void merge(int a,int b){
	a=get(a);
	b=get(b);
	if (a==b)
		++cycles;
	w[a]=b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m;
    	for (int i=1;i<=n;i++){
    		w[i]=i;
    	}
    	cycles=0;
    	ans=0;
    	for (int i=1;i<=m;i++){
    		int a,b;
    		cin>>a>>b;
    		if (a==b)
    			continue;
    		merge(a,b);
    		++ans;
    	}
    	cout<<ans+cycles<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}