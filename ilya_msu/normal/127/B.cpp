#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;





int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    int p = 0;
    int x = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (data[i] == data[i + 1])
            ++x;
        else {
            p += (x / 2);
            x = 1;
        }
    }
    p += (x / 2);
    cout << p / 2 << endl;
    return 0;
}