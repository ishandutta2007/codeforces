/*
Hey!
Hey ey!
Ye ah ah!
Let it out!

Hey!
Hey ey!
Yea ah ah!
Let it out!

You like to bite your own tongue.
Shouldn't keep your mind closed.
Gotta let them all know.
What your capable of.

Don't second guess your own heart.
Go with what feels right.
Gotta let them all know.
What you locked up inside.

Shouldn't hold on to things.
That won't let you move on.
Shouldn't hold yourself back.
Let yourself go.

Let it out, say what you have to say.
Cause it's not worth the wait, let it out.
And don't back down, don't turn away.
No it's not worth the wait and not worth the pain
So let it out, let it out.

Don't wanna look back and think.
You could have made things alright.
With just one simple line.
You chose to keep in your mind.

You wanna look back and say
I did the best that I could
Maybe my best wasn't enough
(But it's the thought that counts)

Shouldn't hold on to the things
That won't let you move on
Shouldn't hold yourself back,
Let yourself go and...
Let it out say what you have to say
Cause it's not worth the wait let it out
And don't back down don't turn away
No it's not worth the wait and it's not worth the pain
So let it out, let it out.

You wanna look back and say
You wanna look back and feel
I did the best that I could
I did the best that I could

You wanna look back and say
You wanna look back and feel
I am proud of
All that I have done!

Shouldn't hold on to the things
That won't let you move on
Shouldn't hold yourself back
Let yourself (go)

Let it out say what you have to say
Cause it's not worth the wait let it out.

Let it out say what you have to say
Cause it's not worth the wait let it out
And don't back down don't turn away
No it's not worth the wait and it's not worth the pain
So let it out, let it out!

Let it out say what you have to say
Cause it's not worth the wait (just) let it out (let it out)
And don't back down don't turn away
No it's not worth the wait and it's not worth the pain
So let it out, let it out!..
*/
 
//#pragma comment(linker, "/STACK:16777216")
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n,dp[1<<20][2];

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    dp[i][0]=dp[i-1][0];
    dp[i][1]=dp[i-1][1];
    dp[i][i%2]+=dp[i-1][1^(i%2)]+1;
    dp[i][0]%=bs;
    dp[i][1]%=bs;
}

cout<<(dp[n][0]+dp[n][1])%bs<<endl;

//cin.get();cin.get();
return 0;}