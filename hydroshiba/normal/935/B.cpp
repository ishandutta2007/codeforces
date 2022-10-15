#include <iostream>
using namespace std;

int main(void)
{
    long long n, x0 = 0, y0 = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, tax = 0;
    cin >> n;
    string S;
    cin >> S;
    for (int i = 0; i < n; i++)
    {
        if (S[i] == 'R')
            x0 += 1;
        if (S[i] == 'U')
            y0 += 1;
        if ((x0 - y0)*(x2 - y2) < 0)
            tax += 1;
        x2 = x1;
        y2 = y1;
        x1 = x0;
        y1 = y0;
    }
    cout << tax;
    return 0;
}