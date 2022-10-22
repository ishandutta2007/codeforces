#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> prices;

int main() {
    long long int n, p, s=0;
    cin >> n;
    for(long long int a=0; a<n; a++) {
        cin >> p;
        prices.push_back(p);
        s+=p;
    }
    sort(prices.rbegin(), prices.rend());
    cin >> n;
    for(long long int a=0; a<n; a++) {
        cin >> p;
        cout << s-prices[p-1] << '\n';
    }
}