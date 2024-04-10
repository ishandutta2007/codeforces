#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=4e5+9;
int n,q;
ll ans[M];
map<int,int>mp[M];
struct Sam{
    int last,sz;
    int len[M],f[M],po[M],siz[M],c[M][29];
    int tr[M],id[M];
    Sam(){last=sz=1;}
    int insert(int s){
        int p=last,np=++sz,q,nq;
        len[np]=len[last]+1;siz[np]=1;
        while(!c[p][s]&&p)c[p][s]=np,p=f[p];
        if(p){
            q=c[p][s];
            if(len[q]==len[p]+1)f[np]=q;
            else{
                nq=++sz;
                f[nq]=f[q];
                f[q]=f[np]=nq;
                len[nq]=len[p]+1;
                for(int i=1;i<=26;++i)c[nq][i]=c[q][i];
                while(c[p][s]==q&&p)c[p][s]=nq,p=f[p];
            }
        }
        else f[np]=1;
        last=np;
        return np;
    }
    void add(char *s){
        int l=strlen(s);
        for(int i=0;i<l;++i)po[i]=insert(s[i]-'a'+1);
    }
    void qsort(){
        for(int i=1;i<=sz;++i)tr[len[i]]++;
        for(int i=1;i<=sz;++i)tr[i]+=tr[i-1];
        for(int i=1;i<=sz;++i)id[tr[len[i]]--]=i;
        for(int i=1;i<=sz;++i){
            for(auto o:mp[i]){
                if(o.fi>q){
                    if(mp[i].count(o.fi-q))ans[o.fi-q]+=1ll*o.se*mp[i][o.fi-q]*len[i];
                }
            }
        }
        for(int i=sz;i>=1;--i){
            int u=id[i];
            if(mp[f[u]].size()<mp[u].size()){
                swap(mp[f[u]],mp[u]);
            }
            for(auto o:mp[u]){
                if(o.fi>q){
                    if(mp[f[u]].count(o.fi-q))ans[o.fi-q]+=1ll*o.se*mp[f[u]][o.fi-q]*len[f[u]];
                }
                else {
                    if(mp[f[u]].count(o.fi+q))ans[o.fi]+=1ll*o.se*mp[f[u]][o.fi+q]*len[f[u]];
                }
            }
            for(auto o:mp[u]){
                mp[f[u]][o.fi]+=o.se;
            }
        }
    }
}sam;
char s[M];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q>>s;
    reverse(s,s+n);
    sam.add(s);
    for(int i=1;i<=q;++i){
        int l,r;
        cin>>l>>r;
        for(int j=1;j<=l;++j){
            int x;
            cin>>x;
            mp[sam.po[n-x]][i]++;
        }
        for(int j=1;j<=r;++j){
            int x;
            cin>>x;
            mp[sam.po[n-x]][i+q]++;
        }
    }
    sam.qsort();
    for(int i=1;i<=q;++i)cout<<ans[i]<<"\n";
    return 0;
}