#include <iostream>

using namespace std;
int x, a, b;
int main()
{
    cin>>x;
    char c;
    cin>>a>>c>>b;
    if(x==12)
    {
        if(a==0)
        {
            cout<<"01";
        }
        else if(a<=12)
        {
            if(a<10) cout<<0;
            cout<<a;
        }
        else if(a>12){
            int f=0;
            if(a%10==0) cout<<"10";
            else
            cout<<0<<a%10;
            }
    }
    else
    {
        if(a<=9)
            cout<<0<<a;
        else if(a<=23)
            cout<<a;
        else cout<<1<<a%10;
    }
    cout<<':';
    if(b<=9)
        cout<<0<<b;
    else if(b<60)
        cout<<b;
    else cout<<5<<b%10;


    return 0;
}