/*
Late at night all systems go
You have come to see the show
We do our best You're the rest
You make it real you know
There is a feeling deep inside
That drives you fuckin' mad
A feeling of a hammerhead
You need it oh so bad

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
Whiplash

Bang your head against the stage
Like you never did before
Make it ring Make it bleed
Make it really sore
In a frenzied madness
with your leather and your spikes
Heads are bobbing all around
It is hot as hell tonight

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
Whiplash

Here on the stage the Marshal noise
is piercing through your ears
It kicks your ass kick your face
Exploding feeling nears
Now is the time to let it rip
To let it fuckin' loose
We are gathered here to be with you
Cause this is what we choose

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
Whiplash

The show is through the metal is gone
It is time to hit the road
Another town Another gig
Again we will explode
Hotel rooms and motorways
Life out here is raw
But we will never stop
We will never quit
cause we are Metallica

Adrenaline starts to flow
You're thrashing all around
Acting like a maniac
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

int tests;
long long cost[N],dist[100][100],x,y;
long long DI;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>x>>y;
    	for (int i=1;i<=6;i++){
    		cin>>cost[i];
    	}
    	for (int i=0;i<=20;i++){
    		for (int j=0;j<=20;j++){
    			dist[i][j]=1e18;
    		}
    	}
    	dist[10][10]=0;
    	for (int iter=1;iter<=15;iter++){
    		for (int i=1;i<=20;i++){
    			for (int j=1;j<=20;j++){
    				if (dist[i][j]>1e15)
    					continue;
    				dist[i+1][j+1]=min(dist[i+1][j+1],dist[i][j]+cost[1]);
    				dist[i][j+1]=min(dist[i][j+1],dist[i][j]+cost[2]);
    				dist[i-1][j]=min(dist[i-1][j],dist[i][j]+cost[3]);
    				dist[i-1][j-1]=min(dist[i-1][j-1],dist[i][j]+cost[4]);
    				dist[i][j-1]=min(dist[i][j-1],dist[i][j]+cost[5]);
    				dist[i+1][j]=min(dist[i+1][j],dist[i][j]+cost[6]);
    			}
    		}
    	}
    	long long ans=0;
    	if (x>0&&y>0){
    		DI=min(x,y);
    		ans+=DI*dist[11][11];
    		x-=DI;
    		y-=DI;
    	}
    	if (x<0&&y<0){
    		DI=min(abs(x),abs(y));
    		x+=DI;
    		y+=DI;
    		ans+=DI*dist[9][9];
    	}
    	if (x>0){
    		ans+=x*dist[11][10];
    		x=0;
    	}
    	if (x<0){
    		ans+=(-x)*dist[9][10];
    		x=0;
    	}
    	if (y>0){
    		ans+=y*dist[10][11];
    		y=0;
    	}
    	if (y<0){
    		ans+=(-y)*dist[10][9];
    		y=0;
    	}
    	cout<<ans<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}