/*
Obey
Obey
Come won't you stay
Sincere
Sincere
All ends in tears
Endure
Endure
Thoughts most impure
Concede
Concede
But both shall we bleed

Oh, Halo on fire
The midnight knows it well
Fast, is desire
Creates another hell
I fear to turn on the light
For the darkness won't go away
Fast, is desire
Turn out the light
Halo on fire

Allure
Allure
Sweetness obscure
Abide
Abide
Secrets inside
Deprive
Deprive
To feel so alive
Obey
Obey
Just don't turn away

Oh, Halo on fire
The midnight knows it well
Fast, is desire
Creates another hell
I fear to turn on the light
For the darkness won't go away
Fast, is desire
Turn out the light
Halo on fire

Prayers cannot get through
Return to sender
Unto which of you
Shall I surrender
Twisting in disguise
Dark resurrection
Lighting up the skies
Wicked perfection

Too dark to sleep
Can't slip away
Open or close
My eyes betray
Beyond the black
Come won't you stay

Hello darkness
Say goodbye
Hello darkness
Say goodbye
Hello darkness
Say goodbye
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
const int N = 1000031;

int n,m;
int cnt;
vector<int> order;
vector<pair<int,int> > LI[N];

long long fact[N];
long long ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	fact[0]=1;
	for (int i=1;i<N;i++)
	{
		fact[i]=fact[i-1]*i%bs;
	}

	scanf("%d",&n);
	scanf("%d",&m);

	for (int i=1;i<=n;i++)
	{
		scanf("%d",&cnt);
		order.clear();
		for (int j=0;j<cnt;j++)
		{
			int val;
			scanf("%d",&val);
			order.push_back(val);
		}
		sort(order.begin(),order.end());

		int cnt=1;
		for (int j=1;j<order.size();j++)
		{
			if (order[j]!=order[j-1])
			{
				LI[order[j-1]].push_back(make_pair(i,cnt));
				cnt=0;
			}
			++cnt;
		}
		LI[order.back()].push_back(make_pair(i,cnt));
	}

	sort(LI+1,LI+m+1);

	ans=1;

	int cnt=1;
	for (int i=2;i<=m;i++)
	{
		if (LI[i]!=LI[i-1])
		{
			//cout<<i<<endl;

			ans*=fact[cnt];
			ans%=bs;
			cnt=0;
		}
		++cnt;
	}
	ans*=fact[cnt];
	ans%=bs;
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}