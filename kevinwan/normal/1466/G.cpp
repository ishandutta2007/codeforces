#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=1e5+10;
const int ms=1e6+10;
const ll mod=1e9+7;

string s,t,rs,a,ra;
ll pf[mn][26],u[26];
int lcp[ms];
ll p2[mn];
ll comp(string&s,string&t){
    ll ans=0;
    int i,j;
    for(i=0,j=0;i<s.size();){
        if(j==t.size()) ans++,j=lcp[j-1];
        else if(s[i]==t[j])i++,j++;
        else if(j) j=lcp[j-1];
        else i++;
    }
    ans+=(j==t.size());
    return ans;
}

ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,q;
    cin>>n>>q;
    p2[0]=1;
    for(int i=1;i<=n;i++)p2[i]=p2[i-1]*2%mod;
    cin>>s>>t;
    rs=string(s.rbegin(),s.rend());
    stack<int>st;
    while(a.size()<ms){
        a+=s,ra+=rs;
        int nxt=0;
        while(st.size()&&st.top()==nxt)nxt++,st.pop();
        st.push(nxt);
        if(nxt>=n-1)break;
        a.push_back(t[nxt]);
        ra.push_back(t[nxt]);
    }
    cerr<<a.size()<<endl<<ra.size()<<endl;
    for(int i=1;i<=n;i++){
        memcpy(pf[i],pf[i-1],sizeof(pf[i]));
        pf[i][t[i-1]-'a']+=p2[n-i],pf[i][t[i-1]-'a']%=mod;
    }
    while(q--){
        string w;
        int k;
        cin>>k>>w;
        for(int i=1,j=0;i<w.size();){
            if(w[i]==w[j])lcp[i++]=++j;
            else if(j)j=lcp[j-1];
            else lcp[i++]=0;
        }
        ll ans=comp(s,w)*p2[n]%mod;
        memset(u,0,sizeof(u));
        for(int i=1,l=s.size();l<w.size()&&i<=k;l=l*2+1,i++){
            string tar;
            u[t[i-1]-'a']+=p2[n-i],u[t[i-1]-'a']%=mod;
            for(int j=min(l,int(w.size())-1)-1;j>=0;j--)tar+=ra[j];
            tar.push_back(t[i-1]);
            for(int j=0;j<min(l,int(w.size())-1);j++)tar+=a[j];
            ans+=comp(tar,w)*p2[n-i],ans%=mod;
        }
        for(int i=0;i<26;i++){
            string tar;
            for(int j=min(int(a.size()),int(w.size())-1)-1;j>=0;j--)tar+=ra[j];
            tar.push_back(i+'a');
            for(int j=0;j<min(int(a.size()),int(w.size())-1);j++)tar+=a[j];
            ans+=comp(tar,w)*(pf[k][i]-u[i]),ans%=mod;
        }
        ans*=po(2,mod-1-(n-k)),ans%=mod;
        if(ans<0)ans+=mod;
        printf("%lld\n",ans);
    }
}