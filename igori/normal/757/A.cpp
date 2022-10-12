#include <iostream>
#include <string>

using namespace std;

int main()
{
    int B=0;
    int u=0;
    int l=0;
    int b=0;
    int a=0;
    int s=0;
    int r=0;
    string c;
    cin>>c;
    int ans=0;
    for(int i=0; i<c.size(); i++)
    {
        if(c[i]=='B')
            B++;
         if(c[i]=='u')
            u++;
        if(c[i]=='l')
            l++;
             if(c[i]=='b')
            b++;
             if(c[i]=='a')
            a++;
             if(c[i]=='s')
            s++;
             if(c[i]=='r')
            r++;
            if((B>0)&&(u>1)&&(l>0)&&(b>0)&&(a>1)&&(s>0)&&(r>0))
            {
                ans++;
                B=B-1;
                u=u-2;
                l=l-1;
                b=b-1;
                a=a-2;
                s=s-1;
                r=r-1;
            }
    }
    cout<<ans;




}