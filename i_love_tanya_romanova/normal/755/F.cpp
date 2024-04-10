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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 2100031;

int n,k,p[N];
int used[N];
vector<int> cycles;
bool reach[N];
int max_div[N];

int can2;
int L[N],val[N];

int solve_mx(int k,int twos)
{
	int ret=0;
	while (k>0&&twos>0)
	{
		twos--;
		k--;
		ret+=2;
	}
	ret+=k;
	if (ret>n)
		ret=n;
	return ret;
}

int cnt[N];
int K;

void run_knapsack()
{
	for (int i=0;i<cycles.size();i++)
	{
		cnt[cycles[i]]++;
	}

	int cur_s=0;

	reach[0]=1;

	for (int i=1;i<=1000000;i++)
	{
		if (cnt[i]==0)
			continue;
		cur_s+=cnt[i]*i;

	//	if (cur_s>=K)
	//		cur_s=K;
		if (reach[K])
			break;
		/*for (int j=0;j<=cur_s;j++)
		{
			cout<<reach[j]<<" ";
		}
		cout<<endl;
		 */

		for (int j=0;j<=cur_s;j++)
		{
			int q=j%i;
			if (reach[j]==1)
			{
				L[q]=i;
				val[q]=j/i;
			}
			else if (L[q]==i&&val[q]>=j/i-cnt[i])
			{
				reach[j]=1;
			}
		}
	}
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		//cin>>p[i];
		scanf("%d",&p[i]);
	}

	for (int i=1;i<=n;i++)
	{
		if (used[i])
			continue;
		int here=0;
		int ps=i;
		while (used[ps]==0)
		{
			here++;
			used[ps]=1;
			ps=p[ps];
		}
		cycles.push_back(here);
	}

	//mx
	for (int i=0;i<cycles.size();i++)
	{
		can2+=cycles[i]/2;
	}

	int ans1,ans2;

	ans2=solve_mx(k,can2);

	ans1=0;

//	sort(cycles.begin(),cycles.end());

	K=min(k,n-k);
	run_knapsack();
	if (reach[K])
	{
		ans1=k;
	}
	else
		ans1=k+1;

	cout<<ans1<<" "<<ans2<<endl;


	cin.get(); cin.get();
	return 0;
}