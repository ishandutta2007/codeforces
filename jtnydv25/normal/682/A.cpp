#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,m;
	cin>>n>>m;
	ll cnt1[5],cnt2[5];
	memset(cnt1,0,sizeof cnt1);
	memset(cnt2,0,sizeof cnt2);
	for(int i = 1;i<=n;i++)
		cnt1[i%5]++;
	for(int i = 1;i<=m;i++)
		cnt2[i%5]++;
	ll sm = 0;
	for(int i = 0;i<5;i++)
		sm+=cnt1[i]*cnt2[(5-i)%5];
	cout<<sm;
}