// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool not1(const string& s) {
	if (s.size() > 1)
		return true;
	return s != "1";
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	 string s;
	 cin >> s;
	 int a = 0;
	 while (not1(s)) {
		 a++;
		 if (s.back() == '1') {
			 int j = s.size() - 1;
			 while (j > 0 && s[j-1] == '1') {
				 j--;
			 }

			 fill(s.begin()+j, s.end(), '0');
			 if (j == 0) {
				 s = string("1") + s;
			 } else {
				 s[j-1] = '1';
			 }
		 } else {
			 s.pop_back();
		 }
	 }

	 cout << a << '\n';
}