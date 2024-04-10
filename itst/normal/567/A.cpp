#include<bits/stdc++.h>
using namespace std;
int num[100002];
int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)	cin >> num[i];
	cout << num[1] - num[0] << " " << num[n - 1] - num[0] << endl;
	for(int i = 1 ; i < n - 1 ; i++)
		cout << min(num[i + 1] - num[i] , num[i] - num[i - 1]) << " " << max(num[n - 1] - num[i] , num[i] - num[0]) << endl;
	cout << num[n - 1] - num[n - 2] << " " << num[n - 1] - num[0];
	return 0;
}