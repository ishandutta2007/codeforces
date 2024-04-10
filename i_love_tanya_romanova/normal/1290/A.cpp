/*
Take a look.
Take a good long look, and tell me what you see.
Through time passing.

Make a stand.
In your way,
Leaves way... too much for me.
On the edge,
Standing.

I was there when lightning struck,
I watched the idols fall.
I could see it coming,
Could read the writing on the wall!

Time. Time after time.
The end of the line.
We stand and watch it fade away...
Sign of the time's the end of the line.

It's your move.
So play... it right.
Sometimes you get just one chance.
Superstitious.
No!
If I had the time I still wouldn't dance.

I was there when lightning struck,
And yes I kept my head.
I could feel them coming,
Could feel the living dead!!! Dead! Dead!!!

Save your breath,
Don't pray for me, pray for yourself.
Through time, keeling.

It's the end.
It snuck up...
Quick and took you by surprise.
The waiting's over.

I was there when lightning struck,
I watched the idols crawl.
It was the second coming.
It was written on the wall!
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

int tests,n,m,k,ar[N];
int ans;
int cost[N];
int bad;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m>>k;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	k=min(k,m-1);
    	bad=m-1-k;

    	ans=0;
    	for (int i=0;i<m;i++){
    		int taken_left=i;
    		int taken_right=m-i-1;
    		cost[i]=max(ar[1+taken_left],ar[n-taken_right]);
    	}

    	for (int forced_left=0;forced_left<=k;forced_left++){
    		int L=forced_left;
    		int R=forced_left+bad;
    		int here=1e9;
    		for (int i=L;i<=R;i++){
    			here=min(here,cost[i]);
    		}
    		ans=max(ans,here);
    	}
    	cout<<ans<<endl;
    }


    //    cin.get(); cin.get();
    return 0;
}