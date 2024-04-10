#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long ts, tf, t, n, sol=1e18, bx=-1;
	long long jebise;
	cin >> ts >> tf >> t >> n;

	jebise = tf - t;

	vector<long long> a(n);
	vector<long long> zavrsava(n);

	if (n == 0) {
		cerr << __LINE__ << '\n';
		cout << ts;
		return 0;
	}

	for (long long i=0; i<n; i++) {
		cin >> a[i];
	}

	if (a[0] > ts) {
		cerr << __LINE__ << '\n';
		cout << ts;
		return 0;
	}

	bx = a[0] - 1;
	sol = ts - bx;

	// ako postoji negde rupa u rasporedu
	long long wrk = ts;
	for (long long i=0; i<n; i++) {
		if (wrk < a[i] && wrk <= jebise) {
			cerr << __LINE__ << '\n';
			cout << wrk;
			return 0;
		} else {
			zavrsava[i] = (wrk += t);
		}
	}

	if (wrk <= jebise) {
		cerr << __LINE__ << '\n';
		cout << wrk;
		return 0;
	}

	// resenje je vece od 0
	// ali koliko?

	for (long long i=0; i<n; i++) {
		// hocu da dodjem odmah posle ovog, osim ako posle
		// njega nije jos jedan isti takav. A docicu
		// u trenutku a[i+1] - 1
		if (i < n-1 && a[i] != a[i+1]) {
			long long cekam = zavrsava[i] - (a[i+1] - 1);
			if (cekam < sol && a[i+1] - 1 <= jebise) {
				sol = cekam;
				bx = a[i+1] - 1;
			}
		}
	}

	cerr << __LINE__ << '\n';
	cout << bx;


}