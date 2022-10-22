#include <iostream>

using namespace std;
int a[10003];
int main()
{

int n,x,ans1=0,ans2=0;
  cin>>n;
for
    (int i=0;i<n;i++)
{cin>>x;
    if(a[x]==0){ans2++;}
a[x]++;
ans1=max(ans1,a[x]);

}
cout<<ans1<<" "<<ans2;
    return 0;
}