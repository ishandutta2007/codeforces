#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << (n*n+1)/2 << "\n";
    if(n%2){
        for(int i=0;i<n*n;i++){
            cout << (i%2 ? '.' : 'C');
            if((i+1)%n==0){
                cout << "\n";
            }
        }
    }else{
        for(int i=0;i<n;i++){
            if(i>0){
                cout << '\n';
            }
            for(int j=0;j<n;j++){
                cout << (((i+j)%2==0) ? 'C' : '.');
            }
        }
    }
}