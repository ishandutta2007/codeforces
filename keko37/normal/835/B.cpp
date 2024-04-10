#include<iostream>
#include<algorithm>

using namespace std;

int k, len, sol, sum;
string s;

int main () {
	cin >> k >> s;
	len=s.size();
	sort(s.begin(), s.end());
	for (int i=0; i<len; i++) {
		sum+=s[i]-'0';
	}
	while (sum<k) {
		sum+=9-(s[sol]-'0');
		sol++;
	}
	cout << sol;
	return 0;
}