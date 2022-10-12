#include <iostream>

using namespace std;

int main()
{
    char s='a';
    int n,k;
    cin>>n>>k;
    int num=k;
    while(n>0)
    {
        if(num==1)
        {
            cout<<s;
            s='a';
            num=k;
        }
        else
           {
               cout<<s;
               s++;
               num--;
           }
        n--;
    }
}