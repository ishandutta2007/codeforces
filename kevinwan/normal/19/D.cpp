#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
struct event{int x,y,t,u;};
const int inf=0x3f3f3f3f;
const int mn=2e5+10;
pii ans[mn];
pii bit[mn];
void up(int a,pii b){for(a++;a<mn;a+=a&-a)bit[a]=max(bit[a],b);}
void cl(int a){for(a++;a<mn;a+=a&-a)bit[a]={-inf,-inf};}
pii qu(int a){pii b={-inf,-inf};for(a++;a;a-=a&-a)b=max(b,bit[a]);return b;}
int cnt;
void solve(int l,int r,vector<event>v){
    cnt+=v.size();
    sort(v.begin(),v.end(),[](event a,event b){if(a.x!=b.x)return a.x<b.x;if(a.y!=b.y)return a.y<b.y;return a.u<b.u;});
    for(event ev:v){
        if(ev.u>=inf)ans[ev.u-inf]=max(ans[ev.u-inf],qu(ev.y));
        else if(l==ev.t&&r==ev.u)up(ev.y,{ev.x,ev.y});
    }
    for(event ev:v)if(ev.u<inf)cl(ev.y);
    if(l==r)return;
    vector<event>a,b;
    int mid=(l+r)>>1;
    for(event ev:v){
        if(ev.u>=inf) {
            if (ev.t <= mid)a.push_back(ev);
            else b.push_back(ev);
        }
        else{
            if(ev.u<=mid)a.push_back(ev);
            else if(ev.t>mid)b.push_back(ev);
            else if(ev.t>l||ev.u<r)a.push_back({ev.x,ev.y,ev.t,mid}),b.push_back({ev.x,ev.y,mid+1,ev.u});
        }
    }
    solve(l,mid,a);
    solve(mid+1,r,b);
}
map<pii,int>m;
int main(){
    int n;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    vector<event>v;
    int num=0;
    vector<int>numx,numy;
    for(int i=0;i<n;i++){
        string s;
        int a,b;
        cin>>s>>a>>b;
        if(s=="add"){
            m[{a,b}]=i;
            numx.push_back(-a),numy.push_back(-b);
        }
        else if(s=="remove"){
            int tt=m[{a,b}];
            m.erase({a,b});
            v.push_back({-a,-b,tt,i-1});
            numx.push_back(-a),numy.push_back(-b);
        }
        else v.push_back({-a-1,-b-1,i,inf+(num++)}),numx.push_back(-a-1),numy.push_back(-b-1);
    }
    for(auto th:m)v.push_back({-th.first.first,-th.first.second,th.second,n-1});
    sort(numx.begin(),numx.end());
    sort(numy.begin(),numy.end());
    numx.erase(unique(numx.begin(),numx.end()),numx.end());
    numy.erase(unique(numy.begin(),numy.end()),numy.end());
    for(event&ev:v)ev.x=lower_bound(numx.begin(),numx.end(),ev.x)-numx.begin(),ev.y=lower_bound(numy.begin(),numy.end(),ev.y)-numy.begin();
    memset(ans,0xc0,sizeof(ans));
    memset(bit,0xc0,sizeof(bit));
    solve(0,n-1,v);
    for(int i=0;i<num;i++){
        if(ans[i].first<0)printf("-1\n");
        else printf("%d %d\n",-numx[ans[i].first],-numy[ans[i].second]);
    }
    //printf("%d",cnt);
}