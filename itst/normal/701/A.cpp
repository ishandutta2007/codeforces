#include<bits/stdc++.h>
using namespace std;
struct card{
	int i , value;
}ans[101];
bool cmp(card a , card b)
{
	return a.value > b.value;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> ans[i].value;
		ans[i].i = i + 1;
	}
	sort(ans , ans + n , cmp);
	for(int i = 0 ; i < n / 2 ; i++)
		cout << ans[i].i << " " << ans[n - i - 1].i << endl;
	return 0;
}