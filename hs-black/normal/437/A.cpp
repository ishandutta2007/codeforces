#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
string A[6];
bool xiu[6];
int len[6];
int main() {
	for (int i = 1;i <= 4; i++) {	
		cin >> A[i];
		len[i] = A[i].size() - 2;
	}
	int cnt = 0;
	for (int i = 1;i <= 4; i++) {
		bool flag1 = 1,flag2 = 1;
		for (int j = 1;j <= 4; j++) {
			if (i == j) continue;
			if (len[i] < len[j] * 2) flag1 = false;
			if (len[i] * 2 > len[j]) flag2 = false;
		}
		xiu[i] = flag1 | flag2;
		if (xiu[i]) cnt++;
	}
	if (cnt == 1)
	for (int i = 1;i <= 4; i++) {
		if (xiu[i]) {
			cout << (char)('A' + i - 1) << endl;
			return 0;
		}
	}
	cout << 'C' << endl;
	return 0;
}