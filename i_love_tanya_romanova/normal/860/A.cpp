/*
I'm a radio joe of the biz called show
I'm a rockin popstar with a get up and go
Rubbin' elbows with the big wigs at my sold out shows
I've been on every cover even rolling stone

Put us on mtv
All we really need
Begging on our knees
Please, please, please, please, please

Conforming to the norm straight out of the mold
Compromising each and every ounce of soul
I'm a doin' anything for the records of gold
I only want what i can hold

Put us on mtv
All we really need
Begging on our knees
Please, please, please, please, please

We know that we'll never be better than
Mister slick superstar david letterman
I promise we'll be perfect gentlemen
Just put us on the show you'll regret us then

Put us on mtv
All we really need
Begging on our knees
Please, please, please, please, please

Thank you very much be sure to label us
We wouldn't want to cause a ruckus or a fuss
Aor, chr, top forty or bust

Put us on mtv
All we really need
Begging on our knees
Please, please, please, please, please

What i am is a picture on the tv screen
Don't make waves don't make a scene
What i say when i play isn't worth a bean
I'm a video joe in an industry

Put us on mtv
All we really need
Begging on our knees
Please, please, please, please, please
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

const int N = 3031;

string st;
int ar[N];
int last_good[N];
int last_dif[N];
int can_take[N][N];
int dp[N];
int par[N];

bool is_good(char c)
{
	if (c=='a'||c=='e'||c=='u'||c=='i'||c=='o')
		return 1;
	return 0;
}

int n;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>st;

	for (int i=0;i<st.size();i++)
	{
		ar[i]=is_good(st[i]);
	}

	last_good[0]=-1;
	last_dif[0]=-1;
	if (ar[0]==1)
		last_good[0]=0;

	for (int i=1;i<st.size();i++)
	{
		last_good[i]=last_good[i-1];
		if (ar[i]==1)
			last_good[i]=i;
		if (st[i]==st[i-1])
			last_dif[i]=last_dif[i-1];
		else
			last_dif[i]=i-1;
		//cout<<last_dif[i]<<" "<<last_good[i]<<endl;
	}

	n=st.size();


	for (int l=0;l<n;l++)
	{
		int is_ok=1;

		for (int r=l;r<n;r++)
		{
			if (r>l+1&&last_good[r]<r-2&&last_dif[r]>last_good[r]&&last_dif[r]>=l)
				is_ok=0;
			if (is_ok)
				can_take[l][r]=1;
			//cout<<l<<" "<<r<<" "<<can_take[l][r]<<endl;
		}
	}

	for (int i=0;i<=n;i++)
	{
		dp[i]=1e9;
	}
	dp[0]=0;
	for (int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++)
		{
			if (can_take[i][j])
			{
				if (dp[i]+1<dp[j+1])
				{
					dp[j+1]=dp[i]+1;
					par[j+1]=i;
				}
			}
		}
	}

	//cout<<dp[n]<<endl;

	vector<string> ans;
	while (n)
	{
		int p=par[n];
		string temp;
		for (int i=p;i<n;i++)
		{
			temp+=st[i];
		}
		ans.push_back(temp);
		n=p;
	}
	reverse(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++)
	{
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;

	cin.get(); cin.get();
	return 0;
}