#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string b[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string c[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
	"eighteen", "nineteen"};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	if (n == 0)
		cout << "zero\n";
	else if (n < 10)
		cout << b[n-1] << '\n';
	else if (n == 10)
		cout << "ten\n";
	else if (n < 20)
		cout << c[n-11] << '\n';
	else
		cout << a[n/10-2] << (n % 10 ? string("-") + b[n%10-1] : "") << '\n';
}