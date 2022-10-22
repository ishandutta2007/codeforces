#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    // ovde ne radi
    if(n <= 5) cout << "-1\n";
    else{
        cout << "1 2\n2 3\n2 4\n4 5\n4 6\n";
        for(int i=7; i<=n; i++) cout << "2 " << i << "\n";
    }
    // ovde radi
    for(int i=2; i<=n; i++) cout << "1 " << i << "\n";
    return 0;
}