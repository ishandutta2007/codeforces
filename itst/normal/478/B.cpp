#include<bits/stdc++.h>
using namespace std;
inline long long cul(int a)
{
	return (long long) a * (a - 1) / 2;
}
int main()
{
	int a , b;
	cin >> a >> b;
	cout << (b - a % b) * cul(a / b) + a % b * cul(a / b + 1) << " " << cul(a - b + 1);
	return 0;
}