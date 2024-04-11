#include <bits/stdc++.h>
using namespace std;


int n, dc = 0, an = 0;
string a[] = {"RGB", "RBG", "BRG", "BGR", "GBR", "GRB"}, s;
int ed[6] = {0, };


int main() {
	cin >> n;
	cin >> s;
	s += "   ";
	for(int i = 0; i < n; i += 3) {
		for(int j = 0; j < 6; j++) {
			ed[j] += (s[i] != a[j][0]);
			ed[j] += (s[i + 1] != a[j][1]);
			ed[j] += (s[i + 2] != a[j][2]);
			if(ed[j] < ed[an])
				an = j;
		}
	}
	cout << (ed[an] - ((3 - (n%3))%3)) << "\n";
	for(int i = 0; i < n; i++)
		cout << a[an][i%3];
}