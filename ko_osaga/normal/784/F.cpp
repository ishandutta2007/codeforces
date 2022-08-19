#include <bits/stdc++.h>
using namespace std;
int n, a[100005];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int p, q, r;
    for(int i=0; i<2000000000; i++){
        r = q;
        q = p;
        p = (p + r);
    }
    srand(p + q + r);
    random_shuffle(a, a+n);
    sort(a, a+n);
    for(int i=0; i<n; i++) cout << a[i] << " ";
}