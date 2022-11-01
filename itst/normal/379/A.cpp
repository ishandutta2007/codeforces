#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int sum = 0 , n , b , t = 0;
	cin >> n >> b;
	while((n + t) / b)
	{
		sum += n;
		t += n;
		n = t / b;
		t %= b;
	}
	cout << sum + n;
	return 0;
}