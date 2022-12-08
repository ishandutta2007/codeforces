#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,l,r;

ll ans1=0,ans2=0;

int main()
{
	cin >> n >> l >> r;
	for(int i=1;i<=r;i++)ans1+=1ll<<(i-1);
	ans1+=1ll*(n-r)*(1ll<<(r-1));
	for(int i=1;i<=l;i++)ans2+=1ll<<(i-1);
	ans2+=1ll*(n-l)*1;
	cout << ans2 << " " << ans1 << endl;
}