#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=1e6+10;
vector<int>ad[mn];
struct query{
    int i,q,w;
};
vector<query>q[mn];
int ans[mn];
int bit[mn];
void up(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        ad[a].push_back(b);
    }
    for(int i=0;i<m;i++){
        int k;
        scanf("%d",&k);
        int ln=0;
        while(k--){
            int x;
            scanf("%d",&x);
            q[ln].push_back({i,x-1,-1});
            q[x-1].push_back({i,x-1,1});
            ln=x;
        }
        q[ln].push_back({i,mn-1,-1});
        q[mn-1].push_back({i,mn-1,1});
    }
    for(int i=0;i<mn;i++){
        for(int x:ad[i]){
            up(x,1);
        }
        for(auto&p:q[i]){
            ans[p.i]+=p.w*qu(p.q);
        }
    }
    for(int i=0;i<m;i++)printf("%d\n",n-ans[i]);
}