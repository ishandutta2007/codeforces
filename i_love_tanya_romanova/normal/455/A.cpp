/*
I met a man locked away
For things, he hadn't done
Innocence on a ball and chain
He'll never feel the sun

Again on his face
Roses in his hands
But when he smiled at me
I could understand

If you're free you'll never see the walls
If you're head is clear you'll never freefall
If you're right you'll never fear the wrong
If you're head is high you'll never fear at all

There was a daughter of a man
Who took his life too young
She swore, she'd never do those things
Then did just what he'd done

And a boy whose gone insane
Heard voices in his head
No one knows, what they say
Now his mothers dead

If you're free you'll never see the walls
If you're head is clear you'll never freefall
If you're right you'll never fear the wrong
If you're head is high you'll never fear at all

There was a man who had a face
It looked a lot like me
I saw him in the mirror
And I followed him in the street

Then when he turned away
I shot him in the head
And then I came to realize
I had killed myself

If you're free you'll never see the walls
If you're head is clear you'll never freefall
If you're right you'll never fear the wrong
If you're head is high you'll never fear
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long long n,q,calc[200000];
long long answ,dp[200000];
long long pre;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 calc[q]++;
}

for (int i=1;i<=100000;i++)
{
 dp[i]=max(dp[i],dp[i-1]);
 if (i==1)pre=0;
 else pre=dp[i-2];
 dp[i]=max(dp[i],pre+1ll*calc[i]*i);
}

answ=0;
for (int i=1;i<=100000;i++)
 answ=max(answ,dp[i]);

cout<<answ<<endl;

cin.get();cin.get();
return 0;}