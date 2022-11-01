#include<bits/stdc++.h>
using namespace std;
struct p{
	int a , b;
}ans[101];
bool cmp(const p &a , const p &b)
{
	return a.b < b.b;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> ans[i].b;
		ans[i].a = i + 1;
	}
	sort(ans , ans + n , cmp);
	for(int i = 0 ; i < n ; i++)	cout << ans[i].a << " ";
	return 0;
}