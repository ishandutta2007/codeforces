#include <iostream>
using namespace std;
int main()
{
    int n;
    long long p;
    cin >> n;
    p = n;
    p = (p*(p+1))*3+1;
    cout << p;
    return 0;
}