#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{

    int n;
    cin >> n;

    while (1)
    {
        n++;
        int a = n % 10, b = (n / 10) % 10, c = (n / 100) % 10, d = n / 1000;
        if (a != b && a != c && a != d && b != c && b != d && c != d) {cout << n; return 0;}
    }

}