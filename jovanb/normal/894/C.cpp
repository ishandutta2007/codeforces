#include <bits/stdc++.h>

using namespace std;

int main()
{
    long m, gcd, x[10000],i;
    cin >> m;
    cin >> x[0];
    gcd = x[0];
    for(i=1; i<m; i++){
        cin >> x[i];
        gcd = __gcd(gcd, x[i]);
    }
    if(gcd != x[0]){cout<<-1; return 0;}
    cout << 2*m-1 <<endl;
    for(i=0; i<m-1; i++){
        cout << x[i] << " " << x[0] << " ";
    }
    cout << x[m-1];
    return 0;
}