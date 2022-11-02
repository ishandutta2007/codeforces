#include <iostream>
using namespace std;

int n;
int a[1010];

int main(){
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    int ans = 0;
    for( int i = 2 ; i < n ; i++ ){
        if( a[i-1] > a[i]  &&  a[i] < a[i+1] ) ans++;
        if( a[i-1] < a[i]  &&  a[i] > a[i+1] ) ans++;
    }
    cout << ans << endl;
    return 0;
}