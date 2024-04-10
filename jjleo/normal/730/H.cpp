#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace  std;
#define ll long long
#define rep(i,m,n) for(int i=m;i<=n;i++)
const int N = 1e6+10;
const double eps = 1e-8;
vector<string> s;
vector<string> g;
int vis[110];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n;
    cin>>n>>m;
    rep(i,1,n){
        string tmp;
        cin>>tmp;
        g.emplace_back(tmp);
    }
    rep(i,1,m){
        int x;
        cin>>x;
        vis[x-1]=1;
        s.emplace_back(g[x-1]);
    }
    int l=0;
    for(auto i:s){
        if(!l)l=i.length();
        else{
            if(l!=i.length()){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    string ans;
    rep(i,0,l-1){
        char ch;
        int ok=0;
        int fl=0;
        for(auto j:s){
            if(!ok)ch=j[i],ok=1;
            if(ch!=j[i])fl=1;
        }
        if(!fl){
            ans+=ch;
        }else{
            ans+='?';
        }
    }
    int tt=0;
    rep(i,1,n){
        if(!vis[i-1]) {
            if (g[i - 1].length() != ans.length())continue;
            else{
                int fl=0;
                rep(j,0,l-1){
                    if(ans[j]!='?'&&ans[j]!=g[i-1][j]){fl=1;break;}
                }
                if(!fl){
                    tt=1;
                    break;
                }
            }
        }
    }
    if(tt){
        cout<<"No"<<endl;
        return 0;
    }
   cout<<"Yes"<<endl;
    cout<<ans;
    return 0;
}