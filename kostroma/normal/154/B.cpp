#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <queue>
#include <time.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef vector <int> vi;

void solve();

int main ()
{
#ifdef DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	//cin>>t;
	while (t--)
		solve();
	return 0;
}

#define int li

bool prime[100500];

int n, m;
bool on[100500];
vector <int> prost;
vector < set <int> > num;

vector <int> primes[100500];

int bp (int val)
{
	int l=0, r=prost.size();
	while (l+1<r)
	{
		int mm=l+r; mm/=2;
		if (prost[mm]>val)
			r=mm;
		else
			l=mm;
	}
	return l;
}

void solve()
{
	cin>>n>>m;
	memset (prime, true, sizeof prime);
	prime[1]=false;
	for (int i=2; i<100500; i++)
		if (prime[i])
		{
			prost.pb(i);
			primes[i].pb(i);
			for (int j=i*2; j<100500; j+=i)
			{
				prime[j]=false;
				primes[j].pb(i);
			}
		}
	num.resize(prost.size());
	while (m--)
	{
		char c;
		c=getchar();
		c=getchar();
		int q;
		if (c=='+')
		{
			cin>>q;
			if (on[q])
			{
				cout<<"Already on\n";
				continue;
			}

			bool f=true;
			int rr=-1;

			for (int i=0; i<primes[q].size(); i++)
				if ( num[bp(primes[q][i])].size()>0 )
				{
					f=false;
					rr=primes[q][i];
					break;
				}

			if (!f)
			{
				cout<<"Conflict with "<<*(num[bp(rr)].begin())<<endl;
				continue;
			}
			for (int i=0; i<primes[q].size(); i++)
				num[bp(primes[q][i])].insert(q);
			cout<<"Success\n";
			on[q]=true;
		}
		else
		{
			cin>>q;
			if (!on[q])
			{
				cout<<"Already off\n";
				continue;
			}
			on[q]=false;
			cout<<"Success\n";
			for (int i=0; i<primes[q].size(); i++)
				num[bp(primes[q][i])].erase(q);
		}
	}

}