#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, br=0;
    cin >> n;
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            int c = a^b;
            if(c < a+b && a < b+c && b < a+c && c<=n){
               br++;
            }
        }
    }
    cout << br/6;
    return 0;
}