// Hydro submission #625ceeb181ef68d42bcbb3e0@1650257585770
#include<bits/stdc++.h>
using namespace std;
bool r[10];
int main()
{
    int n,i,j;
    char c;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c;
        c-=48;
        switch(c)
        {
            case 28:
            {
                for(j=0;j<10;j++)
                if(!r[j])
                {
                    r[j]=true;
                    goto next;
                }
            }
            case 34:
            {
                for(j=9;j+1;j--)
                if(!r[j])
                {
                    r[j]=true;
                    goto next;
                }
            }
            default:
            {
                r[c]=false;
                break;
            }
        }
        next:;
    }
    for(i=0;i<10;i++)
    printf(r[i]?"1":"0");
    return 0;
}