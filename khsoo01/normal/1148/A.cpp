#include<bits/stdc++.h>
using namespace std;

long long a, b, c;

int main()
{
	cin >> a >> b >> c;
	cout << (min(a, b) + c) * 2 + (a != b);
}