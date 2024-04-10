// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INSERT=1;
const int ERASE=0;
class segtree{
private:
int sz=0;
vector<int>mx,tag;
void rangeadd(int p,int l,int r,int s,int t,int x){
    if(l>=t||r<=s){
        return;
    }
    if(l>=s&&r<=t){
        mx[p]+=x;
        tag[p]+=x;
        return;
    }
    mx[p<<1]+=tag[p];
    tag[p<<1]+=tag[p];
    mx[p<<1|1]+=tag[p];
    tag[p<<1|1]+=tag[p];
    tag[p]=0;
    rangeadd(p<<1,l,(l+r)>>1,s,t,x);
    rangeadd(p<<1|1,(l+r)>>1,r,s,t,x);
    mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
public:
segtree(int n){
    sz=1;
    while(sz<n){
        sz<<=1;
    }
    mx.resize(sz<<1);
    tag.resize(sz<<1);
}
void rangeadd(int s,int t,int x){
    rangeadd(1,0,sz,s,t,x);
}
int globalmax(){
    return mx[1];
}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,r;
    cin>>n>>r;
    vector<tuple<int,int,int,int>>seg;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        x-=y;
        y=x+(y<<1);
        seg.emplace_back(x-r,INSERT,y-r,y+r+1);
        seg.emplace_back(x+r+1,ERASE,y-r,y+r+1);
    }
    sort(seg.begin(),seg.end());
    segtree t(6e6);
    int ans=0;
    for(auto s:seg){
        switch(get<1>(s)){
            case INSERT:
                t.rangeadd(get<2>(s)+3e6,get<3>(s)+3e6,1);
                ans=max(ans,t.globalmax());
                break;
            case ERASE:
                t.rangeadd(get<2>(s)+3e6,get<3>(s)+3e6,-1);
                break;
        }
    }
    cout<<ans<<endl;
    return 0;
}