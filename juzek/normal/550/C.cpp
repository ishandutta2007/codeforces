#include <bits/stdc++.h>
using namespace std;


bool czy1(int a)
{
    if (a%8 == 0)
        return true;
    else
        return false;
}

bool czy2(int b,int a)
{
    if ((b*2+a)%8 == 0 && b != 0)
        return true;
    else
        return false;
}

bool czy3(int c,int b,int a)
{
    if ((c*4+b*2+a)%8 == 0 && c != 0)
        return true;
    else
        return false;
}


int main()
{
    string s;
    cin >> s;
    int N = s.length();
    for (int i = 0; i < N;i++)
        s[i] -= '0';
    for (int i = 0;i < N;i++)
    {
        for (int w = i+1;w < N;w++)
        {
            for (int z = w+1;z < N;z++)
            {
                if (czy3(s[i],s[w],s[z]))
                {
                    printf("YES\n");
                    printf("%d%d%d",s[i],s[w],s[z]);
                    return 0;
                }
            }
            if (czy2(s[i],s[w]))
            {
                    printf("YES\n");
                printf("%d%d",s[i],s[w]);
                return 0;
            }
        }
        if (czy1(s[i]))
        {
            printf("YES\n");
            printf("%d",s[i]);
            return 0;
        }
    }
    printf("NO\n");
}