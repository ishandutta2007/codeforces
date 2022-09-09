#pragma comment(linker, "/STACK:106777216")

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;
#define NAME "circles"
int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#else
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);
	int t = 1;
	//cin>>t;
	while (t--)
	{
		solve();
	}
	return 0;
}

#define int li

int n;
int a[100500];
int pref[100500], suff[100500];

void solve(){
	cin>>n;
	--n;
	for (int i=0; i<n; i++)
		cin>>a[i];
	int ans=0, curans=0;
	int curans1=0;
	
	int b1=0, b2=0;

	int delta=0;

	for (int i=0; i<n; i++)
	{
		if (a[i]==0)
		{
			ans=max(ans, curans);
			curans=0;
			curans1=0;
		}
		if (a[i]==1)
		{
			ans=max(curans1, ans);
			curans=max(curans,curans1);
			curans1=0;
			b1=-1;
			b2=0;
		}
		if (a[i]%2)
		{
			curans+=a[i];
			if (a[i]!=1)
				curans1+=a[i];
			b1++;
		}
		if (a[i]%2==0 && a[i]>0)
		{
			curans1+=a[i]-1;
			curans+=a[i]-1;
			b2++;
		}
		if (delta<b2-b1)
		{
			curans1+=b2-b1-delta;
			delta=b2-b1;
		}
		ans=max(ans, curans);
		ans=max(ans, curans1);
		pref[i]=ans;
	}
	ans=max(ans, curans);
	curans=0;
	curans1=0;
	b1=0; b2=0;
	suff[n]=0;
	delta=0;
	int answer=ans;
	ans=0;
	for (int i=n-1; i>=0; i--)
	{
		if (a[i]==0)
		{
			ans=max(ans, curans);
			curans=0;
			curans1=0;
			continue;
		}
		if (a[i]==1)
		{
			ans=max(curans1, ans);
			curans=max(curans,curans1);
			curans1=0;
			b1=-1;
			b2=0;
		}
		if (a[i]%2)
		{
			if (a[i]!=1)
				curans1+=a[i];
			curans+=a[i];
			b1++;
		}
		if (a[i]%2==0 && a[i]>0)
		{
			curans1+=a[i]-1;
			curans+=a[i]-1;
			b2++;
		}
		if (delta<b2-b1)
		{
			curans1+=b2-b1-delta;
			delta=b2-b1;
		}
		ans=max(ans, curans);
		ans=max(ans, curans1);
		suff[i]=ans;
	}

	/*for (int i=0; i<n; i++)
		cout<<pref[i]<<' '<<suff[i]<<endl;*/

	ans=max(ans, curans);
	curans=0;

	answer=max(ans,answer);

	answer=max(answer, suff[0]);
	for (int i=0; i<n; i++)
		answer=max(answer, pref[i]+suff[i+1]);


	cout<<answer;

	
}