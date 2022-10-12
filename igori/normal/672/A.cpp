#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "123456789";
    for (int i = 10; i < 100; i++)
    {
        s += (char)(i / 10 + '0');
        s += (char)(i % 10 + '0');
    }
    for (int i = 100; i < 1000; i++)
    {
        s += (char)(i / 100 + '0');
        s += (char)(i / 10 % 10 + '0');
        s += (char)(i % 10 + '0');
    }
    int n;
    cin >> n;
    cout << s[n - 1];
}