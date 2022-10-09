// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T>
struct compressor {
	vector<T*> v;
	void operator+=(T& x) { v.push_back(&x); }

	T operator() (T init = T()) {
		sort(v.begin(), v.end(), [](int* x, int* y) { return *x < *y; });
		T last = 0, q = 0;
		for (size_t i=0; i<v.size(); i++) {
			if (!i || *v[i] != last) q++;
			last = *v[i];
			*v[i] = q - 1 + init;
		}
		return q;
	}
};

ull juicer[200005];
char ima[200005];
const int LIM = 60;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  {
    mt19937_64 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int j=0; j<200005; j++) {
      juicer[j] = eng();
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    compressor<int> cpr;
    vector<vector<int>> a(n);
    for (int i=0; i<n; i++) {
      int c;
      cin >> c;
      a[i].resize(c);
      for (int& x : a[i]) {
        cin >> x;
        cpr += x;
      }
      sort(begin(a[i]), end(a[i]));
    }
    cpr(0);

    bool found = false;

    // big - rest
    for (int i=0; i<n && !found; i++) {
      if (a[i].size() > LIM) {
        for (int x : a[i]) {
          ima[x] = 1;
        }
        for (int j=0; j<n && !found; j++) {
          if (j == i) continue;
          int cnt = 0;
          for (int y : a[j]) {
            if (ima[y]) cnt++;
            if (cnt == 2) {
              cout << i+1 << ' ' << j+1 << '\n';
              found = true;
              break;
            }
          }
        }

        for (int x : a[i]) {
          ima[x] = 0;
        }
      }
    }

    if (!found) {
      vector<ull> vt;
      // small - small
      for (int i=0; i<n; i++) {
        int c = a[i].size();
        if (c <= LIM) {
          for (int j=0; j<c; j++) {
            for (int k=j+1; k<c; k++) {
              vt.emplace_back(((juicer[a[i][j]] ^ juicer[a[i][k]]) << 20) ^ i);
            }
          }
        }
      }

      sort(begin(vt), end(vt));
      for (int i=0; i<(int)vt.size()-1; i++) {
        if ((vt[i] >> 20) == (vt[i+1] >> 20)) {
          int x = (vt[i] & 0xfffff);
          int y = (vt[i+1] & 0xfffff);

          // false positive?
          if (x == y) continue;
          int k = set_intersection(a[x].begin(), a[x].end(), a[y].begin(), a[y].end(), ima) - ima;
          fill(ima, ima+k, 0);

          if (k < 2) continue;

          found = true;
          cout << x+1 << ' ' << y+1 << '\n';
          break;
        }
      }
    }

    if (!found) {
      cout << "-1\n";
    }
  }
}