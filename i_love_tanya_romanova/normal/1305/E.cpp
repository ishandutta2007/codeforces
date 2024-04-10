/*
Another sun sets down behind me, another day comes crashing in
There's a whispering wind that's blowing, there's a storm that's closing in
I can hear the trains they're rolling to a place I've never been
And I can feel their breath beside me with an empty glass of gin
As the darkness settles in, I can hear her voice again
I can hear your voice again

Waiting for someone to save me but everyone just runs away
Waiting for someone to change me but no one ever comes
I'm breaking down the walls that cage me but nothing ever falls in place
Waiting for the end to take me, blinded by the sun

All the ghosts that live inside me always waiting in the wind
I can see through my reflection, what I've become and what I've been
You see, your Heaven doesn't want me and your Hell won't let me in
It's like I'm holding all the aces but I know I'll never win

Waiting for someone to save me but everyone just runs away
Waiting for someone to change me but no one ever comes
I'm breaking down the walls that cage me but nothing ever falls in place
Waiting for the end to take me, blinded by the sun

You can take it away, tear it all down
Spit in my face, pushed to the ground
Look what I've become!
I've fallen from grace, bloodied and bound
Taking up space, lost and I'm found!
Look what I've become!

I can hear the snakes they're winding
Singing songs of pain and sin
There's an anger overflowing
From this empty glass of gin
As the darkness settles in
And this darkness settles in

Waiting for someone to save me but everyone just runs away
Waiting for someone to change me but no one ever comes
I'm breaking down the walls that cage me but nothing ever falls in place
Waiting for the end to take me, blinded by the sun
(You can take it away!) And the darkness settled in
(You can take it away!) And the darkness settled in!

As the darkness settles in...
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

int n,need,ans[N];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    cin>>need;

    for (int i=1;i<=n;i++){
    	if (need==0){
    		ans[i]=i*16000+500000000;
    		continue;
    	}
    	int max_pairs=(i-1)/2;
    	if (need>=max_pairs){
    		ans[i]=i;
    		need-=max_pairs;
    		continue;
    	}
    	// shitty case
    	int should_cover=need*2;
    	int first_covered=i-should_cover;
    	ans[i]=ans[first_covered]+ans[i-1];
    	need=0;
    }

    if (need==0){
    	for (int i=1;i<=n;i++){
    		if (i>1)
    			cout<<" ";
    		cout<<ans[i];
    	}
    	cout<<endl;
    }
    else
    {
    	cout<<-1<<endl;
    }

    //    cin.get(); cin.get();
    return 0;
}