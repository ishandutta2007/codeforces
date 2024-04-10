#include<bits/stdc++.h>
using namespace std;
int num[101];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)	cin >> num[i];
	sort(num , num + n);
	for(int i = 0 ; i < n ; i++)	cout << num[i] << " ";
	return 0;
}