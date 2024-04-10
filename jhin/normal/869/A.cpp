#include <iostream>

using namespace std;
bool a[2000003];int b[2001],c[2001],n,num;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>b[i],a[b[i]]=true;
    for(int i=0;i<n;i++)cin>>c[i],a[c[i]]=true;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)if((b[i]^c[j])<=2000000) if(a[(b[i]^c[j])])num++;
    if(num%2==0) cout<<"Karen";else cout<<"Koyomi";
    return 0;
}