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
    int br=0;
    br += n/100;
    n %= 100;
    br += n/20;
    n %= 20;
    br += n/10;
    n %= 10;
    br += n/5;
    n %= 5;
    br += n/1;
    n %= 1;
    cout << br;
    return 0;
}