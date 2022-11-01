#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b;
	cin >> a >> b;
	cout << min(a , b) << " " << (max(a , b) - min(a , b)) / 2;
	return 0;
}