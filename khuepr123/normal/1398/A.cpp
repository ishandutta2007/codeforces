#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t; int n; int a[100000];
    for(int o = 0; o < t; o++){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(a[0] + a[1] > a[n - 1]){
            cout << -1 << "\n";
        }
        else{
            cout << 1 << " " << 2 << " " << n << "\n";
        }
    }
}