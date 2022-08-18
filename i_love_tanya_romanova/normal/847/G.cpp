/*
I never claimed to be something more than me,
Your standards, I refuse to see,
I will answer only to myself,
So why don't you police someone else

The place I call home isn't there anymore,
With boards on the windows and locks on the door,
So pick up the pieces that never once fit,
Let this be the end of it

Once you held a place for me,
But now that I've left you went and gave up my seat,
Don't expect me to share your visions of life,
I'll take the my chances somewhere else

The place I call home isn't there anymore,
With boards on the windows and locks on the door,
So pick up the pieces that never once fit,
Let this be the end of it

Give me the green light to get on with my life,
Pick up the pieces then roll the fucking dice

I live in exile of you, your key no longer fits,
Because the locks on my life are new
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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300;

int n,cnt[N];
int ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string st;
		cin>>st;
		for (int j=0;j<st.size();j++)
		{
			if (st[j]=='1')
				cnt[j]++;
		}
	}
	for (int i=0;i<10;i++)
	{
		ans=max(ans,cnt[i]);
	}
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}