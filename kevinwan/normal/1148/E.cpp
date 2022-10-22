#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=3e5+10;
pii s[mn];
int t[mn];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&s[i].first),s[i].second=i;
    sort(s,s+n);
    for(i=0;i<n;i++)scanf("%d",t+i);
    sort(t,t+n);
    for(i=0;i<n;i++)s[i].first=t[i]-s[i].first;
    vector<int>aa,bb,cc;
    for(i=j=0;i<n&&j<n;){
        while(i<n&&s[i].first<=0)i++;
        while(j<n&&s[j].first>=0)j++;
        if(i>j)break;
        if(i==n||j==n)break;
        int dif=min(s[i].first,-s[j].first);
        aa.push_back(s[i].second);
        bb.push_back(s[j].second);
        cc.push_back(dif);
        s[i].first-=dif;
        s[j].first+=dif;
    }
    bool suc=1;
    for(i=0;i<n;i++)if(s[i].first)suc=0;
    if(suc){
        printf("YES\n%d\n",aa.size());
        for(i=0;i<aa.size();i++)printf("%d %d %d\n",aa[i]+1,bb[i]+1,cc[i]);
    }
    else printf("NO");
}