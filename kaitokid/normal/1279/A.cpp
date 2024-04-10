#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{int a[4];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[2]>a[0]+a[1]+1)cout<<"No\n";
        else cout<<"Yes\n";

}
    return 0;
}