#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
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

const int N=1e6+99;

int n,q,mx;
set<int> s1,s2;
set<pair<int,int> > e;
map<int,int> gh;

void Add(int x){
    e.insert(mp(x-gh[x],x));
   // cout<<x<<" : "<<gh[x]<<endl;
}
void rem(int x){
    e.erase(mp(x-gh[x],x));
}
void mv(){
    if(s1.size()==0){
        cout<<0<<'\n';
        return ;
    }    
    int ans=(*s1.rbegin())-(*s1.begin());
    if(e.size()) ans-=(*e.rbegin()).F;
    cout<<ans<<'\n';
}
void add(int x){
    s1.insert(x);
    s2.insert(-x);
    int l=x,r=x;
    if(x!=(*s1.rbegin())) r=*s1.upper_bound(x);
    if(x!=(*s1.begin())) l=-(*s2.upper_bound(-x));
    if(x<r){
        rem(r);
        gh[r]=x;
        Add(r);
    }
    if(l<x){
        gh[x]=l;
        Add(x);
    }
}
void del(int x){
    int l=x,r=x;
    if(x!=(*s1.rbegin())) r=*s1.upper_bound(x);
    if(x!=(*s1.begin())) l=-(*s2.upper_bound(-x));
    if(x<r){
        rem(r);
        gh[r]=r;
        if(l<x){
            gh[r]=l;
            Add(r);
        }
    }
    if(l<x)
        rem(x);
    s1.erase(x);
    s2.erase(-x);
}

int main(){
    cin>>n>>q;
    f(i,0,n){
        int x;
        gett(x);
        add(x);
    }
    mv();
    f(io,0,q){
        int t,x;
        Gett(t,x);
        if(t)
            add(x);
        else
            del(x);
        mv();
    }
}