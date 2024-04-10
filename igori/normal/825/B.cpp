#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string s[10];

int main()
{
    for (int i = 0; i < 10; i++)
        cin >> s[i];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (s[i][j] == '.')
            {
                int l = 0;
                for (int k = 1; k <= 5; k++)
                {
                    if (i + k < 10 && s[i + k][j] == 'X')
                        l++;
                    else
                        break;
                }
                for (int k = 1; k <= 5; k++)
                {
                    if (i - k >= 0 && s[i - k][j] == 'X')
                        l++;
                    else
                        break;
                }
                if (l >= 4)
                {
                    cout << "YES";
                    return 0;
                }
                l = 0;
                for (int k = 1; k <= 5; k++)
                {
                    if (i + k < 10 && j + k < 10 && s[i + k][j + k] == 'X')
                        l++;
                    else
                        break;
                }
                for (int k = 1; k <= 5; k++)
                {
                    if (i - k >= 0 && j - k >= 0 && s[i - k][j - k] == 'X')
                        l++;
                    else
                        break;
                }
                if (l >= 4)
                {
                    cout << "YES";
                    return 0;
                }
                l = 0;
                for (int k = 1; k <= 5; k++)
                {
                    if (j + k < 10 && s[i][j + k] == 'X')
                        l++;
                    else
                        break;
                }
                for (int k = 1; k <= 5; k++)
                {
                    if (j - k >= 0 && s[i][j - k] == 'X')
                        l++;
                    else
                        break;
                }
                if (l >= 4)
                {
                    cout << "YES";
                    return 0;
                }
                l = 0;
                for (int k = 1; k <= 5; k++)
                {
                    if (i - k >= 0 && j + k < 10 && s[i - k][j + k] == 'X')
                        l++;
                    else
                        break;
                }
                for (int k = 1; k <= 5; k++)
                {
                    if (i + k < 10 && j + k >= 0 && s[i + k][j - k] == 'X')
                        l++;
                    else
                        break;
                }
                if (l >= 4)
                {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}