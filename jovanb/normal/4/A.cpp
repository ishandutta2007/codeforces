#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, i, j;
    cin >> n;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i+j == n){
                if(i%2 == 0 && j%2 == 0){
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}