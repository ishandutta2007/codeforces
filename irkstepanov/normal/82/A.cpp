#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;

int main()
{

    int x;
    cin >> x;

    while (x > 5)
    {
        x -= 5;
        if (x % 2) ++x;
        x /= 2;
    }

    string s[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    cout << s[x - 1];

}