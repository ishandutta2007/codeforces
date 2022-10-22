#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans[59];
int fr[29][29];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int n,k;
cin>>n>>k;
cout<<"a";
n--;
if(n==0)return 0;

while(n)
{for(int i=0;i<k;i++)
{
    for(int j=k-1;j>i;j--)
    {
        if(n==0)return 0;
        cout<<char('a'+i);
        n--;
        if(n==0)return 0;
        cout<<char('a'+j);

        n--;
        if(n==0)return 0;

    }
}
for(int i=k-1;i>=0;i--)
{
    cout<<char('a'+i);
    n--;
    if(n==0)return 0;
}
}


    return 0;
}