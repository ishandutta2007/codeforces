#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
void solve();
int main ()
{
#ifdef _DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}
#define int li
int n;
int rests[20];
int num[20];
void solve ()
{
    cin>>n;
	int ans=0;
	int a=1, b=n;
	while ( a<=n )
	{
		ans+=b;
		a++;
		while ( b>0 && a*b>n )
			b--;
	}
	for (int i=1; i<=n; i++)
		num[i%9]++;
	int all=0;
	for ( int i=0; i<9; i++ )
		for (int j=0; j<9; j++)
			{
				int z=num[(i*j)%9];
				all+=z*num[i]*num[j];
			}
	cout<<all-ans;
}