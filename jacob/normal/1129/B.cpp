#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
		int k;
		in >> k;
		for (int b = 1999; b >= 0; --b) {
			int kb = k + b;
			int a = 2000 - b;
			while (kb % a != 0) {
				--a;
			}
			int y = kb / a + 1;
			if (y > 1000000 * b) {
				continue;
			}
			out << a + b << endl;
			for (int i = 0; i < a - 1; ++i)
				out << "0 ";
			out << "-1";
			int ry = 0;
			for (int i = 0; i < b; ++i) {
				int r = y / b;
				if (i < y % b)
					++r;
				ry += r;
				out << " " << r;
			}
			out << endl;
			int tst = (ry - 1) * (a + b) - ry * b;
			return;
		}
		abort();
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}