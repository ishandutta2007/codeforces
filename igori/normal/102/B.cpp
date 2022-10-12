#include <iostream>
#include <string>

using namespace std;

long long n, ans;
string s;

int ds(long long n)
{
    long long c = 0;
    while (n > 0)
    {
        c += n % 10;
        n /= 10;
    }
    return c;
}

int main()
{
    cin >> s;
    if (s.size() == 1)
    {
        cout << 0;
        return 0;
    }
    ans = 1;
    for (int i = 0; i < s.size(); i++)
    {
        n = n + s[i] - '0';
    }
    while (n >= 10)
    {
        n = ds(n);
        ans++;
    }
    cout << ans;
}