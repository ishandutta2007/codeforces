#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, x, y;

int ask(vector<int> q) {

	if (q.size() == 0) {
		return 0;
	}

	cout << "? " << q.size();
	for (int x : q) {
		cout << ' ' << x;
	}
	cout << '\n' << flush;

	// citaj odgovor
	int resp;
	cin >> resp;

	if (q.size() % 2) {
		resp ^= x;
	}

	return resp != 0;
}

vector<int> dajvec(int bit) {
	vector<int> q;
	for (int i=1; i<=n; i++) {
		if (i & (1<<bit)) {
			q.push_back(i);
		}
	}

	return q;
}

int par(int bit) {
	return ask(dajvec(bit));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> x >> y;

	int bitraz = 0;
	for (int i=0; i<10; i++) {
		if (par(i)) {
			bitraz ^= (1 << i);
		}
	}

	int nekibit = 0;
	while (!((1 << nekibit) & bitraz)) {
		nekibit++;
	}

	// sad znamo da jedan od brojeva ima bit 0 na poziciji nekibit, nadjimo
	// ostale bitove ovog broja

	vector<int> vec = dajvec(nekibit);

	while (vec.size() > 1) {
		auto it = vec.begin() + (vec.end() - vec.begin()) / 2;

		int ans = ask(vector<int>(vec.begin(), it));

		if (ans) {
			vec = vector<int>(vec.begin(), it);
		} else {
			vec = vector<int>(it, vec.end());
		}
	}

	int a = vec[0];
	int b = a ^ bitraz;

	if (a > b) {
		swap(a, b);
	}

	cout << "! " << a << ' ' << b << '\n' << flush;
}