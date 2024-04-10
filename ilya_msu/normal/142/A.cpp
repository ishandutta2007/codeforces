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
        long long n;
        cin >> n;
        long long mini = 6 * n + 12, maxi = 0;
        for (long long i = 1; i * i * i < n + 1; ++i) {
                if (n % i != 0)
                        continue;
                int m = n / i;
                for (long long j = 1; j * j < m + 1; ++j) {
                        if (m % j != 0) 
                                continue;
                        long long a, b, c;
                        long long k = m / j;
                        a = i + 1;
                        b = j + 2;
                        c = k + 2;
                        long long f = fu(a, b, c);
                        mini = min(mini, f);
                        maxi = max(maxi, f);
                        a = j + 1;
                        b = i + 2;
                        c = k + 2;
                        f = fu(a, b, c);
                        mini = min(mini, f);
                        maxi = max(maxi, f);
                        a = k + 1;
                        b = j + 2;
                        c = i + 2;
                        f = fu(a, b, c);
                        mini = min(mini, f);
                        maxi = max(maxi, f);
                        }
        }
        cout << mini << " " << maxi << endl;
        
        return 0;
}