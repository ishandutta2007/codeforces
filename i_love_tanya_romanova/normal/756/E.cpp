/*
Another wasted breath trying to prove my innocence
I know I've sealed my fate, another lie that brings disgrace
I know you wanna see, see me hurt, make me suffer
But all that's left are all the
Broken shattered pieces of our lives

I wish that I could tell you so you know
There's things I'm hiding deep beneath my skin
Beneath my skin
I wanna tell you so you know
There's things I'm hiding deep beneath my skin
Beneath my skin

So come and take my life, let me feel your wickedness
I know I've made mistakes so come and watch me fall from grace
I know you wanna see, see me hurt, make me suffer
I've nothing left so I'll just sacrifice myself to make it right
(To make it right)

I wish that I could tell you so you know
There's things I'm hiding deep beneath my skin
Beneath my skin
I wanna tell you so you know
There's things I'm hiding deep beneath my skin
Beneath my skin

I wanna tell you so you know
I wanna tell you

I guess I've fucked things up
I know it's all my fault
I'm pretty sure that this will be
The death of me

I guess I've fucked things up
I know it's all my fault
I'm pretty sure that this will be
The death of me

I wish that I could tell you so you know
There's things I'm hiding deep beneath my skin
Beneath my skin
I wanna tell you so you know
There's things I'm hiding deep beneath my skin
Beneath my skin

I wish that I could tell you so you know
There's things I'm hiding deep beneath my skin
Beneath my skin
I wanna tell you so you know
There's things I'm hiding deep beneath my skin
Beneath my skin
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
const int N = 500031;

vector<int> dp[N];
int n;
int ratio[N];
int b[N];
vector<int> cur_num;

int get_rem(int val)
{
	long long ost=0;
	for (int i=cur_num.size()-1;i>=0;--i)
	{
		ost=ost*1000000000+cur_num[i];
		long long new_ost=ost%val;
		cur_num[i]=ost/val;
		ost=new_ost;
	}

	while (cur_num.size()>1&&cur_num.back()==0)
		cur_num.pop_back();

	return ost;

}

vector<int> parse_num(string st){
	while (st.size()%9)
	{
		st="0"+st;
	}
	vector<int> ret;
	int here=0;

	for (int i=0;i<st.size();i++){
		here=here*10+st[i]-48;
		if (i%9==8)
			ret.push_back(here),
			here=0;
	}
	return ret;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;

	for (int i=1;i<n;i++)
	{
		cin>>ratio[i];
	}

	ratio[n]=100000000;

	for (int i=1;i<=n;i++)
	{
		cin>>b[i];
	}

	string st;
	cin>>st;

	cur_num=parse_num(st);


	reverse(cur_num.begin(),cur_num.end());

	/*for (int i=0;i<cur_num.size();i++)
	{
		cout<<cur_num[i]<<" ";
	}
	cout<<endl;
*/
	dp[1].push_back(1);
	for (int i=1;i<=n;i++)
	{
		int need_rem;

		if (ratio[i]==1)
			need_rem=0;
		else
			need_rem=get_rem(ratio[i]);

//		cout<<need_rem<<endl;

		int cnt_ways=0;

/*		for (int j=0;j<dp[i].size();j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
*/

		for (int j=0;j<dp[i].size()+b[i];j++)
		{
			if (j<dp[i].size())
				cnt_ways+=dp[i][j];
			if (j>b[i])
				cnt_ways-=dp[i][j-b[i]-1];
			cnt_ways%=bs;
			if (cnt_ways<0)
				cnt_ways+=bs;
			if (j%ratio[i]==need_rem)
				dp[i+1].push_back(cnt_ways);
		}
	}

	if (dp[n+1].size()==0||cur_num.size()>1||cur_num[0]!=0)
		cout<<0<<endl;
	else
		cout<<dp[n+1][0]<<endl;

	cin.get(); cin.get();
	return 0;
}