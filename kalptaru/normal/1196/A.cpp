#include <bits/stdc++.h>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)]; FOR(i, 0, (n)) {cin >> a[i];}
struct p
{
	int a,b;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	while(q--)
	{
		readarr(a,3);
		cout<<(a[0]+a[1]+a[2]>>1);
		cout<<endl;
	}
	return 0;
}