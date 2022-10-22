#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=1e6+10;
struct nd{
    int len,bac;
    map<char,int>nxt;
};
nd sa[mn*2];
int dp[mn*2];
int lst,ct;
void init(){
    sa[0].len=0;
    sa[0].bac=-1;
    lst=0;
    ct++;
}
void ad(char c){
    int n=ct++;
    sa[n].len=sa[lst].len+1;
    int p=lst;
    while(p!=-1&&!sa[p].nxt.count(c)){
        sa[p].nxt[c]=n;
        p=sa[p].bac;
    }
    if(p==-1)sa[n].bac=0;
    else{
        int q=sa[p].nxt[c];
        if(sa[p].len+1==sa[q].len)sa[n].bac=q;
        else{
            int r=ct++;
            sa[r].len=sa[p].len+1;
            sa[r].nxt=sa[q].nxt;
            sa[r].bac=sa[q].bac;
            while(p!=-1&&sa[p].nxt[c]==q){
                sa[p].nxt[c]=r;
                p=sa[p].bac;
            }
            sa[q].bac=sa[n].bac=r;
        }
    }
    lst=n;
}
vector<int>g[mn];
bool vis[mn];
void dfs(int x){
    vis[x]=1;
    for(auto p:sa[x].nxt)if(!vis[p.second])dfs(p.second);
    for(auto p:sa[x].nxt)dp[x]+=dp[p.second];
}
int main(){
    string s;
    cin>>s;
    init();
    int n;
    n=s.size();
    for(int i=0;i<n;i++)ad(s[i]);
    for(int i=lst;i!=0;i=sa[i].bac)dp[i]=1;
    dfs(0);
    int q;
    scanf("%d",&q);
    while(q--){
        string t;
        cin>>t;
        int m;
        m=t.size();
        int cur=0;
        t+=t;
        set<int>s;
        int ans=0;
        for(int l=0,r=0;l<m;){
            if(l+m==r){
                if(!s.count(cur)){
                    s.insert(cur);
                    ans+=dp[cur];
                }
                if(sa[sa[cur].bac].len==m-1)cur=sa[cur].bac;
                l++;
            }
            else if(sa[cur].nxt.count(t[r])){
                cur=sa[cur].nxt[t[r++]];
            }
            else{
                if(l==r)l++,r++;
                else{
                    if(sa[sa[cur].bac].len==r-l-1)cur=sa[cur].bac;
                    l++;
                }
            }
        }
        printf("%d\n",ans);
    }
}