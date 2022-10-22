#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=51123987;
const int mn=2e6+10;
vector<int> manacher(string S){
    string s="$";
    for(int i=0;i<S.size();i++)s.push_back(S[i]),s.push_back('$');
    int n=s.size();
    vector<int>v(n);
    for(int m=0,l=0,r=0,cl=0,cr=0;m<n;){
        while(l-1>=0&&r+1<n&&s[l-1]==s[r+1])l--,r++;
        v[m]=r-m;
        cl=m-1,cr=m+1;
        while(cr<=r){
            v[cr]=min(v[cl],r-cr);
            if(v[cr]==r-cr)break;
            cr++,cl--;
        }
        m=cr;
        l=2*m-r;
    }
    return v;
}
ll bit[3][mn];
void upd(int a,int b,int c){
    c%=mod;
    if(c<0)c+=mod;
    for(b++;b<mn;b+=b&-b){
        ll val=c+bit[a][b];
        bit[a][b]=val>mod?val-mod:val;
    }
}
ll que(int a,int b){int c=0;for(b++;b;b-=b&-b)c+=bit[a][b];return c%mod;}
ll half=(mod+1)/2;
void up(ll l,ll r){
    swap(l,r);
    l=mn-5-l,r=mn-5-r;
    upd(2,l,half);
    upd(1,l,(-2*l+3)*half%mod);
    upd(0,l,(-l+1)*(-l+2)%mod*half%mod);
    upd(2,r,-half);
    upd(1,r,-(-2*l+3)*half%mod+(r-l+1));
    upd(0,r,-(-l+1)*(-l+2)%mod*half%mod+(r-l+1)*(r-l+2)%mod*half%mod-r*(r-l+1)%mod);
}
ll eval(ll x){
    return (x*x%mod*que(2,x)%mod+x*que(1,x)%mod+que(0,x))%mod;
}
ll qu(ll l,ll r){
    if(r<l)return 0;
    swap(l,r);
    l=mn-5-l,r=mn-5-r;
    return eval(r)-eval(l-1);
}
int main(){
    int n;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    string s;
    cin>>s;
    vector<int>v=manacher(s);
    ll ans=0;
    for(int i=0;i<n;i++){
        int len=(v[i*2+1]+1)/2;
        ans+=qu(i-len+1,i);
        ans+=1LL*len*(len-1)/2;
        ans%=mod;
        up(i,i+len-1);
        len=v[i*2+2]/2;
        ans+=qu(i-len+1,i);
        up(i+1,i+len);
        ans+=1LL*len*(len-1)/2;
        ans%=mod;
    }
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}