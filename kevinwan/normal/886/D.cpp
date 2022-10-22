#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+34;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int nxt[mn];
bool vis[mn],st[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    memset(vis,1,sizeof(vis));
    memset(st,1,sizeof(st));
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(char c:s)vis[c]=0;
        for(int i=0;i+1<s.size();i++){
            if(nxt[s[i]]&&nxt[s[i]]!=s[i+1]){
                printf("NO\n");
                return 0;
            }
            nxt[s[i]]=s[i+1];
            st[s[i+1]]=0;
        }
    }
    string ans;
    for(int i='a';i<='z';i++)if(!vis[i]&&st[i]){
        for(int j=i;j;j=nxt[j]){
            if(vis[j]){
                printf("NO\n");
                return 0;
            }
            vis[j]=1;
            ans.push_back(j);
        }
    }
    for(int i='a';i<='z';i++)if(!vis[i]){
        printf("NO\n");
        return 0;
    }
    printf("%s",ans.c_str());
}