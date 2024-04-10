/*
I'm out to mix it up and change my complexion
To coat the feelings and cure my depression
A shot of petrol is my bonafide method
To lose control and get thoroughly distracted

I'm on the money, here I come
Fuel for my engine and I'm gone

I like to forget why I feel this compulsive
As I toss tomorrow's dreams in the garbage
What's important is a mind that's sicker
Turning Jekyll into Hide much quicker

I'm on the money, here I come
Fuel for my engine and I'm gone

1, 2, 3, 4, 1, 2, 3, 4
Kick start and turn me over
Punch drunk but I'm still sober
Fourteen years and a whole lot bolder

And I don't flinch
Hungry and I'll take the best
'Cause I never wanted anything less
What doesn't kill me makes me stronger

It's like a war inside me, I'm good, I'm evil
Two sides of the coin and I've been blessed with both
On one hand I am you but I don't like you
I guess that's the nature of the way things work

I'm on the money, here I come
Fuel for my engine and I'm gone

1, 2, 3, 4, 1, 2, 3, 4
Kick start and turn me over
Punch drunk but I'm still sober
Bukowski's on my shoulder
With much to think, hungry and I'll take the best

'Cause I never wanted anything less
What doesn't kill makes me stronger
It's like a war inside me, action is all I know
Tell me it's suicide, tell me something I don't know

I don't know why I've been made some kind of hero
When I've done all I can do to prove I'm not
It's amazing to think someone could trust me
Tell me what do you know about me really?

And I you make the mistake of getting close to
Me, you'll just give me all that you've got
So I don't know why I've been made some kind of hero
When I've done all I can do to prove I'm not

1, 2, 3, 4, 1, 2, 3, 4
Kick start and turn me over
Punch drunk, but I'm still sober
Fourteen years and a whole lot bolder

And I don't flinch
Hungry and I'll take the best
'Cause I never wanted anything less
What doesn't kill me makes me stronger

1, 2, 3, 4, 1
I can't close this broken door
It's just the nature of the way things work
You wanna be me, I don't give a damn

Anyone can do it but it takes a man not to
Try so hard to give me a real life
Anyone can do it but it takes a man not to
It's just the nature of the way things work
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int n,m,pen[1<<20],banned[1<<20],line[1<<20];
vector<int> g[1<<20];
int used[1<<20];

void solve(int v)
{
	used[v]=1;
	if (pen[v])
		line[v]++;
	else
		line[v]=0;
	if (line[v]>m)
		banned[v]=1;
		
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		if (banned[v])
			banned[to]=1;
		line[to]=line[v];
		solve(to);
	}
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
	cin>>pen[i];

for (int i=1;i<n;i++)
{
	int a,b;
	cin>>a>>b;
	g[a].push_back(b);
	g[b].push_back(a);
}

solve(1);

int ans=0;

for (int i=1;i<=n;i++)
	if (i>1&&g[i].size()==1&&banned[i]==0)
		++ans;

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}