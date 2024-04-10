#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,ans;
string s;
int a[200],b[200];

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
    cin>>n;
cin>>s;
for(int i=0;i<n;i++)cin>>a[i]>>b[i];
for(int i=0;i<100000;i++)
{int res=0;
    for(int j=0;j<n;j++){if(i==b[j]||((i>b[j])&&((i-b[j])%a[j]==0)))
    {
        if(s[j]=='0')s[j]='1';else s[j]='0';
    }
    if(s[j]=='1')res++;}
    ans=max(res,ans);

}
cout<<ans;
    return 0;
}