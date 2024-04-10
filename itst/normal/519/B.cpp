#include<bits/stdc++.h>
using namespace std;
int num[100001] , cmp[100001];
int main()
{
	std::ios::sync_with_stdio(false);
	int n , f = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)	cin >> num[i];
	sort(num , num + n);
	for(int i = 0 ; i < n - 1 ; i++)	cin >> cmp[i];
	sort(cmp , cmp + n - 1);
	for(int i = 0 ; i < n - 1 && !f ; i++)
		if(num[i] != cmp[i])
		{
			cout << num[i] << endl;
			f = 1;
		}
	if(!f)	cout << num[n - 1] << endl;
	for(int i = 0 ; i < n - 2 ; i++)	cin >> num[i];
	sort(num , num + n - 2);
	f = 0;
	for(int i = 0 ; i < n - 2 && !f ; i++)
		if(num[i] != cmp[i])
		{
			cout << cmp[i];
			f = 1;
		}
	if(!f)	cout << cmp[n - 2];
	return 0;
}