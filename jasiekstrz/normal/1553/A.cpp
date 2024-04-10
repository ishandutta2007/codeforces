#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int c=n%10;
	cout<<n/10+(c==9)<<"\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int qq;
	cin>>qq;
	while(qq--)
		solve();
	return 0;
}