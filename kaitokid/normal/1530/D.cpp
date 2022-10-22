#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sd[200009];
int a[200009],ans[200009],gv[200009];
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
        for(int i=1;i<=n;i++)sd[i]=false;
        queue<int>v;
        for(int i=1;i<=n;i++){cin>>a[i];sd[a[i]]=true;}
        for(int i=1;i<=n;i++)
            if(!sd[i])v.push(i);
        for(int i=1;i<=n;i++)gv[i]=0;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            if(gv[a[i]]){
        int d=v.front();
        v.pop();
        ans[i]=d;
        if(d!=i)continue;
        ans[i]=a[i];
        ans[gv[a[i]]]=d;
        gv[a[i]]=i;
        continue;}
            res++;
            ans[i]=a[i];
            gv[a[i]]=i;

        }
        cout<<res<<endl;
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
        }
    return 0;
}