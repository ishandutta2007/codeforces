/*
Slaves
Hebrews born to serve, to the pharaoh
Heed
To his every word, live in fear
Faith
Of the unknown one, the deliverer
Wait
Something must be done, four hundred years

So let it be written
So let it be done
I'm sent here by the chosen one
So let it be written
So let it be done
To kill the first born pharaoh son
I'm creeping death

Now
Let my people go, land of goshen
Go
I will be with thee, bush of fire
Blood
Running red and strong, down the Nile
Plague
Darkness three days long, hail to fire

So let it be written
So let it be done
I'm sent here by the chosen one
So let it be written
So let it be done
To kill the first born pharaoh son
I'm creeping death

Die by my hand
I creep across the land
Killing first born man

Die by my hand
I creep across the land
Killing first born man

I
Rule the midnight air, the destroyer
Born
I shall soon be there, deadly mass
I
Creep the steps and floor, final darkness
Blood
Lamb's blood, painted door, I shall pass

So let it be written
So let it be done
I'm sent here by the chosen one
So let it be written
So let it be done
To kill the first born pharaoh son
I'm creeping death
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
const int N = 10000031;

int n,m,k;
int our[N];
int cnt[N];
int s;
int S[N];
long long ohead[N];
vector<pair<int,int> >order;
vector<int> ans;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
	{
//		cin>>our[i];
		scanf("%d",&our[i]);
		cnt[our[i]]++;
	}

	for (int i=0;i<N;i++)
	{
		s+=cnt[i];
		if(s>1ll*k*(i+1))
		{
			cout<<-1<<endl;
			return 0;
		}
		S[i]=s;
	}

	for (int i=N-1;i>=0;--i)
	{
		ohead[i]=1ll*(i+1)*k-S[i];
		if (i<N-1)
			ohead[i]=min(ohead[i],ohead[i+1]);
	}

	for (int i=1;i<=m;i++)
	{
		int val;
//		cin>>val;
		scanf("%d",&val);
		order.push_back(make_pair(val,i));
	}

	sort(order.begin(),order.end());

	for (int i=0;i<order.size();i++)
	{
		if (i>0&&order[i].first==order[i-1].first)
			continue;
		int ps=order[i].first;
		long long can_take=ohead[ps]-ans.size();
		for (int j=i;j<order.size();j++)
		{
			if (can_take==0)
				break;
			if (order[j].first!=order[i].first)
				break;
			ans.push_back(order[j].second);
			can_take--;
		}
	}

	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		if (i)
			printf(" ");
		printf("%d",ans[i]);
//		cout<<ans[i];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}