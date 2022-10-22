#include <bits/stdc++.h>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int x,cnt,T,a[N],tedad[N];
set<int> s,bad;
pair<char,int> q[N];
map<int,int> t;
ll Fen[N];

void update(int x,int val){ ++x;  while(x<=N)  {  Fen[x]+=val;  x+=(x&-x);  } }
ll query(int x){  ++x;  ll res=0;  while(x>0)  {  res+=Fen[x];  x-=(x&-x);  } return res; } 

void Add(int l,int r){
    if(l*2<r) bad.insert(r);
}
void delet(int l,int r){
    if(l*2<r) bad.erase(r);
}
void do_it(){
    int c=0;
    sort(a,a+T);
    f(i,0,T)
        if(!i || a[i]!=a[i-1])
            t[a[i]]=++c;
}
void add(int x){
    int l=0,r=0;
    if(s.lower_bound(x)!=s.end()) r=*s.lower_bound(x);
    if(s.lower_bound(x)!=s.begin()) l=*prev(s.lower_bound(x),1);
    if(l && r) delet(l,r);
    if(l) Add(l,x);
    if(r) Add(x,r);
    int u=t[x];
    tedad[u]++;
    if(tedad[u]==1) s.insert(x);
    update(u,x);
    cnt++;
}
void del(int x){
    int u=t[x];
    tedad[u]--;
    if(tedad[u]==0) s.erase(x);
    int l=0,r=0;
    if(s.lower_bound(x)!=s.end()) r=*s.lower_bound(x);
    if(s.lower_bound(x)!=s.begin()) l=*prev(s.lower_bound(x),1);
    if(l) delet(l,x);
    if(r) delet(x,r);
    if(l && r) Add(l,r);
    update(u,-x);
    cnt--;
}
void Get_ans(){
    int res=0;
    for(auto u : bad){
        int v=t[u];
        if(query(v-1)*2<u) res++;
    }
    cout<<max(cnt-1-res,0)<<'\n';
}

int main(){
    cin>>T;
    f(i,0,T){
        cin>>q[i].F>>q[i].S;
        a[i]=q[i].S;
    }
    do_it();

    f(io,0,T){
        if(q[io].F=='+')
            add(q[io].S);
        else
            del(q[io].S);
        Get_ans();
    }
}