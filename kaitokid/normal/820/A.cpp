#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
int c,v0,v1,a,l;
cin>>c>>v0>>v1>>a>>l;
int ans=1;
c-=v0;
while(c>0)
{ans++;
//cout<<c<<endl;
c+=l;
//cout<<c<<endl;
v0+=a;
v0=min(v0,v1);
c-=v0;
//cout<<c<<endl;

}
cout<<ans;
    return 0;
}