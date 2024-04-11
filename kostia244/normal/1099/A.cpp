#include <bits/stdc++.h>
using namespace std;

int w, h, w1, h1, w2, h2;
int main() {
	cin >> w >> h >> w1 >> h1 >> w2 >> h2;
	while(h) {
		w += h;
		if(h == h1)
			w = max(0, w - w1);
		if(h == h2)
			w = max(0, w - w2);
		h--;
	}
	cout << w;
	return 0;
}