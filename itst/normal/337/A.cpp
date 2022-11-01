#include<bits/stdc++.h>
using namespace std;
int num[1001];
int main()
{
	std::ios::sync_with_stdio(false);
	int n , k , minN = 99999999;
	cin >> n >> k;
	for(int i = 0 ; i < k ; i++)	cin >> num[i];
	sort(num , num + k);
	for(int i = 0 ; i + n - 1 < k ; i++)
		minN = min(minN , num[i + n - 1] - num[i]);
	cout << minN;
	return 0;
	return 0;
}