/*
Pretty in scarlet
So pretty in scarlet

We slept a while
To turn it up and get it off our minds
I slept a while
To get it all
It seems allright
To find a place without a single life
Where is the night
We run into

Cause nothing's good I can explain
I'm falling down and caught up the rain
I turn myself into changes
The night I kissed you goodbye
Cause nothing's good I can explain
I'm falling down and caught up the rain
To turn myself into changes
Your death is over

You wanna live a life pretty in scarlet
Come on
You wanna wash it down I'm pretty in scarlet
To myself to say goodbye
You wanna live a life pretty in scarlet
Come on
You wanna wash it down I'm pretty in scarlet
To myself to say

It's ok
Doesn't count
For my place
Deeper sound
Let me dive alone
Let me dive alone

You gave me wine
To poison me and take away my time
I can hear your cry
I wonder why

Cause nothing's good I can explain
I'm falling down and caught up the rain
Cause I turn myself into changes
The night I kissed you goodbye
Cause nothing's good I can explain
I'm falling down and caught up the rain
I turn myself into changes
Your death is over

You wanna live a life pretty in scarlet
Come on
You wanna wash it down I'm pretty in scarlet
To myself to say goodbye
You wanna live a life pretty in scarlet
Come on
You wanna wash it down I'm pretty in scarlet
To myself to say goodbye

Pretty in scarlet
Pretty in scarlet
Pretty in scarlet

You wanna live a life pretty in scarlet
Come on
You wanna wash it down I'm pretty in scarlet
(2x)

Pretty
She's pretty
She's pretty
And I run, and I run, and I run, and I run away

And if you throw a stone on me
And if you need some pain to see
And if you live your lies
I will run, will run, will run, run away

And if you throw a stone on me
And if you need some pain to see
And if you live your lies
I will run
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
#define bsize 512
#define MAG 1000

using namespace std;

int n,a,b;
vector<pair<int, int> > order[1<<15];
vector<int> ans;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
//	cin>>a>>b;
	scanf("%d %d",&a,&b);
	order[a/MAG].push_back(make_pair(b,i));
}
for (int i=0;i<=1000000/MAG+31;i++)
{
	sort(order[i].begin(),order[i].end());
	if (i%2)
		reverse(order[i].begin(),order[i].end());
	for (int j=0;j<order[i].size();j++)
	{
		ans.push_back(order[i][j].second);
	}
}

for (int i=0;i<ans.size();i++)
{
	if (i)
		printf(" ");
	printf("%d",ans[i]);
}
cout<<endl;

//cin.get();cin.get();
return 0;}