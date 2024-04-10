#include <iostream>

using namespace std;

bool c8(int a)
{
    if(a<0) a=-a;
    while(a>0)
    {
        if(a%10==8)
            return true;
        a=a/10;
    }
    return false;
}

int main()
{
    int a, ok=0;
cin>>a;
int k=0;

while(!ok)
{
    a++;k++;
    if(c8(a))
        ok=1;

}
cout<<k;
    return 0;
}