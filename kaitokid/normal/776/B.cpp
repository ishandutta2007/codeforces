#include <bits/stdc++.h>

using namespace std;
bool bl[100009];
int main()
{
int n;
   cin>>n;

if(n<3)cout<<1<<endl;
else cout<<2<<endl;
for(int i=2;i<=sqrt(n+1);i++)
{
  if(bl[i]==true)continue;
  for(int j=i*i;j<=n+1;j+=i)bl[j]=true;

}
for(int i=2;i<=n+1;i++)if(bl[i])cout<<"2 ";else cout<<"1 ";
    return 0;
}