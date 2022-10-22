#include <bits/stdc++.h>
using namespace std;

long long a, b, m;

void Input() {
	cin >> a >> b >> m;
}

void Solve() {
	if (a == b) {cout << "1 " << a << endl; return;}
	vector<long long> Min, Max;
	Min.push_back(a); Max.push_back(a);
	int siz = 1;
	for (; siz <= 50; siz++) {
		if (siz == 50) {siz++; break;}
		long long Mn = 1, Mx = m;
		for (int x = 0; x < siz; x++) {
			Mn += Min[x]; Mx += Max[x];
		}
		Min.push_back(Mn); Max.push_back(Mx);
		if (Mn > b) {cout << "-1\n"; return;}
		if (Mn <= b && b <= Mx) {siz++; break;}
	}
	if (siz > 50) {cout << "-1\n"; return;}
	long long curr = Min.back();
	vector<long long> Weight(siz, 1), coef(siz, 1);
	for (int i=2; i<siz; i++) Weight[i] = Weight[i-1] * 2;
	reverse(Weight.begin(), Weight.end());
	for (int i=1; i<siz; i++) {
		long long MaxAllowed = min(m-1, (b - curr) / Weight[i]);
		coef[i] += MaxAllowed; curr += MaxAllowed * Weight[i];
	}
	vector<long long> arr(siz, 0); arr[0] = a;
	for (int i=1; i<siz; i++) {
		for (int j=0; j<i; j++) arr[i] += arr[j];
		arr[i] += coef[i];
	}
	cout << siz;
	for (auto z: arr) cout << " " << z;
	cout << endl;
}

int main(int argc, char* argv[]) {
	int T; 
	cin >> T; 
	while (T--) {Input(); Solve();} 
	return 0;
}