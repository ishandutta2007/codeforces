#include <iostream>

using namespace std;

int a, b;

int nonule(int n)
{
    int ans = 0;
    int q1 = 1;
    int q2 = 1;
    for (int i = 0; i < 10; i++)
    {
        int x = (n / q1) % 10;
        if (x != 0)
        {
            ans += q2 * x;
            q2 = q2 * 10;
        }
        q1 = q1 * 10;
    }
    return ans;
}

int main()
{
    cin >> a >> b;
    if (nonule(a) + nonule(b) == nonule(a + b))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}