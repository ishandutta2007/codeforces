#include <bits/stdc++.h>
using namespace std;

int a[300010];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n); n--;
    cout << a[n / 2];
}