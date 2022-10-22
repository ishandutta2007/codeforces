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
    int sum = 0;
    for(int i=2; i<n; i++){
        sum += i*(i+1);
    }
    cout << sum;
    return 0;
}