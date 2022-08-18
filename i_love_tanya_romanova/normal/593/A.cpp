/*
Pray for the days of glory
Long gone the master plan
Gone is the pride of independence
Sacrificed like a lamb

Here is the same old story
Here where the honor ran
There was a price for the consolation
Walking in hand in hand

Thy kingdom come, he came to fear it
He's on the Judas list
Thy will be done and fondled spirit
Sees devils in the mist

Give a new resolution
Give what all I can
Give me some more of what I can take
Feed me from your garbage can

Let me have the absolution
Let me stand like a man
Let me walk tall with the godforsaken
Walking out hand in hand

Thy kingdom come, he came to fear it
He's on the Judas list
Thy will be done and fondled spirit
Sees devils in the mist

One more godforsaken
Tend to make him pay
A kiss from Judas and temptation
Sends him on his way

Passes on redemption
Tend to make him right
Another kiss of Judas lands
Before he sees daylight into his night

Hot

One more godforsaken
Tend to make him pray
A kiss from Judas and temptation
As I heard him pray

Thy kingdom come, he came to fear it
He's on the Jesus list
Thy will be done and ruined spirit
Sees devils in the mist

Thy will be done
Thy will be done
Thy will be done
Thy will be done
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

int n;
int ans;
string word[10000];

bool good(string st,char c1,char c2)
{
	for (int i=0;i<st.size();i++)
		 if (st[i]!=c1&&st[i]!=c2)
		 	return false;
	return true;
}

int check(char c1,char c2)
{
	int s=0;
	for (int i=1;i<=n;i++)
		if (good(word[i],c1,c2))
			s+=word[i].size();
	return s;
}
int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>word[i];
	
	for (int c1='a';c1<='z';c1++)
		for (int c2='a';c2<='z';c2++)
		{
			int cnt=check(c1,c2);
			ans=max(ans,cnt);
		}

	cout<<ans<<endl;
		
	return 0;
}