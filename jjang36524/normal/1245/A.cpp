#include <iostream>
using namespace std;
int N;
int a,b;
int gcd(int x,int y)
{
    if(!y)
    return x;
    return gcd(y,x%y);
}
int main()
{
    cin >> N;
    while(N--)
    {
        cin >> a >> b;
        int res=gcd(a,b);
        if(res==1)
        cout <<"Finite"<<endl;
        else
        {
            cout <<"Infinite"<<endl;
        }
    }
}