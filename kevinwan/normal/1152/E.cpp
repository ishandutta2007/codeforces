#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=1e5+200;
int b[mn],c[mn];
vector<int>g[mn];
vector<pii>v;
int ind[mn];
bool u[mn];
int nxt(int x,int i){return x^v[i].first^v[i].second;}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=1;i<n;i++)cin>>b[i],nums.push_back(b[i]);
    for(int i=1;i<n;i++)cin>>c[i],nums.push_back(c[i]);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    if(nums.size()>n){printf("-1");return 0;}
    map<int,int>comp;
    for(int i=0;i<nums.size();i++)comp[nums[i]]=i;
    for(int i=1;i<n;i++){
        if(b[i]>c[i]){printf("-1");return 0;}
        b[i]=comp[b[i]],c[i]=comp[c[i]];
        g[b[i]].push_back(i-1);
        g[c[i]].push_back(i-1);
        v.push_back({b[i],c[i]});
    }
    int s=-1,e=-1;
    for(int i=0;i<nums.size();i++)if(g[i].size()&1){
        if(s==-1)s=i;
        else if(e==-1)e=i;
        else{printf("-1");return 0;}
    }
    if(s==-1)s=e=0;
    vector<int>pth,st;
    st.push_back(s);
    while(st.size()){
        int x=st.back();
        while(ind[x]<g[x].size()&&u[g[x][ind[x]]])ind[x]++;
        if(ind[x]==g[x].size()){
            pth.push_back(x);
            st.pop_back();
        }
        else{
            u[g[x][ind[x]]]=1;
            int y=nxt(x,g[x][ind[x]++]);
            st.push_back(y);
        }
    }
    if(pth.size()!=n){printf("-1");return 0;}
    reverse(pth.begin(),pth.end());
    for(int i=0;i<n;i++)printf("%d ",nums[pth[i]]);
}