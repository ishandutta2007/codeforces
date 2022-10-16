#include <iostream>
#include <algorithm>

using namespace std;

bool check(int a, int b, int c, int d)
{

if(a<=b&&b<=c&&c<=d&&d<=1000000)
{
    if(a+b+c+d==2*b+2*c && a+b+c+d==4*(d-a))
        return true;
}
return false;
}

int main()
{int n, a, b, c, d;
cin>>n;
if(n==0)
{
    cout<<"YES\n1\n1\n3\n3\n";
}

if(n==1)
{
    cin>>a;
    cout<<"YES\n"<<a<<'\n'<<3*a<<'\n'<<3*a<<'\n';
}
if(n==2)
{
    cin>>a>>b;
    if(a>b)
    {
        int aux=a;
        a=b;
        b=aux;
    }
    int diff=b-a;
    if(diff==2*a)
        cout<<"YES\n"<<a<<'\n'<<b;
    else{
            if(b<3*a)
    cout<<"YES\n"<<3*a-(b-a)<<'\n'<<3*a<<'\n';
    else if(b%3==0)
        cout<<"YES\n"<<b/3<<'\n'<<b-(a-(b/3))<<'\n';
else cout<<"NO";
    }
}
if(n==3)
{
int a[5];
cin>>a[0]>>a[1]>>a[2];
sort(a, a+3);
if(3*a[0]==a[2])
    cout<<"YES\n"<<a[2]-(a[1]-a[0])<<'\n';
else
if(check(a[0], a[1], a[2], 3*a[0]))
{
    cout<<"YES\n"<<3*a[0]<<'\n';
}
else if(a[2]%3==0)
{
if(check(a[2]/3,a[0], a[1], a[2]))
{
        cout<<"YES\n"<<a[2]/3<<'\n';
        }
else cout<<"NO";

}
else cout<<"NO";

}
if(n==4)
{
    int a[5];
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    sort(a+1, a+5);

    if(check(a[1], a[2], a[3], a[4]))
        cout<<"YES\n";
        else cout<<"NO";
}
        return 0;
}