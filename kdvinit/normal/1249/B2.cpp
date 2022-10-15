#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int a[n+1],pos[n+1],ans[n+1]={0};
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(ans[i]!=0) continue;
            int cnt=1,j=a[i],val[n+1];
            val[1]=i;
            while(a[j]!=a[i])
            {
                cnt++;
                val[cnt]=j;
                j=a[j];
            }
            for(int k=1;k<=cnt;k++)
            {
                ans[val[k]]=cnt;
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}