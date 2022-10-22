#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
cin>>a[0]>>a[1]>>a[2]>>a[3];
sort(a,a+4);
int sum=a[0]+a[1]+a[2]+a[3];
for(int i=0;i<4;i++)
{
    if(sum==2*a[i]){cout<<"YES";return 0;}
}
if(a[0]+a[3]==a[1]+a[2])cout<<"YES";
else cout<<"NO";
    return 0;
}