#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[109];
int main()
{
 ios::sync_with_stdio(0);
 cin.tie(NULL);
int t,n,d;
cin>>t;
while(t--)
{
    cin>>n>>d;
    int u=0;
    for(int i=0;i<n;i++){cin>>a[i];if(a[i]>d)u++;}
    sort(a,a+n);
if(a[0]+a[1]<=d||u==0)cout<<"YES\n";
else cout<<"NO\n";

}
    return 0;
}