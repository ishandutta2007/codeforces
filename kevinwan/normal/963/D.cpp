#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=1e5+10,siz=5;
ll m=26;
int n;
vector<int>v[mn*siz];
map<ll,int>mp;
ll h[mn],p[mn];
int lps[mn];
int ct=0;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    p[0]=1;
    for(int i=1;i<mn;i++)p[i]=p[i-1]*m;
    string s;
    cin>>s;
    n=s.size();
    h[0]=s[0];
    for(int i=1;i<n;i++)h[i]=h[i-1]*m+s[i];
    for(int i=1;i<=siz;i++){
        for(int j=i-1;j<n;j++){
            ll hsh=h[j]-(j-i>=0?h[j-i]*p[i]:0);
            auto it=mp.find(hsh);
            if(it==mp.end()){
                mp[hsh]=++ct;
                v[ct].push_back(j);
            }
            v[it->second].push_back(j);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int k;
        string t;
        cin>>k>>t;
        vector<int>w;
        if(t.size()<=siz){
            ll hsh=0;
            for(char c:t)hsh=hsh*m+c;
            auto it=mp.find(hsh);
            if(it!=mp.end())w=v[mp[hsh]];
        }
        else {
            for (int i = 1, j = 0; i < t.size();) {
                if (t[i] == t[j])lps[i++] = ++j;
                else if (j)j = lps[j - 1];
                else lps[i++] = 0;
            }
            for(int i=0,j=0;i<n||j==t.size();){
                if(j==t.size())w.push_back(i),j=lps[j-1];
                else if(s[i]==t[j])i++,j++;
                else if(j)j=lps[j-1];
                else i++;
            }
        }
        if(w.size()<k){printf("-1\n");continue;}
        int ans=0x3f3f3f3f;
        for(int i=k-1;i<w.size();i++)ans=min(ans,w[i]-w[i-k+1]+(int)t.size());
        printf("%d\n",ans);
    }
}