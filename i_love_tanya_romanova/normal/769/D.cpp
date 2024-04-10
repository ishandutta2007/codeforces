/*
Quarters for the criminally insane
The sentence read for life I must remain
The path I chose has led me to my grave
To try again I'd have no other way

Quarters for the criminally insane
Escape for me has fast become a game
Soon to be, I'll leave without a trace
Endangered species end the human race

Branded in pain
Marked criminally insane
Locked away and kept restrained
Disapprobation, but what have I done
I have yet only just begun
To take your fuckin' lives!

Night will come and I will follow
For my victims, no tomorrow
Make it fast, your time of sorrow
On his trail, I'll make you follow
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
#define BS 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 500031;

long long n,k,ans;
int pcount[N];
long long cnt[N];

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	for (int i=0;i<N;i++)
	{
		pcount[i]=pcount[i/2]+i%2;
	}

	cin>>n>>k;
	for (int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		cnt[val]++;
	}

	if (k==0)
	{
		for (int i=0;i<N;i++)
		{
			long long here=1ll*cnt[i]*(cnt[i]-1)/2;
			ans+=here;
		}
	}
	else
	{
		for (int i=0;i<=10000;i++)
		{
			for (int j=i+1;j<=10000;j++)
			{
				int here=(i^j);
				if (pcount[here]==k)
					ans+=1ll*cnt[i]*cnt[j];
			}
		}
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}