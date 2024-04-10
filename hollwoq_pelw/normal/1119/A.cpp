#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n],l1=0,r1=n-1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l2 = 0, r2 = n-1;
    while(a[l1++] == a[r1]){}
    while(a[l2] == a[r2--]){}
    cout << max(r2-l2+1, r1-l1+1);
    return 0;
}