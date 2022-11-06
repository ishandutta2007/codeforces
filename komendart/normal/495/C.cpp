#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    string s;
    cin >> s;
    s += '.';
    
    vector<int> result;
    
    vector<int> braces;
    
    for (int i = 0; i < s.size(); i ++ )
    {
        if (s[i] == '(')
        {
           braces.push_back(i);
        }
        else if (s[i] == ')')
        {
            if (braces.empty())
            {
                cout << -1 << endl;
                return 0;
            }
            s[braces.back()] = '.';
            s[i] = '.';
            braces.pop_back();
        }
    }
    
    vector<char> t;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            cout << -1 << endl;
            return 0;
        }
        if (s[i] != '.') t.push_back(s[i]);
    }
    if (t.back() != '#')
    {
        cout << -1 << endl;
        return 0;
    }
    
    bool good = true;
    int balance = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '(')
        {
           balance++;
        }
        else if (t[i] == '#')
        {
            if (balance == 0)
            {
                good = false;
                break;
            }
            if (i != t.size() - 1)
            {
                result.push_back(1);
                balance--;
            }
            else
            {
                result.push_back(balance);
                balance = 0;
            }
        }
    }
    
    if (balance > 0 || !good)
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < result.size(); i ++)
        {
            cout << result[i] << endl;
        }
    }
}