#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009],id[100009];
int ans[100009];
bool bl(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        for(int i=0;i<n;i++)
        {cin>>a[i];id[i]=i;}
        sort(id,id+n,bl);
        int l=0;
        bool res=true;
        for(int i=1;i<n;i++)
        {
            if(a[id[i]]==a[id[i-1]])continue;
            if(l==i-1){res=false;break;}
            for(int j=l;j<i-1;j++)ans[id[j]]=id[j+1];
            ans[id[i-1]]=id[l];
            l=i;
        }
        if(l==n-1)res=false;
        for(int j=l;j<n-1;j++)ans[id[j]]=id[j+1];
            ans[id[n-1]]=id[l];
        if(!res)cout<<-1;
        else for(int i=0;i<n;i++)cout<<ans[i]+1<<" ";
        cout<<endl;

    }


    return 0;

}