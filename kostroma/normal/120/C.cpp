#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef long long li;
typedef pair <int, int> pi;
#define mp make_pair
#define pb push_back
void solve ();
int main()
{
		freopen("input.txt","r",stdin);
#ifndef _DEBUG
	freopen("output.txt","w",stdout);
#endif
	 solve();
	return 0;
}

void solve()
{
	int n, k;
	cin>>n>>k;
	int a[200];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
	{
		if(a[i]>=3*k)
			a[i]-=3*k;
		else
			a[i]%=k;
	}
	int res=0;
	for(int i=0; i<n; i++)
		res+=a[i];
	cout<<res;
	return;
}