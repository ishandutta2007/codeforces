#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<long long> loc;
long long n, m, V = 0;

class Truck {
private:
	long long s, f, c, r;
public:
	void get() {
		cin >> s >> f >> c >> r;
		s--, f--;
	}
	long long cost(long long pos) {
		return (loc[pos + 1] - loc[pos]) * c;
	}
	bool can(long long cap) {
		long long cur = cap, tr = r;
		for (int pos = s; pos < f; pos++) {
			if (cost(pos) > cap)
				return false;
			if (cost(pos) > cur)
				if (tr--)
					cur = cap;
				else
					return false;
			cur -= cost(pos);
		}
		return true;
	}
	long long getmin() {
		long long lo = V, hi = 1000000000000000000ll, mid;
		while(lo + 1 < hi) {
			mid = (lo + hi) / 2;
			if(can(mid))
				hi = mid;
			else
				lo = mid;
		}
		return hi;
	}
};

vector<Truck> trucks;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	loc.resize(n);
	for (auto& i : loc)
		cin >> i;
	trucks.resize(m);
	for(auto& i : trucks)
		i.get();
	shuffle(trucks.begin(), trucks.end(), rng);
	for(int i = 0; i < m; i++)
		if(!trucks[i].can(V))
			V = trucks[i].getmin();
	cout << V;
}