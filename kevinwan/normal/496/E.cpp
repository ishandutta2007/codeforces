#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=1e5+10;
pair<pii,int> a[mn];
pair<pii,pii> b[mn];
map<pii,int>ma;
int ans[mn];
int main(){
    int n,m,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",&a[i].first.first,&a[i].first.second),a[i].second=i;
    scanf("%d",&m);
    for(i=0;i<m;i++)scanf("%d%d%d",&b[i].first.first,&b[i].first.second,&b[i].second.first),b[i].second.second=i+1;
    sort(a,a+n);
    sort(b,b+m);
    for(i=0,j=0;i<n;i++){
        while(j<m&&b[j].first.first<=a[i].first.first)ma[{b[j].first.second,b[j].second.second}]+=b[j].second.first,j++;
        auto it=ma.lower_bound({a[i].first.second,0});
        if(it==ma.end()){printf("NO");
        return 0;}
        ans[a[i].second]=it->first.second;
        it->second--;
        if(!(it->second))ma.erase(it);
    }
    printf("YES\n");
    for(i=0;i<n;i++)printf("%d ",ans[i]);
}