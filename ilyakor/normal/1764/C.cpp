/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <functional>
#include <sstream>
#include <cmath>

#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

template<class T> T abs(T x) { return x >= 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

class TaskC {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n;
	    in >> n;
        unordered_map<int, int> d;
	    for (int i = 0; i < n; ++i) {
	        int x;
	        in >> x;
	        d[x] += 1;
	    }
	    vector<ii> a;
	    for (auto e : d)
	        a.pb(ii(e.first, e.second));
	    sort(all(a));
	    int64 res = 0, sum = 0;
	    for (ii e : a) {
//	        res += sum * e.second;
	        sum += e.second;
	    }
	    if (sz(a) == 1) {
	        res += a[0].second / 2;
	    } else {
	        int64 best = 0;
	        int64 s = 0;
	        for (ii e : a) {
	            s += e.second;
	            sum -= e.second;
	            int64 cur = s * sum;
	            best = max(best, cur);
	        }
	        res += best;
	    }
	    out << res << "\n";
	}
};


int main() {
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}