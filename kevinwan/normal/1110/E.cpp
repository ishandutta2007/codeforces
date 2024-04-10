#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=2e5+10;
int a[mn],b[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)cin>>b[i];
    for(i=n-1;i;i--)a[i]-=a[i-1],b[i]-=b[i-1];
    sort(a+1,a+n);
    sort(b+1,b+n);
    bool yes=1;
    for(i=0;i<n;i++)yes&=(a[i]==b[i]);
    if(yes)printf("Yes");
    else printf("No");
}