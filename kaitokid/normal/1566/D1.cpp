#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[409],id[409];
bool bl(int x,int y)
{
    if(a[x]<a[y])return true;
    if(a[x]>a[y])return false;
    return x>y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){cin>>a[i];id[i]=i;}
        sort(id+1,id+m+1,bl);

     int ans=0;
     for(int i=1;i<=m;i++){
        for(int j=1;j<i;j++)
        if(id[i]>id[j])ans++;}

     cout<<ans<<endl;

    }
    return 0;
}