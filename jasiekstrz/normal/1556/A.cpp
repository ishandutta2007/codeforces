#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
void solve()
{
	long long c,d;
	cin>>c>>d;
	if((c+d)%2==1 || abs(c-d)%2==1)
	{
		cout<<"-1\n";
		return;
	}
	if(c==d)
		cout<<(c==0 ? 0:1)<<"\n";
	else
		cout<<"2\n";
	return;
}	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--)
		solve();
	return 0;
}