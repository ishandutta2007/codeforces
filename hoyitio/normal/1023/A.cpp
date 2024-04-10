#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    bool ans = true;
    int len = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i]=='*')
        {
            len = 1;
            break;
        }
        if(i >= m||s[i] != t[i])
        {
            ans = false;
            break;
        }
    }
    if((!len&&n!=m)||(len&&n-len>m))
    {
        ans = false;
    }
    for(int i = 1 ; i < n ; i++)
    {
        if(!ans)break;
        if(s[n-i] == '*')
        {
            break;
        }
        if(s[n-i]!=t[m-i])
        {
            ans = false;
            break;
        }
    }
    ans?printf("YES"):printf("NO");
    return 0 ;
}