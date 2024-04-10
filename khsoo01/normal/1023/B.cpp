#include<bits/stdc++.h>
using namespace std;

long long a, b, ans;

int main()
{
	cin >> a >> b;
	if(b <= a+1) {
		ans = b - 1;
		int X = (b % 2 == 0);
		cout << (ans - X) / 2;
	}
	else if(b > 2*a) cout << "0";
	else {
		int X = (b % 2 == 0);
		cout << (a - (b - a) + 1 - X) / 2;
	}
}