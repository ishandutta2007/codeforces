#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int a[k] = {0}, m;
    for (int i = 0; i < n; i++){
        cin >> m;
        a[m%k] ++;
    }
    int s = a[0]/2+(k%2==0)*(a[k/2]/2);
    for (int i = 1; i < (k+1)/2; i++){
        s += min(a[i], a[(k-i)]);
    }
    cout << s*2;
}