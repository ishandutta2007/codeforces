#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=3e5+10;
int a[mn],lo[mn],hi[mn];
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
        map<int,int>comp;
        vector<int>v;
        int n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",a+i),v.push_back(a[i]);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(i=0;i<v.size();i++)comp[v[i]]=i;
        for(i=0;i<n;i++)a[i]=comp[a[i]];
        memset(lo,0x3f,4*v.size());
        memset(hi,0,4*v.size());
        for(i=0;i<n;i++)lo[a[i]]=min(lo[a[i]],i),hi[a[i]]=max(hi[a[i]],i);
        int ans=0;
        int st=0;
        for(i=1;i<v.size();i++){
            if(lo[i]<hi[i-1]){
                ans=max(ans,i-st);
                st=i;
            }
        }
        ans=max(ans,(int)(v.size()-st));
        printf("%d\n",v.size()-ans);
    }
}