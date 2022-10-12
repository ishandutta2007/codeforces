#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool e(int a,int b)
{
    if(a>b)
        return true;
    else
        return false;
}


int main()
{   int h=0;
    cin>>h;
    int m[100];
    for(int i=0; i<h; i++)
        cin>>m[i];
    int a=0; int b=0;
    sort(m,m+h);
    for(int i=h-1; i>-1; i--)
    {
        for(int j=0; j<i; j++)
            a=a+m[j];
        for(int j=i; j<h; j++)
            b=b+m[j];
        if(b>a)
           {
               cout<<h-i<<endl;
               return 0;
           }
        b=0;
        a=0;
    }


}