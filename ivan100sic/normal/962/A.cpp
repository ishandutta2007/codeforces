#include <iostream>
 
using namespace std;
 
long long n, sum, tr, a[200005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) (cin >> a[i]), sum+=a[i];
    for (int i = 1; i <= n; i++) {
        tr+=a[i];
        if (2*tr >= sum) {
            cout << i;
            return 0;
        }
    }
    return 0;
}