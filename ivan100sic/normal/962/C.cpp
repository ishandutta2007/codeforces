#include <iostream>
#include <set>
 
#define MAX 2000000000
 
using namespace std;
 
set<long long> s;
void prep() {
    long long x = 1;
    while (x*x <= MAX) {
        s.insert(x*x);
        x++;
    }
}
 
int cnt(long long x) {
    int c = 0;
    while (x > 0) {
        c++;
        x/=10;
    }
    return c;
}
 
long long result = -1;
int broj[15], cif;
bool b[15];
void check() {
    long long tr = 0;
    for (int i = 1; i <= cif; i++) {
        if (b[i]) tr*=10, tr+=broj[i];
    }
    if (s.find(tr) != s.end()) result = max(result, tr);
}
 
void bt(int c) {
    if (c == 0) check();
    else {
        b[c] = true;
        bt(c-1);
        b[c] = false;
        bt(c-1);
    }
}
 
long long n;
int main()
{
    prep();
    cin >> n;
    cif = cnt(n);
    for (int i = cif; i > 0; i--) {
        broj[i] = n%10;
        n/=10;
    }
    bt(cif);
    if (result == -1) cout << -1;
    else {
        cout << cif-cnt(result);
    }
    return 0;
}