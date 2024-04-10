#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--) {
		int a, b, C;
		cin >> a >> b >> C;
		printf("%d\n", (C%3 == 0 ? a : C%3 == 1 ? b : (a^b)));
	}
}