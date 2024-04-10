#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009],id[200009];
vector<int>cy[200009];
int ans[200009];
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

       int n;
       cin>>n;
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
           id[i]=i;
       }
       sort(id,id+n,bl);
       int num=0,u;
       for(int i=0;i<n;i++)
       {
           if(i==0|| a[id[i]]>a[id[i-1]])u=1;
           else u++;
           while(u>num)num++;
           cy[u].push_back(id[i]);
       }
       for(int i=1;i<=num;i++)
       {
           int rr=cy[i].size();
           for(int j=0;j<cy[i].size();j++)ans[cy[i][j]]=a[cy[i][(j+1)%rr]];
        cy[i].clear();
       }
       for(int i=0;i<n;i++)cout<<ans[i]<<" ";
       cout<<endl;

    }


return 0;
}