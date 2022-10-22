#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int lst[109];
int l[109],r[109],num[10009];
int mx;
bool ch(int x,int y)
{
    for(int i=x;i<=y;i++)if(num[i]+1>mx)return false;
    return true;
}
void go(int x,int y)
{
    for(int i=x;i<=y;i++)num[i]++;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
     mx=(n+k-2)/(k-1);
    for(int i=1;i<=n*k;i++)
    {
        int x;
        cin>>x;
        if(lst[x]==0){lst[x]=i;continue;}
        if(l[x]!=0)continue;
        if(ch(lst[x],i)){go(lst[x],i);l[x]=lst[x];r[x]=i;}
        lst[x]=i;
    }
    for(int i=1;i<=n;i++)
    cout<<l[i]<<" "<<r[i]<<endl;
    return 0;
}