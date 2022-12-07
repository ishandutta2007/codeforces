#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    while(n) {
        v.push_back(n % 2);
        n /= 2;
    }
    while(v.size() < 6) {
        v.push_back(0);
    }
    vector<int> w {v[4], v[1], v[3], v[2], v[0], v[5]};

    for(int i= 0; i<= 5; i++) n += (1 << i) * w[i];
    cout << n << "\n";

}