#include <bits\stdc++.h>


using namespace std;
int ans[100000]={0};
int p[501][501];
int main()
{
    int x,y,x0,y0;
    cin>>x>>y>>x0>>y0;
    string s;
    cin>>s;
    for (int i=0;i<501;i++)
        for (int j=0;j<501;j++)
        p[i][j]=1;
    p[x0][y0]=0;
    ans[0]=1;
    int poses=1;

    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='U')
        {
            if (x0>1)
            {
                x0--;
                if (p[x0][y0]==1)
{

             ans[i+1]++;
            poses++;
                p[x0][y0]=0;


                }
            }

        } else

            if (s[i]=='D')
        {
            if (x0<x)
            {
                x0++;
                if (p[x0][y0]==1)
{

             ans[i+1]++;
                poses++;
                p[x0][y0]=0;


                }
            }
        } else
        if (s[i]=='R')
        {
            if (y0<y)
            {
                y0++;
                if (p[x0][y0]==1)
{

             ans[i+1]++;
            poses++;
                p[x0][y0]=0;


                }
            }
    }
    else if (s[i]=='L')
        {
            if (y0>1)
            {
                y0--;
                if (p[x0][y0]==1)
{

             ans[i+1]++;
            poses++;
                p[x0][y0]=0;


                }
            }
    }
    }
    ans[s.length()]+=x*y-poses;
    printf("%d",ans[0]);
    for (int i=1;i<=s.length();i++)
        printf(" %d",ans[i]);
    return 0;
}