#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        int p1, p2;
        cin >> s1 >> p1 >> s2 >> p2;
        while (s1.size() < s2.size() && p1)
        {
            s1.push_back('0');
            p1--;
        }
        while (s2.size() < s1.size() && p2)
        {
            s2.push_back('0');
            p2--;
        }
        if (s1.size() < s2.size())
        {
            cout << "<\n";
        }
        if (s1.size() > s2.size())
        {
            cout << ">\n";
        }
        if (s1.size() == s2.size())
        {
            if (p1 < p2)
            {
                cout << "<\n";
            }
            if (p1 > p2)
            {
                cout << ">\n";
            }
            if (p1 == p2)
            {
                if (s1 < s2)
                {
                    cout << "<\n";
                }
                if (s1 > s2)
                {
                    cout << ">\n";
                }
                if (s1 == s2)
                {
                    cout << "=\n";
                }
            }
        }
    }
}