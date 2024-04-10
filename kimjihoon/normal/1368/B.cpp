#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long p[10];
string s = "codeforces";

long long cl()
{
	long long s = 1;
	for (int i = 0; i < 10; i++)
		s *= p[i];
	return s;
}

int main()
{
	ios::sync_with_stdio(false);	
	cin.tie(0);
	long long k; cin >> k;
	int t = 0;
	while (cl() < k) {
		p[t]++; 
		t = (t + 1) % 10;
	}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < p[i]; j++)
			cout << s[i];
	cout << '\n';
	return 0;
}