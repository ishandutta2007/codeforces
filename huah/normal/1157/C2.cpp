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
        //cout<<l<<' '<<r<<' '<<now<<' '<<a[l]<<' '<<a[r]<<endl;
        flag=false;
        if(a[l]>now&&a[r]>now)
        {
            flag=true;
            if(a[l]<a[r])
                now=a[l],l++,ans+='L';
            else if(a[r]<a[l])
                now=a[r],r--,ans+='R';
            else if(a[l]==a[r])
            {
                int tot1=0,tot2=0;
                for(int i=r-1;i>=l;i--)
                    if(a[i]>a[i+1]) tot1++;
                else break;
                for(int i=l+1;i<=r;i++)
                    if(a[i]>a[i-1]) tot2++;
                else break;
                if(tot1<tot2) now=a[l],l++,ans+='L';
                else now=a[r],r--,ans+='R';
            }
        }
        else if(a[l]>now)
        {
            now=a[l];
            flag=true;
            l++;ans+='L';
        }
        else if(a[r]>now)
        {
            now=a[r];
            flag=true;
            r--;ans+='R';
        }
    }
    cout<<ans.size()<<endl<<ans<<endl;
}