#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int p[2*n];
    for (int i = 0; i < 2*n; i++) p[i] = i+1;
    for (int i = 0; i < k; i++){
        swap(p[2*i], p[2*i+1]);
    }
    for (int i = 0; i < 2*n; i++) cout << p[i] << ' ';
    
    return 0;
}