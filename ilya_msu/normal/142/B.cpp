#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;


long long fu (long long a, long long b, long long c) {
        return 2 * a * b + 2 * a * c + b * c - 4 * a - 2 * b - 2 * c + 4;
}

int main() {
        int n, m;
        cin >> n >> m;
        if (m > n)
                swap(n, m);
        if (m == 1) {
                cout << n << endl;
                return 0;
        }
        if (n == 2) {
                cout << 4 << endl;
                return 0;
        }
		if (m == 2) {
			if (n % 4 == 0)
				cout << n << endl;
			if (n % 4 == 1)
				cout << n + 1 << endl;
			if (n % 4 == 2)
				cout << n + 2 << endl;
			if (n % 4 == 3)
				cout << n + 1 << endl;
			return 0;
		}
        cout << (m * n + 1) / 2 << endl;
        return 0;
}