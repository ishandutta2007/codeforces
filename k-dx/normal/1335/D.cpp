#include <bits/stdc++.h>
using namespace std;

string t[10];

char getx(char a) {
	return a == '1' ? '2' : '1';
}

int main () {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int ti;
	cin >> ti;
	while (ti--) {
		for (int i = 0; i < 9; i++)
			cin >> t[i];

		t[0][0] = getx(t[0][0]);
		t[1][3] = getx(t[1][3]);
		t[2][6] = getx(t[2][6]);
		t[3][1] = getx(t[3][1]);
		t[4][4] = getx(t[4][4]);
		t[5][7] = getx(t[5][7]);
		t[6][2] = getx(t[6][2]);
		t[7][5] = getx(t[7][5]);
		t[8][8] = getx(t[8][8]);

		for (int i = 0; i < 9; i++)
			cout << t[i] << "\n";
	}

	return 0;
}