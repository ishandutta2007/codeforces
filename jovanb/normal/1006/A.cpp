#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    int x;
    for(int i=1; i<=n; i++){
        cin >> x;
        if(x%2 == 0) x--;
        cout << x << " ";
    }
    return 0;
}