#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	long long int result = 0;
	int n;

	cin >> n;
	for(int i = 0; i < n; i++){
		char a;
		cin >> a;
		if((int)(a - '0') % 2 == 0) result += i+1;
	}

	cout << result << "\n";

	return 0;
}