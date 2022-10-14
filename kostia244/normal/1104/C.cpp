#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define ll long long
using namespace std;

string s;
int cv = 0, ch = 0;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> s;
	for(size_t i = 0; i < s.size(); i++) {
		if(s[i] == '0') {
			cv &= 1;
			printf("%d 1\n", 1 + (2 * cv));
			cv++;
		}else {
			ch %= 4;
			printf("%d 2\n", 1 + ch);
			ch++;
		}
	}
}