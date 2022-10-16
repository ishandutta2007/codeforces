#include <iostream>
using namespace std;
int a, b, c, d;
int main()
{
	cin >> a>>b >> c >> d;
	if (a + d == b + c || a + c == b + d || a + b == c + d||a==b+c+d||b==a+c+d||c==a+b+d||d==a+b+c)
		cout << "YES";
	else
		cout << "NO";
}