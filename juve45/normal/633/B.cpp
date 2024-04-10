#include <iostream>

using namespace std;
int n;
int main()
{
cin>>n;
int nr=0;

int ii=0;
while(nr<n)
{

ii+=5;
    int h=ii;
while(h%5==0)
{
nr++;
h/=5;
}

}
if(nr==n)
{

    cout<<5<<'\n';
    for(int i=0;i<5;i++)
    cout<<ii+i<<' ';
    cout<<'\n';
}
else cout<<"0\n";
    return 0;
}