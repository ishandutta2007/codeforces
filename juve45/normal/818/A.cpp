#include <iostream>

using namespace std;

long long n, k;
int main()
{
    cin >> n >> k;
    long long f = n/2;
    f /= (k+1);
    cout << f << ' ' << f * k << ' ' << n - f*(k+1);
    
}