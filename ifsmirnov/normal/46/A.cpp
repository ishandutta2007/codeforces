#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    int cur = 1;
    for (int i = 0; i < n - 1; i++)
    {
        cout << (cur % n) + 1 << endl;
        cur = (cur + i + 2);
    }
    return 0;
}