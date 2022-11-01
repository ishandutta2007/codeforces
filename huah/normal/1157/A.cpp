#include<bits/stdc++.h>
using namespace std;
map<int,bool>vis;
int ans=0;
void f(int x)
{
    if(!vis[x]) vis[x]=true,ans++;
    else return;
    int t=x+1;
    while(t%10==0) t/=10;
    f(t);
}
int main()
{
    int n;
    scanf("%d",&n);
    f(n);
    printf("%d\n",ans);
}