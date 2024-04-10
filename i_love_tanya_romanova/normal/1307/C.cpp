/*
There's a story in your eyes
I can see the hurt behind your smile
For every sign I recognize
Another one escapes me

Let me know what plagues your mind
Let me be the one to know you best
Be the one to hold you up
When you feel like you're sinking

Tell me once again
What's beneath the pain you're feeling
Don't abandon me
Or think you can't be saved

I walk beside you
Wherever you are
Whatever it takes
No matter how far
Through all that may come
And all that may go
I walk beside you
I walk beside you

Summon up your ghosts for me
Rest your tired thoughts upon my hands
Step inside this sacred place
When all your dreams seem broken

Resonate inside this temple
Let me be the one who understands
Be the one to carry you
When you can walk no further

Tell me once again
What's below the surface bleeding
If you've lost your way,
I will take you there

I walk beside you
Wherever you are
Whatever it takes
No matter how far
Through all that may come
And all that may go
I walk beside you
I walk beside you

Oh, when everything is wrong
Oh, when hopelessness surrounds you
Oh, the sun will rise again
The tide you swim against
Will carry you back home
So don't give up
Don't give in

I walk beside you
Wherever you are
Whatever it takes
No matter how far
Through all that may come
And all that may go
I walk beside you
I walk beside you
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

string st;
long long c2[1031][1031];
long long c1[1031];
long long ans;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>st;
    for (int i=0;i<st.size();i++){
    	for (int p1='a';p1<='z';p1++){
    		c2[p1][st[i]]+=c1[p1];
    	}
    	c1[st[i]]++;
    }

    for (int i='a';i<='z';i++){
    	for (int j='a';j<='z';j++){
    		ans=max(ans,c2[i][j]);
    	}
    	ans=max(ans,c1[i]);
    }

    cout<<ans<<endl;

    //    cin.get(); cin.get();
    return 0;
}