#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    string a;
    cin >> a;
    while(k){
        k--;
        int i = n-1;
        while(i>0){
            if (a[i] == 'G' && a[i-1] == 'B'){
                a[i] = 'B';
                a[i-1] = 'G';
                i --;
            }
            i--;
        }
    }
    cout << a;
    return 0;
}