#include <iostream>
#include<string>

using namespace std;

string s[]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
long long n,x,y;

int main()
{
    cin>>n;
    x=5;y=0;
    while(y+x<n)
    {
        y+=x;
        x*=2;
    }
    n-=y;
    x/=5;
    cout<<s[(n-1)/x]<<endl;
}