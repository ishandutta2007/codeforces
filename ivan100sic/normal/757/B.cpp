#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int fsf[100005];

void sito() {
	for (long long i=2; i<100005; i++) {
		if (fsf[i] == 0) {
			fsf[i] = i;
			for (long long j=i*i; j<100005; j+=i) {
				if (fsf[j] == 0) {
					fsf[j] = i;
				}
			}
		}
	}
}

int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	sito();
	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		set<int> f;
		while (x > 1) {
			int y = fsf[x];
			f.insert(y);
			x /= y;
		}
		for (int y : f) {
			a[y]++;
		}
	}

	int p = max(*max_element(a, a+100005), 1);

	cout << p;

}