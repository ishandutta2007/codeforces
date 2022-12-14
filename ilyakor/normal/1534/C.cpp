/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <algorithm>
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

constexpr int mod = 1000 * 1000 * 1000 + 7;

class TaskC {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n;
	    in >> n;
	    vi a(n), a1(n), a2(n);
	    for (int i = 0; i < n; ++i)
	        in >> a1[i];
        for (int i = 0; i < n; ++i)
            in >> a2[i];
        for (int i = 0; i < n; ++i)
            a[a1[i] - 1] = a2[i] - 1;
        int res = 0;
        vi u(n);
        for (int i = 0; i < n; ++i) if (!u[i]) {
            int x = i;
            while (!u[x]) {
                u[x] = 1;
                x = a[x];
            }
            ++res;
        }
        int r = 1;
        for (int i = 0; i < res; ++i)
            r = (r * 2) % mod;
        out << r << "\n";
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