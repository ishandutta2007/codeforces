/*
Have been down for much too long bitter taste of this
Time, getting sick and tired about the way things are
So tell me where is all the peace of mind that i could
Never find, never wanted what you offered me at all

Tell me, tell me, tell me
What do you believe in
Tell me, tell me, tell me
What do you believe
Give me, give me, give me
Something to believe in
Give me, give me, give me
Something to believe

Have been broken much too long with a heart of anger
I could never understand what you became so tell me
Where is your heaven on earth that i could never find
Maybe i am just too blind to realize

Tell me, tell me, tell me
What do you believe in
Tell me, tell me, tell me
What do you believe
Give me, give me, give me
Something to believe in
Give me, give me, give me
Something to believe

Do you believe in pain
Do you believe in hate
This life it ain't for me
Your world it ain't for me

Tell me, tell me, tell me
What do you believe in
Tell me, tell me, tell me
What do you believe
Give me, give me, give me
Something to believe in
Give me, give me, give me
Something to believe
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
const int N = 111031;

int tests;
string st1,st2;

int get_val(char c)
{
	if (c>='0'&&c<='9')
		return c-'0';
	return c-'a'+10;
}

long long parse_num(string st)
{
	long long res=0;
	for (int i=0;i<st.size();i++)
	{
		res=res*16+get_val(st[i]);
	}
	return res;
}

long long checker(long long val)
{
	long long v=0;
	long long memo=val;
	while (val>0)
	{
		int here=val%16;
		val/=16;
		v|=(1<<here);
	}
	long long v2=(memo^v);
	if (v2<memo)
		return 1;
	return 0;
}

long long naive(long long r)
{
	long long res=0;
	for (long long i=1;i<=r;i++)
	{
		if (checker(i))
		{
			int qq=0;
			int v=i;
			while (v)
			{
				qq=max(qq,v%16);
				v/=16;
			}
		//	cout<<"!!"<<i<<" "<<qq<<endl;
		}
		res+=checker(i);
	}
	return res;
}

vector<int> get_by_digit(string st){
	vector<int> ret;
	for (int i=0;i<st.size();i++)
	{
		ret.push_back(get_val(st[i]));
	}
	return ret;
}

long long dp[20][2][2];

bool cant_put(int dig_id,int what,int req)
{
	int in_dig=req-(dig_id-1)*4;
	if (in_dig<0||in_dig>=4)
		return false;
	if (what&(1<<in_dig))
		return false;
	return true;
}

long long run_dp(vector<int> dig,int max_dig)
{
	if (max_dig>=4*dig.size())
		return 0;

	for (int i=0;i<=dig.size();i++)
	{
		for (int is_les=0;is_les<=1;is_les++)
		{
			for (int used_max=0;used_max<=1;used_max++)
			{
				dp[i][is_les][used_max]=0;
			}
		}
	}

	for (int i=0;i<dig.size();i++)
	{
		for (int j=1;j<=max_dig;j++)
		{
			if (j>dig[0]&&i==0)
				continue;
			if (cant_put(dig.size()-i,j,max_dig))
				continue;
			if (max_dig>=(dig.size()-i)*4) // leading 1 to the left
				continue;
/*			if (max_dig==4)
			{
				cout<<i<<"%"<<j<<" "<<endl;
			}
*/			dp[i+1][i>0||j<dig[0]][j==max_dig]+=1;
		}
	}

	for (int i=0;i<dig.size();i++)
	{
		for (int is_les=0;is_les<=1;is_les++)
		{
			for (int used_max=0;used_max<=1;used_max++)
			{
/*				if (max_dig==4)
				{
					cout<<i<<"%"<<is_les<<" "<<used_max<<" "<<dp[i][is_les][used_max]<<endl;
				}
*/				if (dp[i][is_les][used_max]==0)
					continue;
				for (int ad_dig=0;ad_dig<=max_dig;ad_dig++)
				{
					if (is_les==0&&ad_dig>dig[i])
						continue;
					if (cant_put(dig.size()-i,ad_dig,max_dig))
						continue;
				/*	if (i+1==dig.size()&&(used_max|(ad_dig==max_dig))==1&&max_dig==4)
					{
						cout<<i<<" "<<is_les<<" "<<used_max<<" "<<ad_dig<<" "<<dp[i][is_les][used_max]<<endl;
					}*/
					dp[i+1][is_les|(ad_dig<dig[i])][used_max|(ad_dig==max_dig)]+=
							dp[i][is_les][used_max];
				}
			}
		}
	}
	long long res=0;
	for (int i=0;i<=1;i++)
	{
		/*if (max_dig==4)
		{
			cout<<dp[dig.size()][i][1]<<"%"<<endl;
		}*/
		res+=dp[dig.size()][i][1];
	}
	return res;
}

long long smart(string st)
{
	vector<int> v=get_by_digit(st);
	long long res=0;
	for (int max_dig=1;max_dig<=15;max_dig++)
	{
	//	cout<<st<<"%"<<run_dp(v,max_dig)<<" "<<max_dig<<endl;
		res+=run_dp(v,max_dig);
	}
	return res;
}

int main(){
//	freopen("explosion.in","r",stdin);
//	freopen("explosion.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>tests;
	for (;tests;--tests)
	{
		cin>>st1>>st2;
		long long A=parse_num(st1);
		long long B=parse_num(st2);
		//cout<<A<<"%"<<B<<endl;

	//	cout<<naive(B)-naive(A-1)<<endl;

	//	cout<<smart(st2)<<" "<<naive(B)<<endl;
		long long res=smart(st2)-smart(st1);
		if (checker(A))
			res++;
		cout<<res<<endl;
	}
	cin.get(); cin.get();
	return 0;
}