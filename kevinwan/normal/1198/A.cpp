#include <bits/stdc++.h>
using namespace std;
int n,k;
map<int,int>num;
vector<int>a;
int main()
{
    int i;
    scanf("%d%d",&n,&k);
    k=1<<(min(30,k*8/n));
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        num[x]++;
    }
    a.push_back(0);
    for(auto p:num){
        a.push_back(p.second);
    }
    for(i=1;i<a.size();i++)a[i]+=a[i-1];
    k=min(k,(int)a.size()-1);
    int ans=0;
    for(i=k;i<a.size();i++)ans=max(ans,a[i]-a[i-k]);
    printf("%d",n-ans);
}