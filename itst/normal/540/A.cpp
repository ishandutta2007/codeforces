#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string a , b;
	int n , sum = 0;
	cin >> n >> a >> b;
	for(int i = 0 ; i < n ; i++)
		sum += min(abs(a[i] - b[i]) , 10 - abs(a[i] - b[i]));
	cout << sum;
	return 0;
}