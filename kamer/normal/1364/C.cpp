#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n);
    vector<int> count(n + 10, 0);
    a[0] = 0;
    for (int i = 0; i < n; i++) {cin >> a[i + 1]; count[a[i + 1]] = 1; }
    if (a[n] > 0) count[0] = 1;
    vector<int> indices;
    indices.push_back(-1);
    for (int i = 0; i < n; i++) {
        if (a[i] < a[i + 1]) {b[i] = a[i]; indices.push_back(i); }
    }
    indices.push_back(n);
    int currValue = 0;
    for (int i = 0; i < indices.size() - 1; i++) {
        int l = indices[i];
        int r = indices[i + 1];
        for (int j = l + 1; j < r; j++) {
            while (count[currValue] == 1) currValue++;
            b[j] = currValue;
            currValue++;
        }
    }
    for (int i = 0; i < n; i++) cout << b[i] << " ";

}