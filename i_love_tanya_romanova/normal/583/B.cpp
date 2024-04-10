/*
I don't know why
All the fiction of your sleeping
Doesn't visit you awake
I don't know how to get your storybook sunrise
To follow you above your cloudy day
All these gifts you left on you
With heaven painted on you
I wish this now with all my soul

May all your visions turn to gold
To have and hold
May all your visions turn to gold
May all your visions turn to gold
To have and hold
May all your visions turn to gold

Terrified the world will never turn to look at you
And the sun won't see you shine
Sure as life, a rose could burst just from your smiling
Let the water form a cry
Only better luck should greet you
The road should rise to meet you
I wish this now with all i know

May all your visions turn to gold
To have and hold
May all your visions turn to gold
May all your visions turn to gold
To have and hold
May all your visions turn to gold

Loose inside your winter
Feel the cold wind blowing
Cutting through your head and your ears
Feel the fire growing
No more frozen danger
No more wrteched ice storm of fear

May all your visions turn to gold
To have and hold
May all your visions turn to gold
May all your visions turn to gold
To have and hold
May all your visions turn to gold
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

const int N = 1200000;

using namespace std;

int n,ar[N],have;
int ans;
int used[N];

int main(){
//	freopen("path2.in","r",stdin);
//	freopen("path2.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>ar[i];
	
	while (true)
	{
		for (int i=1;i<=n;i++)
			if (ar[i]<=have&&used[i]==0)
			{
				have++;
				used[i]=1;
			}
		if (have<n)++ans;
		for (int i=n;i;--i)
		{
			if (ar[i]<=have&&used[i]==0)
			{
				have++;
				used[i]=1;
			}
		}
		if (have<n)
			++ans;
		else
			break;
	}
	
	cout<<ans<<endl;
	
	return 0;
}