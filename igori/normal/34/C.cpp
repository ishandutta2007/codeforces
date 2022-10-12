#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define prev prevfff

int yay[4000];

int main()
{
    string s;
    cin >> s;
    int k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ',')
        {
            yay[k] = 1;
            k = 0;
        }
        else
        {
            k = 10 * k + s[i] - '0';
        }
    }
    yay[k] = 1;
    int t = 0;
    for (int i = 1; i <= 1001; i++)
    {
        if (yay[i])
        {
            for (int j = i; j <= 1001; j++)
            {
                if (yay[j] == 0)
                {
                    if (t) cout << ",";
                    t = 1;
                    if (i == j - 1)
                        cout << i;
                    else
                        cout << i << "-" << j - 1;
                    i = j - 1;
                    break;
                }
            }
        }
    }
}