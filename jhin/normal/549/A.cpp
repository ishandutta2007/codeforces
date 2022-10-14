#include <bits/stdc++.h>

using namespace std;

char s[52][52];
bool b[26];

int main()
{
    int n , m;
    scanf("%d%d" , &n , &m);
    for(int i=0 ; i<n ; i++)
        scanf("%s" , &s[i]);
    if(n == 1 || m == 1)
        return printf("0") , 0;
    int res = 0;
    for(int i=0 ; i<n-1 ; i++)
    {
        for(int j=0 ; j<m-1 ; j++)
        {
            int cnt = 0;
            if(s[i][j] == 'a' || s[i][j] == 'f' || s[i][j] == 'c' || s[i][j] == 'e')
            {
                if(!b[s[i][j]-'a'])
                {
                    cnt++;
                    b[s[i][j]-'a'] = true;
                }
            }
            if(s[i][j+1] == 'a' || s[i][j+1] == 'f' || s[i][j+1] == 'c' || s[i][j+1] == 'e')
            {
                if(!b[s[i][j+1]-'a'])
                {
                    cnt++;
                    b[s[i][j+1]-'a'] = true;
                }
            }
            if(s[i+1][j+1] == 'a' || s[i+1][j+1] == 'f' || s[i+1][j+1] == 'c' || s[i+1][j+1] == 'e')
            {
                if(!b[s[i+1][j+1]-'a'])
                {
                    cnt++;
                    b[s[i+1][j+1]-'a'] = true;
                }
            }
            if(s[i+1][j] == 'a' || s[i+1][j] == 'f' || s[i+1][j] == 'c' || s[i+1][j] == 'e')
            {
                if(!b[s[i+1][j]-'a'])
                {
                    cnt++;
                    b[s[i+1][j]-'a'] = true;
                }
            }
            if(cnt == 4)
                res++;
            b[s[i+1][j]-'a'] = false;
            b[s[i+1][j+1]-'a'] = false;
            b[s[i][j+1]-'a'] = false;
            b[s[i][j]-'a'] = false;
        }
    }
    printf("%d" , res);
    return 0;
}