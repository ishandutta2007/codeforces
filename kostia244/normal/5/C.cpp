#include <bits/stdc++.h>
using namespace std;

int d[1000005], c[1000005];
string str;
stack<int> a;

int main() {
	memset(d, -1, sizeof(d));
	memset(c, -1, sizeof(c));
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			a.push(i);
			c[i] = d[i] = -1;
		} else {
			if (a.empty())
				d[i] = -1;
			else {
				d[i] = a.top();
				a.pop();
				c[i] = d[i];
				if (str[d[i] - 1] == ')' && c[d[i] - 1] != -1) {
					c[i] = c[d[i] - 1];
				}
			}
		}
	}
	int b = 0, bc = 1;

	for (int i = 0; i < str.size(); i++) {
		if(c[i] != -1 &&  (i - c[i] + 1) >= b)
			if((i - c[i] + 1) == b)
				bc++;
			else
				b = (i - c[i] + 1), bc = 1;
	}

	if(b == 0)
		bc = 1;

	cout << b << " " << bc;

	return 0;
}