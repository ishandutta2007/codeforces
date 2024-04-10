/*
Follow me, I'll lead the way; your fears will soon overtake
Hide your infinite tears inside, it seeks your smallest break
Screaming as if nothing helps, you press on to survive
Playing out the fantasies of a force that keeps you alive

He'll have you down on your knees
You play his fatal game
He'll satisfy your every need
You'll never be the same

Take my hand, I'll show you how;
You've just one life to live
The road you're on goes straight to hell;
Your life is yours to give
His fantasies of all of you are much too great to see
This world your living is so unreal, perfected just for me

He'll have you down on your knees
You play his fatal game
He'll satisfy your every need
You'll never be the same
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

int n,a[N];
vector<pair<int,int> > ans;
int used[N];

vector<pair<int,int> > order;

void dfs(int v)
{
	used[v]=1;
	for (int ii=0;ii<n;ii++)
	{
		int i=order[ii].second;
		if (used[i])
			continue;
		if (a[v]==0)
			continue;
		a[v]--;
		ans.push_back(make_pair(v,i));
		dfs(i);
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		order.push_back(make_pair(a[i],i));
	}

	sort(order.begin(),order.end());
	reverse(order.begin(),order.end());

	dfs(1);

	if (ans.size()+1!=n)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<ans.size()<<endl;
		for (int i=0;i<ans.size();i++)
		{
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}

	cin.get(); cin.get();
	return 0;
}