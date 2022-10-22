#include <bits/stdc++.h>

using namespace std;

int ord(long long int n, int ex) {
    int o=0;
    while(n%ex==0) {
        n/=ex;
        o++;
    }
    return o;
}

pair<int, long long int> arr[101];

int main() {
    int n, num;
    cin >> n;
    for(int a=0; a<n; a++) {
        cin >> arr[a].second;
        arr[a].first=ord(arr[a].second, 3)*-10000+ord(arr[a].second, 2);
    }
    sort(arr, arr+n);
    for(int a=0; a<n; a++) {
        cout << arr[a].second << ' ';
    }
}