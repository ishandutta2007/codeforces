/*
Here I am standing, darkness all around.
Thinking of past, taken my last breath, the air is cold as ice
No one close to hear my voice
Did not leave me with a choice
Heaven will you wait for me?

Will I find a way, will I find a place
Will you let me go in peace
Will I find a way to the other side.

Sad are memories from the life I lived
Cannot go on, cannot go further
I has to end right here
For the things that I have done
All the girls I lost and won
Let me rest in peace at last

Will I find a way, will I find a place
Will you let me go in peace
Leave behind those dark days
No I ask again will you hear my cries
Then you realize why oh why
I must find a way to the other side.

Hear them whisper calling out my name
The sentences is set, the hammer has fallen
I have paid the price
Sad to realize to late death was meant to be my fate
All this pain will follow me.
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
const int N = 200031;

int n;
vector<long long> othr;
int cnt[100];

long long get_pow2(long long val)
{
	for (int i=0;i<=40;i++)
	{
		if (val==(1ll<<i))
				return i;
	}
	return -1;
}

long long cnt_of_open[N];
long long cnt_of_closed[N];

int ans_max;
vector<long long> list_of_closed[N];

vector<vector<long long> > all_sequences;

bool cmp(vector<long long> a,vector<long long> b){
	if (a.size()!=b.size())
		return a.size()<b.size();// short first
	for (int i=0;i<a.size();i++)
	{
		if (a[i]!=b[i])
			return a[i]<b[i];// small first
	}
	return false;// equal
}

int cnt_with[1000];

bool is_nice(vector<long long> &v)
{
	for (int i=1;i<v.size();i++)
	{
		if (v[i]!=v[i-1]*2)
			return false;
	}
	return true;
}

bool solve(int span)
{
	vector<long long > vals_to_remove;
	for (int i=0;i<span;i++)
	{
		for (int j=0;j<all_sequences[i].size();j++)
		{
			vals_to_remove.push_back(all_sequences[i][j]);
		}
	}

	sort(vals_to_remove.begin(),vals_to_remove.end());

	for (int i=0;i<=40;i++)
	{
		cnt_with[i]=0;
	}

	for (int i=span;i<all_sequences.size();i++){
		if (is_nice(all_sequences[i]))
			cnt_with[all_sequences[i].size()-1]++;
	}

	for (int i=0;i<vals_to_remove.size();i++)
	{
		int q=-1;
		for (int j=0;j<=40;j++)
		{
			if (cnt_with[j]>0&&(1ll<<j)*2>=vals_to_remove[i])
			{
				q=j;
				break;
			}
		}
		if (q==-1)
			return false;
		cnt_with[q]--;
	}
	return true;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;

	for (int i=0;i<n;i++)
	{
		long long val;
		cin>>val;
		int q=get_pow2(val);
		if (q==-1)
			othr.push_back(val);
		else
			cnt[q]++;
	}

	for (int i=40;i>=0;--i)
	{
		int can_make=1e9;
		for (int j=0;j<=i;j++){
			can_make=min(can_make,cnt[j]);
		}

		for (int j=0;j<=i;j++)
		{
			cnt[j]-=can_make;
		}

		cnt_of_open[i]=can_make;

		while (cnt[i]>0)
		{
			othr.push_back(1ll<<i);
			cnt[i]--;
		}
	}

	sort(othr.begin(),othr.end());

	reverse(othr.begin(),othr.end());

	for (int i=(int)othr.size()-1;i>=0;--i)
	{
		int q=-1;
		for (int j=0;j<=40;j++)
		{
			if (cnt_of_open[j]==0)
				continue;
			if ((1ll<<j)*2>othr[i])
			{
				q=j;
				break;
			}
		}
		if (q==-1)
		{
			cout<<-1<<endl;
			return 0;
		}
		cnt_of_open[q]--;
		cnt_of_closed[q]++;
		list_of_closed[q].push_back(othr[i]);
	}

	long long res=0;
	for (int i=0;i<=40;i++)
	{
		res+=cnt_of_open[i]+cnt_of_closed[i];
	}
	ans_max=res;
	//cout<<res<<endl;

	all_sequences.clear();

	for (int i=0;i<=40;i++)
	{
		vector<long long> vals_here;
		for (int j=0;j<=i;j++)
		{
			vals_here.push_back(1ll<<j);
		}
		for (int j=0;j<cnt_of_open[i];j++)
		{
			vector<long long> vals2=vals_here;
			all_sequences.push_back(vals2);
		}
		for (int j=0;j<list_of_closed[i].size();j++)
		{
			vector<long long> vals2=vals_here;
			vals2.push_back(list_of_closed[i][j]);
			all_sequences.push_back(vals2);
		}
	}

	sort(all_sequences.begin(),all_sequences.end(),cmp);

	int l,r;
	l=0;
	r=all_sequences.size();
	while (l<r)
	{
		int mid=l+r+1;
		mid/=2;
		if (solve(mid))
			l=mid;
		else
			r=mid-1;
	}

	for (int i=ans_max-l;i<=ans_max;i++)
	{
		if (i!=ans_max-l)
			cout<<" ";
		cout<<i;
	}
	cout<<endl;


	cin.get(); cin.get();
	return 0;
}