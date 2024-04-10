#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, s=0, t1=0, t2;
    cin >> n >> t2;
    s+=(2*n+t2-1);
    for(int a=1; a<n; a++) {
        t1=t2;
        cin >> t2;
        s+=(abs(t1-t2));
    }
    cout << s;
}