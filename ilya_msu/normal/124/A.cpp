#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int m = min(n - a, b + 1);
    if (m < 0)
        cout << 0 << endl;
    else
        cout << m << endl;
    return 0;
}