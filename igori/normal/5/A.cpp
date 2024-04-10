#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int h=0;
    int ans=0;
    int aaaaaaaa=0;
    char str[1000];
    int t=0;
    while(gets(str) != 0) {

        string o = str;
        t=0;
        if(o[0]=='+')
            {h++;t++;}
        if(o[0]=='-')
            {h--;t++;}
        if(t==0)
        {
            int k=0;
            int i=0;
            int ss=o.size();
            while(k<1)
                {
                    i++;
                    if(o[i]==':')
                    {
                      ans=ans+(ss-i-1)*h;
                      k++;
                    }
                }



        }
        


    }
    cout<<ans;





}