/*
Like a new day rising
Like a calm before the storm
Like fog lifting from valleys
On a sleeping forest floor
Eyes open slowly as the dust is shaken off
To gaze upon the wreckage
That the midnight hands have wrought

And now I
I feel my temperature rising
My body explode
I feel like somebody's watching
Like I'm not alone
I stopped, I vowed right then and said that

Whatever path you take (the path you take)
Wherever you might go (where you may go)
Whenever you decide to leave
I'll follow
I'll follow

We face a crossroad never knowing what's in store
There's an angel on my shoulder
There's a devil at my door
She proclaimed, "Tonight
Will be the greatest of our lives"
And I said, "Don't be so sure
Let's just wait until the morning light"

I feel my temperature rising
My body explode
I feel like somebody's watching
Like I'm not alone
I stopped, I vowed right then and said that

Whatever path you take (the path you take)
Wherever you might go (where you may go)
Whenever you decide to leave
I'll follow
I'll follow

There in the clearing
We gathered close
Under the moon's pale light
We lay out the tools
"You don't have to do this
But I forgive you if you don't"
She just looked away
And said, "I know"

Gripped by the midnight hands
We cradle futures
They would prevent
Gripped by the midnight hands

The line's crossed over
The dawn grows closer
Let's bite off too much
Let's jump with a blind trust
In water over our heads

Whatever path you take
And wherever you might go
And whenever you decide to leave
I'll follow
I'll follow

I won't bet on the falls you take (the falls you take)
I won't let go if you started to stray
I'll be there until you don't wake up, yeah
I'll follow
I will follow
I will follow

Whatever path you take (I will follow)
Wherever you might go (I will follow)
Whenever you decide to leave (I will follow)
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,p[N],b[N],cycles;
int used[N];

void dfs(int v)
{
	if (used[v])
		return ;used[v]=1;
	dfs(p[v]);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>p[i];
	}

	for (int i=1;i<=n;i++)
	{
		cin>>b[i];
	}

	for (int i=1;i<=n;i++)
	{	if (used[i])
			continue;
		dfs(i);
		++cycles;
	}

	if (cycles==1)
		cycles=0;

	int s=0;

	for (int i=1;i<=n;i++)
		s+=b[i];
	s%=2;
	if (s==0)
		++cycles;
	cout<<cycles<<endl;

	cin.get(); cin.get();
	return 0;
}