#include <bits/stdc++.h>
using namespace std;

int a, b;

int main(){
    ios_base::sync_with_stdio(false);

    cin >> a >> b;
    if(a*log(b)==b*log(a)) cout << "=";
    else if(b*log(a)>a*log(b)) cout << ">";
    else cout << "<";

    return 0;
}