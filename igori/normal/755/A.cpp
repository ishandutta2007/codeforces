#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%2==1)
        {cout<<999;return 0;}
    else
    {
        if(n==2)
           {cout<<4;return 0;}
           
        int m=1;
        while(1!=0)
        {
            for(int j=2; j<sqrt(n*m)+1; j++)
            {
                if((n*m+1)%j==0)
                {
                    cout<<m; return 0;
                }
            }
            m++;
        }


    }

}