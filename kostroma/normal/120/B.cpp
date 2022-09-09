#include <stdio.h>
#include <iostream>
using namespace std;


void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#else 
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}
int n, k, a[2000];
void solve ()
{
	cin>>n>>k;
	for (int i=0; i<n; i++)
		cin>>a[i];
	k--;
	int u=-1;
	for ( int i=k; i<n; i++ )
		if (a[i])
		{
			u=i;
			break;
		}
	if (u>-1)
	{
		cout<<u+1;
		return;
	}
	for (int i=0; i<n; i++)
		if (a[i])
		{
			cout<<i+1;
			return;
		}
}