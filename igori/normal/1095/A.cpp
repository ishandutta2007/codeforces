#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
char c[5000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int v = 0;
    int i = 0;
    for (i = 0; i < n; v++, i += v)
    {
        cout << c[i];
    }
}