#include <bits/stdc++.h>
using namespace std;
const int mn=5e5+10;
typedef pair<int,int> pii;
pair<pii,int> qu[mn];
set<int> num[mn];
vector<int>nums;
map<int,int>comp;
int a[mn],ans[mn];
int seg[mn*2];
void upd(int a,int b){
    seg[a+=mn]=b;
    for(a>>=1;a;a>>=1)seg[a]=min(seg[2*a],seg[2*a+1]);
}
int query(int a,int b){
    a+=mn,b+=mn;
    int ans=0x3f3f3f3f;
    while(a<=b){
        if(a&1)ans=min(ans,seg[a++]);
        if(!(b&1))ans=min(ans,seg[b--]);
        a>>=1,b>>=1;
    }
    return ans;
}
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",a+i);
        nums.push_back(a[i]);
    }
    sort(nums.begin(),nums.end());
    nums.resize(distance(nums.begin(),unique(nums.begin(),nums.end())));
    for(i=0;i<nums.size();i++)comp[nums[i]]=i;
    for(i=1;i<=n;i++){
        a[i]=comp[a[i]];
        num[a[i]].insert(i);
    }
    for(i=0;i<m;i++)scanf("%d%d",&qu[i].first.first,&qu[i].first.second),qu[i].second=i;
    sort(qu,qu+m,greater<pair<pii,int>>());
    memset(seg,0x3f,sizeof(seg));
    for(i=0,j=n;i<m;i++){
        while(qu[i].first.first<=j){
            auto it=num[a[j]].find(j);
            if(++it!=num[a[j]].end())upd(*it,(*it)-j);
            j--;
        }
        ans[qu[i].second]=query(qu[i].first.first,qu[i].first.second);
    }
    for(i=0;i<m;i++){
        if(ans[i]==0x3f3f3f3f)printf("-1\n");
        else printf("%d\n",ans[i]);
    }
}