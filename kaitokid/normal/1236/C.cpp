#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;

int main()
{
    ios::sync_with_stdio(0);
int n;
cin>>n;
int q=1,g=(n*n);
if(n%2==0){for(int i=1;i<=n;i++)
{
for(int j=0;j<(n)/2;j++){cout<<q<<" ";q++;}
for(int j=0;j<(n)/2;j++){cout<<g<<" ";g--;}
    cout<<endl;


}return 0;}
int mid=n*(n/2)+1;
for(int i=1;i<=n;i++)
{
for(int j=0;j<(n)/2;j++){cout<<q<<" ";q++;}
for(int j=0;j<(n)/2;j++){cout<<g<<" ";g--;}
    cout<<mid;
    mid++;
    cout<<endl;


}
    return 0;
}