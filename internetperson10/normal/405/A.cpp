#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int main() {
    int n, c;
    cin >> n;
    while(n--) {
        cin >> c;
        arr.push_back(c);
    }
    sort(arr.begin(), arr.end());
    for(n=0; n<arr.size(); n++) {
        cout << arr[n] << ' ';
    }
}