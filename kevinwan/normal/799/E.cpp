#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=2e5+10;
ll v[mn];
bool ina[mn],inb[mn];
vector<ll>ab,a,b,sab,sa,sb;
int bit[mn];
struct comp{
    bool operator()(const int&a,const int&b)const{
        if(v[a]!=v[b])return v[a]<v[b];
        return a<b;
    }
};
struct idk:set<int,comp>{
    int pos=0;
    ll sum=0;
    iterator it=begin();
    void insert(int x){
        if(it==end()||comp()(x,*it))pos++,sum+=v[x];
        set<int,comp>::insert(x);
    }
    void erase(int x){
        if(it==end()||comp()(x,*it))pos--,sum-=v[x];
        set<int,comp>::erase(x);
    }
    ll query(int x){
        while(pos<x&&it!=end())sum+=v[*(it++)],pos++;
        while(pos>x&&it!=begin())sum-=v[*(--it)],pos--;
        if(pos!=x)return 0x3f3f3f3f3f3f3f3f;
        return sum;
    }
};
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,k,l,x;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>v[i];
    cin>>l;
    for(int i=0;i<l;i++)cin>>x,ina[x]=1;
    cin>>l;
    for(int i=0;i<l;i++)cin>>x,inb[x]=1;
    for(int i=1;i<=n;i++){
        if(ina[i]&&inb[i])ab.push_back(i);
        else if(ina[i])a.push_back(i);
        else if(inb[i])b.push_back(i);
    }
    idk s;
    sort(ab.begin(),ab.end(),comp());
    sort(a.begin(),a.end(),comp());
    sort(b.begin(),b.end(),comp());
    sab.resize(mn),sa.resize(mn),sb.resize(mn);
    for(int i=1;i<=ab.size();i++)sab[i]=sab[i-1]+v[ab[i-1]];
    for(int i=1;i<=a.size();i++)sa[i]=sa[i-1]+v[a[i-1]];
    for(int i=1;i<=b.size();i++)sb[i]=sb[i-1]+v[b[i-1]];
    int st=max(0,k-(int)min(a.size(),b.size()));
    int en=min(k,(int)ab.size());
    if(en<st){printf("-1");return 0;}
    for(int i=1;i<=n;i++)s.insert(i);
    for(int i=0;i<k-st;i++)s.erase(a[i]),s.erase(b[i]);
    for(int i=0;i<st;i++)s.erase(ab[i]);
    ll ans=0x3f3f3f3f3f3f3f3f;
    for(int i=st;i<=en;i++){
        int rem=m-k-k+i;
        ll pro=sab[i]+sa[k-i]+sb[k-i]+s.query(rem);
        ans=min(ans,pro);
        if(i<en) {
            s.erase(ab[i]);
            s.insert(a[k - i - 1]);
            s.insert(b[k - i - 1]);
        }
    }
    if(ans>1e17)printf("-1");
    else printf("%lld",ans);
}