#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c;
    cin >> a >> b >> c;
    cout << 2*c+2*min(a,b)+(max(a,b)!=min(a,b));
    return 0;
}