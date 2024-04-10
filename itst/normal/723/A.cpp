#include<bits/stdc++.h>
using namespace std;
int num[3];
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> num[0] >> num[1] >> num[2];
	sort(num , num + 3);
	cout << num[2] - num[0];
	return 0;
}