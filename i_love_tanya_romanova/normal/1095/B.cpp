/*
Guilty as charged
But damn it, it ain't right
There's someone else controlling me

Death in the air
Strapped in the electric chair
This can't be happening to me

Who made you God to say
"I'll take your life from you?"

Flash before my eyes
Now it's time to die
Burning in my brain
I can feel the flame

Wait for the sign
To flick the switch of death
It's the beginning of the end

Sweat, chilling cold
As I watch death unfold
Consciousness my only friend

My fingers grip with fear
What am I doing here?

Flash before my eyes
Now it's time to die
Burning in my brain
I can feel the flame

Someone help me
Oh please, God help me
They're trying to take it all away
I don't want to die

Time moving slow
The minutes seem like hours
The final curtain call I see

How true is this?
Just get it over with
If this is true, just let it be

Wakened by horrid scream
Freed from this frightening dream

Flash before my eyes
Now it's time to die
Burning in my brain
I can feel the flame
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

int n;
int ar[N];
multiset<int> S;
multiset<int>::iterator it;
int ans;

int eval(){
	it=S.begin();
	int lo=(*it);
	it=S.end();
	--it;
	int hi=(*it);
	return hi-lo;
}

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
    	S.insert(ar[i]);
    }

    ans=1e9;

    for (int i=1;i<=n;i++){
    	S.erase(S.find(ar[i]));
    	ans=min(ans,eval());
    	S.insert(ar[i]);
    }
    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}