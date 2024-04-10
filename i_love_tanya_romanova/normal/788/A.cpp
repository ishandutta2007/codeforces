/*
A killer a leader they think he is God
Demanding commanding obeying his word
Crazy psycho out of his mind
Followers believers loyal to the man

Kill for their master murder when he says
Torture all their victims
Bloodbath they look dead

Animals savages sick people they are
Praying sinning for their fake God
Wild dirty together they ride
Their home the desert cult they live

Mayhem death shoot them down
Take no prisoners kill them all
Cutting breaking thrash to death
Banging the head breaking his neck
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007

#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,ar[N];
int res;

int f(int l,int r)
{
	int ret=0;

	for (int i=l;i<r;i++)
	{
		int here=ar[i]-ar[i+1];
		here=abs(here);
		if (i%2==l%2)
			ret+=here;
		else
			ret-=here;
	}
	return ret;
}

void read_data()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
}

void generate_data()
{
	n=rand()%100+2;
	for (int i=1;i<=n;i++)
	{
		ar[i]=rand()%100-50;
	}
}

int slow()
{
	int ret=-1e9;
	for (int l=1;l<n;l++)
	{
		for (int r=l+1;r<=n;r++)
		{
			ret=max(ret,f(l,r));
		}
	}
	return ret;
}

long long V[N];

long long solver(int parity)
{
	long long smallest_sum=1e18;
	if (parity==0)
		smallest_sum=0;
	long long s=0;
	long long ret=-1e18;

	for (int i=1;i<=n;i++)
	{
		s+=V[i];
//		cout<<i<<"%"<<V[i]<<" "<<smallest_sum<<" "<<s<<" "<<parity<<endl;
		if (i<n)
			ret=max(ret,s-smallest_sum);
		if (i%2==parity)
			smallest_sum=min(smallest_sum,s);
	}
	return ret;
}

long long solve()
{
	for (int i=1;i<=n;i++)
	{
		V[i]=abs(ar[i]-ar[i+1]);
	}
	/*for (int i=1;i<=n;i++)
	{
		cout<<V[i]<<" ";
	}
	cout<<endl;
*/
	for (int i=2;i<=n;i+=2)
	{
		V[i]*=-1;
	}

	long long ret=solver(0);

	for (int i=1;i<=n;i++){
		V[i]*=-1;
	}
	ret=max(ret,solver(1));
	return ret;
}

int main(){
	//freopen("cinema.in","r",stdin);
	//freopen("cinema.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	/*for (int iter=1;iter<=100;iter++)
	{
		generate_data();
		long long A=solve();
		long long B=slow();
		for (int i=1;i<=n;i++)
		{
			cout<<ar[i]<<" ";
		}
		cout<<endl;

		cout<<A<<" "<<B<<endl;
		assert(A==B);
	}
*/
	read_data();
	cout<<solve()<<endl;

//	cout<<solve()<<" "<<slow()<<endl;


	cin.get(); cin.get();
	return 0;
}