/*
The sky is red, I don't understand,
past midnight I still see the land.
People are sayin' the woman is damned,
she makes you burn with a wave of her hand.
The city's a blaze, the town's on fire.
The woman's flames are reaching higher.
We were fools, we called her liar.
All I hear is "Burn!"

I didn't believe she was devil's sperm.
She said, "Curse you all, you'll never learn!
When I leave there's no return."
The people laughed till she said, "Burn!"
Warning came, no one cared.
Earth was shakin', we stood and stared.
When it came no one was spared.
Still I hear "Burn!"

You know we had no time,
we could not even try.
You know we had no time.

You know we had no time,
we could not even try.
You know we had no time.

The sky is red, I don't understand,
past midnight I still see the land.
People are sayin' the woman is damned,
she makes you burn with a wave of her hand.
Warning came, no one cared.
Earth was shakin, we stood and stared.
When it came no one was spared.
Still I hear "Burn!"
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

const int N = 200031;

int n;
vector<pair<int,vector<int> > > cand;
string st;
int already_solved[N];
vector<pair<int,int> > ans;
int is_used[N];

int count_vertices(vector<int> v){
	int cnt=0;
	for (int i=0;i<v.size();i++)
	{
		if (!is_used[v[i]])
			++cnt;
	}
	return cnt;
}

int get_unused_vertex(vector<int> v){
	for (int i=0;i<v.size();i++)
	{
		if (!is_used[v[i]])
			return v[i];
	}
	return -1;
}

vector<string> get_split(string st){
	for (int i=0;i<st.size();i++)
	{
		if (st[i]=='-')
			st[i]=' ';
	}
	stringstream s(st);
	vector<string> ret;
	string temp;
	while (s>>temp){
		ret.push_back(temp);
	}
	return ret;
}

vector<int> get_numbers(string st){
	for (int i=0;i<st.size();i++)
	{
		if (st[i]>='0'&&st[i]<='9')
			continue;
		st[i]=' ';
	}
	stringstream s(st);
	vector<int> ret;
	int temp;
	while (s>>temp){
		ret.push_back(temp);
	}
	return ret;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	//cout<<n-1<<endl;
	for (int i=1;i<=n;i++)
	{
		cin>>st;
		vector<string> v=get_split(st);
		for (int j=0;j<v.size();j++)
		{
			vector<int> V=get_numbers(v[j]);
			V.erase(V.begin());
			cand.push_back(make_pair(i,V));
		}
	}

	if (cand.size()!=(2*n-2))
	{
		cout<<-1<<endl;
		return 0;
	}

	while (true){
		int have_unused=0;
		int found_something=0;
		for (int i=0;i<cand.size();i++)
		{
			if (already_solved[i])
				continue;
			if (is_used[cand[i].first])
				continue;
			have_unused=1;
			int C=count_vertices(cand[i].second);
			if (C!=1)
				continue;
			found_something=1;

			int t=get_unused_vertex(cand[i].second);
			ans.push_back(make_pair(cand[i].first,t));
			//cout<<cand[i].first<<"@"<<t<<endl;
			already_solved[i]=1;
			is_used[t]=1;
		}
		if (have_unused==0)
			break;
		if (found_something==0)
			break;
	}

	for (int i=0;i<ans.size();i++)
	{
		if (ans[i].first>ans[i].second)
			swap(ans[i].first,ans[i].second);
	}

	sort(ans.begin(),ans.end());

	vector<pair<int,int> > res=ans;
	ans.clear();
	for (int i=0;i<res.size();i++)
	{
		if (i==0||res[i]!=res[i-1])
			ans.push_back(res[i]);
	}
	if (ans.size()!=n-1){
		cout<<-1<<endl;
		return 0;
	}
	cout<<n-1<<endl;

	for (int i=0;i<ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}

	cin.get(); cin.get();
	return 0;
}