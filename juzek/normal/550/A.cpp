#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int N = s.length();
    bool ab = false,ba = false;

    for (int i = 0;i < N;i++)
    {
        if (ab == false)
        {
            if (s[i] == 'A' && s[i+1] == 'B')
            {
                ab = true;
                i++;
            }
        }
        else
        {
            if (s[i] == 'B' && s[i+1] == 'A')
                ba = true;
        }
    }
    if (ab && ba)
        printf("YES");
    else
    {
        ab = false;
        ba = false;
        for (int i = 0;i < N;i++)
        {
            if (ba == true)
            {
                if (s[i] == 'A' && s[i+1] == 'B')
                {
                    ab = true;
                }
            }
            else
            {
                if (s[i] == 'B' && s[i+1] == 'A')
                {
                    ba = true;
                    i++;
                }
            }
        }
        if (ab && ba)
            printf("YES");
        else
            printf("NO");

    }


    return 0;
}