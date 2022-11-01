#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
string ans="";
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int now=0,l=1,r=n;
    bool flag=true;
    while(flag&&l<=r)
    {
        flag=false;
        if(a[l]>=now&&a[r]>=now)
        {
            flag=true;
            now=min(a[l],a[r]);
            if(a[l]<a[r])
                l++,ans+='L';
            else r--,ans+='R';
        }
        else if(a[l]>=now)
        {
            now=a[l];
            flag=true;
            l++;ans+='L';
        }
        else if(a[r]>=now)
        {
            now=a[r];
            flag=true;
            r--;ans+='R';
        }
    }
    cout<<ans.size()<<endl<<ans<<endl;
}