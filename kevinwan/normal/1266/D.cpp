#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mn=1e5+10;
const ll mod=1e9+7;
ll hail[mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        hail[a]-=c;
        hail[b]+=c;
    }
    vector<int>v,vv;
    vector<ll> vvv;
    stack<int>pos,neg;
    for(int i=1;i<=n;i++){
        if(hail[i]>0)pos.push(i);
        if(hail[i]<0)neg.push(i);
    }
    while(pos.size()&&neg.size()){
        ll sub=min(hail[pos.top()],-hail[neg.top()]);
        v.push_back(neg.top()),vv.push_back(pos.top()),vvv.push_back(sub);
        hail[pos.top()]-=sub,hail[neg.top()]+=sub;
        if(hail[pos.top()]==0)pos.pop();
        if(hail[neg.top()]==0)neg.pop();
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)printf("%d %d %lld\n",v[i],vv[i],vvv[i]);
}