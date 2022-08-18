/*
Burning hatred
Turning colder
Where blood boils to extinguish fear
Turn around, you're not welcome here

For all the torment I've spread
I've chosen you, even though you're reeking with fear
Turn around, you're not welcome here

When blood breeds joy,
Your kind devouring the dying dead. When blood breeds joy,
Cutting every inch of their sickened skin
When blood breeds joy,
The greedy become the elders

When blood breeds joy,
In here lies the dread

Pain

Even though the tides will turn
Events will come and people will burn
To all the tyrants and people like you
These words will echo through

In numbers you're unbearable
Thrown together by a lust for deceit. Digesting the innocent
Before the lies turn into a feast

When blood breeds joy,
Your kind devouring the dying dead. When blood breeds joy,
Cutting every inch of their sickened skin
When blood breeds joy,
The greedy become the elders

When blood breeds joy,
In here lies the dread

Pain

Like in a void, you feel nothing
Constructed to stand yourself

Even though the tides will turn
Events will come and people will burn
To all the tyrants and people like you
Someday these words will echo through

In here lies the dread
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

const int N = 400000;

using namespace std;

int n,ar[N],ps[N],ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
		ps[ar[i]]=i;
	}
	
	for (int i=1;i<=n;i++)
		if (i==1||ps[i]<ps[i-1])
		{
			int cnt=1;
			for (int j=i+1;j<=n;j++)
			{
				if (ps[j]<ps[j-1])
					break;
				++cnt;
			}
			ans=max(ans,cnt);
		}
	cout<<n-ans<<endl;
	
	return 0;
}