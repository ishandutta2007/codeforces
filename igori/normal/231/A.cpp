#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a;
    int now=0;
    int k=0;
    cin>>a;
    int ch=0;
    for(int i=0; i<a; i++)
    {
        cin>>k;
        now=now+k;
        cin>>k;
        now=now+k;
        cin>>k;
        now=now+k;
        if(now>1)
            ch++;
        now=0;



    }
    cout<<ch;
}