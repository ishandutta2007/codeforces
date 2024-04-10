#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;



int main() {
    long long k, l;
    cin >> k >> l;
    long long x = k;
    int i = 0;
    while (x < l) {
        x *= k;
        ++i;
    }
    if (x == l) 
        cout << "YES" << endl << i << endl;
    else
        cout << "NO" << endl;
    return 0;
}