#include <iostream>
#include <cmath>
using namespace std;

int n;

int main(){
    int a[100];
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> a[i];
        if( i != 1 ){
            if( abs(a[i]-a[i-1]) >= 2 ){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}