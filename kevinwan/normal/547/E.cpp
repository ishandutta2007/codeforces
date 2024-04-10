#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=5e5+10;
const ll mod=1e9+7;
string s;
int pos[mn];
int sa[mn],isa[mn];
int ans[mn];
int bit[mn];
int lcp[mn];
int sp[mn][19];
void up(int a,int b){for(a++;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(a++;a;a-=a&-a)b+=bit[a];return b;}
struct query{
    int p,l,r,sgn,ind;
};
inline int mi(int l,int r){
    if(r<l)return 0x3f3f3f3f;
    int b=31-__builtin_clz(r-l+1);
    return min(sp[l][b],sp[r-(1<<b)+1][b]);
}
int bsr(int x,int lim){
    int cur=x-1;
    for(int i=1<<18;i;i>>=1){
        if(cur+i>=s.size()-1)continue;
        if(mi(x,cur+i)>=lim)cur+=i;
    }
    return cur+1;
}
int bsl(int x,int lim){
    int cur=x;
    for(int i=1<<18;i;i>>=1){
        if(cur-i<=0)continue;
        if(mi(cur-i,x-1)>=lim)cur-=i;
    }
    return cur;
}
pii val[mn];
vector<int>b[mn];
void getsa(){
    assert(s.size()<=5e5);
    iota(sa,sa+s.size(),0);
    sort(sa,sa+s.size(),[](int a,int b){return s[a]<s[b];});
    for(int i=0;i<s.size();i++){
        if(i&&s[sa[i]]==s[sa[i-1]])isa[sa[i]]=isa[sa[i-1]];
        else isa[sa[i]]=i;
    }
    for(int l=1;l<s.size();l<<=1){
        for(int i=0;i<s.size();i++)val[i]={isa[i],i+l<s.size()?isa[i+l]:-1};
        for(int i=0;i<s.size();i++)b[val[sa[i]].second+1].push_back(sa[i]);
        int cur=0;
        for(int i=0;i<=s.size();i++){
            for(int j:b[i])sa[cur++]=j;
            b[i].clear();
        }
        for(int i=0;i<s.size();i++)b[val[sa[i]].first].push_back(sa[i]);
        cur=0;
        for(int i=0;i<s.size();i++){
            for(int j:b[i])sa[cur++]=j;
            b[i].clear();
        }
        for(int i=0;i<s.size();i++){
            if(i&&val[sa[i]]==val[sa[i-1]])isa[sa[i]]=isa[sa[i-1]];
            else isa[sa[i]]=i;
        }
    }
}
void getlcp(){
    for(int i=0,l=0;i<s.size();i++){
        if(isa[i]+1==s.size())continue;
        int j=sa[isa[i]+1];
        while(i+l!=s.size()&&j+l!=s.size()&&s[i+l]==s[j+l])l++;
        lcp[isa[i]]=l--;
        l=max(l,0);
    }
}
vector<query>v;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    s="0";
    for(int i=0;i<n;i++){
        pos[i]=s.size();
        string t;
        cin>>t;
        s+=t;
        s+='0';
    }
    pos[n]=s.size();

        getsa();
        getlcp();
    //else assert(0);
    for(int i=1;i+1<s.size();i++)sp[i][0]=lcp[i];
    for(int i=1;i<19;i++)for(int j=1;j+(1<<i)<s.size();j++)sp[j][i]=min(sp[j][i-1],sp[j+(1<<(i-1))][i-1]);
    for(int i=1;i<=m;i++){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        k--,l--,r--;
        l=pos[l],r=pos[r+1]-1;
        int x=isa[pos[k]];
        int bl=bsl(x,pos[k+1]-pos[k]-1),br=bsr(x,pos[k+1]-pos[k]-1);
        v.push_back({bl-1,l,r,-1,i});
        v.push_back({br,l,r,1,i});
    }
    sort(v.begin(),v.end(),[](query a,query b){return a.p<b.p;});
    int cur=0;
    for(query q:v){
        while(cur<q.p){
            cur++;
            if(sa[cur])up(sa[cur],1);
        }
        ans[q.ind]+=q.sgn*(qu(q.r)-qu(q.l-1));
    }
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}