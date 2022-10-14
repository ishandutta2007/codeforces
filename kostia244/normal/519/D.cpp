#include <bits/stdc++.h>
using namespace std;

long long score = 0, cnt = 0;
map<long long, int> a[26];
int cost[26];
string str;

int main() {
	for(int i = 0; i < 26; i++)
		cin >> cost[i];
	cin >> str;

	for(int i = 0; i < (str.size() - 1); i++) {
		score += cost[str[i] - 'a'];
		a[str[i] - 'a'][score]++;
		cnt += a[str[i + 1] - 'a'][score];
	}
	cout << cnt;
	return 0;
}