#include<bits/stdc++.h>
using namespace std;
int f(char a)
{
    return a - '0';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        string c,d;
        cin>>a>>c>>d;
        bool pos0 = false, pos1 = false;
        int licz = 0;
        for(int x=0;x<a;x++)
        {
            if(f(c[x]) + f(d[x]) == 1)
            {
                licz += 2;
                pos0 = false;
                pos1 = false;
            }
            if(f(c[x]) + f(d[x]) == 2)
            {
                if(pos0 == true)
                {
                    pos0 = false;
                    licz++;
                }
                else
                    pos1 = true;
            }
            if(f(c[x]) + f(d[x]) == 0)
            {
                if(pos1 == true)
                {
                    pos1 = false;
                    pos0 = false;
                    licz+=2;
                }
                else
                {
                    licz++;
                    pos0 = true;
                }
            }
        }
        cout<<licz<<'\n';
    }
    return 0;
}