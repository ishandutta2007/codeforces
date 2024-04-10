#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    double mini, a, b, m, n;
    cin >> n >> m;
    cin >> a >> b;
    mini = a/b;
    n--;
    while(n--){
        cin >> a >> b;
        mini = min(mini, a/b);
    }
    cout << mini*m;
    return 0;
}