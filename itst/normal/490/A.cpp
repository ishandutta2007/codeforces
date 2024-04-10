#include<bits/stdc++.h>
using namespace std;
struct p{
	int index , t;
}ans[5001];
int num[3];
inline bool cmp(const p &a , const p &b)
{
	return a.t < b.t;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> ans[i].t;
		num[ans[i].t - 1]++;
		ans[i].index = i;
	}
	cout << min(min(num[0] , num[1]) , num[2]) << endl;
	sort(ans + 1 , ans + n + 1 , cmp);
	for(int i = 1 ; i <= min(min(num[0] , num[1]) , num[2]) ; i++)
		cout << ans[i].index << ' ' << ans[i + num[0]].index << " " << ans[i + num[0] + num[1]].index << endl;
	return 0;
}