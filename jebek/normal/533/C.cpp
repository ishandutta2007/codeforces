#include <iostream>

using namespace std;

int a,b,c,d;

bool check()
{
    if(c>=a && d>=b)
        return true;
    if(c<=a && d<=b)
        return false;
    if(c<a)
    {
        if(max(d-b,c)<a)
            return false;
        return true;
    }
    if(max(c-a,d)<b)
        return false;
    return true;
}

int main()
{
    cin>>a>>b>>c>>d;
    if(check())
        cout<<"Polycarp"<<endl;
    else
        cout<<"Vasiliy"<<endl;
}