/*
When darkness falls
May it be
That we should see the light

When reaper calls
May it be
That we walk straight and right

When doubt returns
May it be
That faith shall permeate our scars

When we're seduced
Then may it be
That we not deviate our cause

All sinners, a future
All saints, a past
Beginning, the ending
Return to ash

Now that we're dead, my dear
We can be together
Now that we're dead, my dear
We can live forever

When all is pain
May it be
It's all we've ever known

When flame consumes
May it be
It warms our dying bones

When loss has won
May it be
It's you I'm madly fighting for

When Kingdom comes
May it be
We walk right through that open door

All sinners, a future
All saints, a past
Beginning, the ending
Return to ash

Now that we're dead, my dear
We can be together
Now that we're dead, my dear
We can live forever

All sinners, a future
All saints, a past
Beginning, the ending
Return to ash

Now that we're dead, my dear
We can be together
Now that we're dead, my dear
We can live, we can live forever

Return to ashes, shed this skin
Beyond the black, we rise again
We shall live forever
*/

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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

string st;
int cnt[N];
int ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>st;
	for (int i=0;i<st.size();i++)
	{
		cnt[st[i]]++;
	}
	ans=1e9;
	ans=min(ans,cnt['B']);
	ans=min(ans,cnt['u']/2);
	ans=min(ans,cnt['l']);
	ans=min(ans,cnt['b']);
	ans=min(ans,cnt['a']/2);
	ans=min(ans,cnt['s']);
	ans=min(ans,cnt['r']);
	// a ,u
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}