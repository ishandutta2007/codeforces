#include <bits/stdc++.h>

using namespace std;

int taken[100010];
int arr[100010];
int distinct[100010];

int main() {
    int n, q, x;
    cin >> n >> q;
    for(int a=0; a<n; a++) {
        cin >> arr[a];
    }
    for(int a=n-1; a>-1; a--) {
        if(!taken[arr[a]]) {
            taken[arr[a]]=1;
            distinct[a]=1+distinct[a+1];
        }
        else distinct[a]=distinct[a+1];
    }
    for(int a=0; a<q; a++) {
        cin >> x;
        cout << distinct[x-1] << '\n';
    }
}