#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=5e3+10;
struct nd{
    nd*c[2];
    int a,num=0;
};
string s;
nd*t;
void ad(nd*n,int i,int o){
    n->num++;
    n->a=o;
    if(i==s.size())return;
    if(!n->c[s[i]-'a'])n->c[s[i]-'a']=new nd();
    ad(n->c[s[i]-'a'],i+1,o);
}
vector<pii>v;
void tra(nd*n,int d){
    if(d)for(int i=0;i<n->num;i++)v.push_back({n->a,n->a+d-1});
    if(n->c[0])tra(n->c[0],d+1);
    if(n->c[1])tra(n->c[1],d+1);
}
struct ht{
    const static ll p=1e9+7,q=1e9+9;
    ll a,b;
    ht operator+(ht ot){return {(a+ot.a)%p,(b+ot.b)%q};}
    ht operator-(ht ot){return {(a-ot.a)%p,(b-ot.b)%q};}
    ht operator*(ht ot){return {(a*ot.a)%p,(b*ot.b)%q};}
    bool operator==(ht ot){return (a-ot.a)%p==0&&(b-ot.b)%q==0;}
    ht(ll a,ll b){this->a=a,this->b=b;}
    ht(ll a){this->a=this->b=a;}
    ht(){a=b=0;}
};
ll p=rng()+6482753;
ht m={p,p};
ht po[mn];
ht h[mn],rh[mn];
inline ht hsh(int l,int r){return h[r]-(l>=2?(h[l-2]*po[(r-l)/2+1]):0);}
inline ht rhsh(int l,int r){return rh[l]-rh[r+2]*po[(r-l)/2+1];}
bool check(int l,int r){
    int len=r-l+1;
    int mo=len/2;
    if(mo&1)mo++;
    mo-=2;
    int lr=l+mo,rl=r-mo;
    return hsh(l,lr)==rhsh(rl,r);
}
int main(){
    int n,k;
    cin>>s>>k;
    t=new nd();
    n=s.size();
    for(int i=0;i<n;i++)ad(t,i,i);
    tra(t,0);
    h[0]=s[0],h[1]=s[1];
    po[0]=1;
    for(int i=1;i<=n;i++)po[i]=po[i-1]*m;
    for(int i=2;i<n;i++)h[i]=h[i-2]*m+s[i];
    for(int i=n-1;i>=0;i--)rh[i]=rh[i+2]*m+s[i];
    for(pii p:v){
        k-=check(p.first,p.second);
        if(k==0){
            for(int i=p.first;i<=p.second;i++)printf("%c",s[i]);
            return 0;
        }
    }
}