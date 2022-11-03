#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    int a, b;
    cin >> b >> a;
    if(b < a){
        swap(a, b);
    }
    cout << a << " " << (b - a) / 2 << endl;
    return 0;
}