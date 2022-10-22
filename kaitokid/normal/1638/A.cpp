#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            if(a[i]==i)continue;
            for(int j=i+1;j<=n;j++)if(a[j]==i){reverse(a+i,a+j+1);break;}
            break;
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}