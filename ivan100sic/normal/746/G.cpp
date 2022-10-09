#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, t, k; 
int a[200005];

vector<int> nivo[200005];
vector<pair<int, int>> e;

int main() {
	cin >> n >> t >> k;
	for (int i=1; i<=t; i++) {
		cin >> a[i];
	}

	int k_min, k_max;
	k_max = n-t;
	k_min = 0;
	for (int i=2; i<=t; i++) {
		// koliko ostaje iz prethodnog sloja?
		int raz = a[i-1] - a[i];
		if (raz > 0) {
			k_min += raz;
		}
	}
	k_min += a[t];
	cerr << k_min << ' ' << k_max << '\n';
	if (k < k_min || k > k_max) {
		cout << -1;
		return 0;
	}

	{
		int cvor = 1;
		int preko = k - k_min;
		
		/*
			pri pakovanju cvorova sa minimalno listova
			dobija se da ima k_min listova

			ako hocemo da ima vise listova od ovoga,
			na svakom nivou, pogledamo koliko najmanje
			i najvise listova mozemo da imamo na prethodnom


		*/

		for (int i=1; i<=a[1]; i++) {
			++cvor;
			nivo[1].push_back(cvor);
			e.push_back({1, cvor});
		}
		for (int l=2; l<=t; l++) {
			int pre_min = max(a[l-1] - a[l], 0);
			int pre_max = a[l-1] - 1;

			// sada se odlucujem za broj listova u prethodnom
			// nivou.
			int pre = pre_min + preko;
			if (pre > pre_max) {
				pre = pre_max;
			}

			preko -= pre - pre_min;

			int prepun = a[l-1] - pre;

			// sad popunjavam prvi prolaz
			for (int i=0; i<prepun; i++) {
				++cvor;
				nivo[l].push_back(cvor);
				e.push_back({cvor, nivo[l-1][i]});
			}

			// sve sto nisam popunio sad popunim
			for (int i=0; i<a[l]-prepun; i++) {
				++cvor;
				nivo[l].push_back(cvor);
				e.push_back({cvor, nivo[l-1][0]});
			}
		}
		cout << n << '\n';
		for (auto p : e) {
			cout << p.first << ' ' << p.second << '\n';
		}
	}
}