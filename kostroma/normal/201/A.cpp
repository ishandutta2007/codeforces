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

//#define int li

int x;

void solve(){
	cin>>x;
	if (x==3)
	{
		cout<<5;
		return;
	}
	int ans=1<<30;
	if (x%4==0)
	{
		for (int k=1; k<=200; k++)
		{
			if ( ((k-1)*(k-1)+1)/2>=x/4 )
				ans=min( ans, 2*k );
		}
	}
	for (int k=0; k<=200; k++)
	{
		if (x%2)
		{
			int add=(k*k+1)/2; add*=4;
			add+=4*(k/2)+1;
			if (add>=x)
				ans=min(ans, 2*k+1);
		}
		else
		{
			int add=(k*k+1)/2; add*=4;
			add+=4*(k/2);
			if (add>=x)
				ans=min(ans, 2*k+1);

			add=k*k/2; add*=4;
			add+=4*((k+1)/2);
			if (add>=x)
				ans=min(ans, 2*k+1);
		}
	}

	cout<<ans;
	
}