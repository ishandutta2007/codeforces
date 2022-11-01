#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
int a[100], b[100];
int main() {
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        copy_n(istream_iterator<int>(cin), n, a);
        b[max_element(a, a + n) - a]++;
    }
    cout << int(max_element(b, b + n) - b) + 1 << endl;
}