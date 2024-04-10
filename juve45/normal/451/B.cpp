#include <iostream>

using namespace std;
int n, a[100005], ok, i1, i2;

int main()
{
cin>>n;
ok=2;
a[n+1]=1000000001;
for(int i=1;i<=n+1;i++)
{
    if(i<=n)
    cin>>a[i];
    if(ok==2)
    {
        if(a[i]<a[i-1])
            ok--, i1=i-1;
    }
    if(ok==1)
        if(a[i]>a[i-1])
        {
        if(a[i1]<a[i] && a[i-1]>a[i1-1])
        ok--, i2=i-1;
        else ok=-1, cout<<"no\n";
        }
    if(ok==0)
        if(a[i]<a[i-1])
    {
        cout<<"no\n";
        return 0;
    }
}
/*int iok=1;
for(int i=1;i<n;i++)
    if(a[i]>a[i+1])
    iok=2;

if(iok==1)
    cout<<"yes\n1 "<<n<<'\n';
else{*/
if(ok==2)
cout<<"yes\n1 1\n";
if(ok==1)
    cout<<"no\n";
if(ok==0)
cout<<"yes\n"<<i1<<' '<<i2<<'\n';
//}
    return 0;
}