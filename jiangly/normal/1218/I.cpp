#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2000;
vector<int> g[4*MAX_N];
int dfn[4*MAX_N];
int low[4*MAX_N];
int a[MAX_N][MAX_N];
int b[MAX_N];
int belong[4*MAX_N];
int cnt,tot;
vector<int> stk;
void tarjan(int u){
    dfn[u]=tot;
    low[u]=tot++;
    stk.push_back(u);
    for(int v:g[u]){
        if(dfn[v]==-1){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(belong[v]==-1){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        belong[u]=cnt;
        while(stk.back()!=u){
            belong[stk.back()]=cnt;
            stk.pop_back();
        }
        stk.pop_back();
        ++cnt;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            char c;
            cin>>c;
            a[i][j]=c-'0';
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            char c;
            cin>>c;
            a[i][j]^=(c-'0');
        }
    }
    for(int i=0;i<n;++i){
        char c;
        cin>>c;
        b[i]=c-'0';
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(a[i][j]==1){
                if(b[i]==0&&b[j]==0){
                    cout<<-1<<endl;
                    return 0;
                }else if(b[i]==0&&b[j]==1){
                    g[i+2*n].push_back(i);
                }else if(b[i]==1&&b[j]==0){
                    g[j+3*n].push_back(j+n);
                }else{
                    g[i].push_back(j+3*n);
                    g[j+3*n].push_back(i);
                    g[j+n].push_back(i+2*n);
                    g[i+2*n].push_back(j+n);
                }
            }else{
                if(b[i]==0&&b[j]==1){
                    g[i].push_back(i+2*n);
                }else if(b[i]==1&&b[j]==0){
                    g[j+n].push_back(j+3*n);
                }else if(b[i]==1&&b[j]==1){
                    g[i].push_back(j+n);
                    g[j+n].push_back(i);
                    g[i+2*n].push_back(j+3*n);
                    g[j+3*n].push_back(i+2*n);
                }
            }
        }
    }
    for(int i=0;i<4*n;++i){
        dfn[i]=-1;
        belong[i]=-1;
    }
    for(int i=0;i<4*n;++i){
        if(dfn[i]==-1){
            tarjan(i);
        }
    }
    for(int i=0;i<2*n;++i){
        if(belong[i]==belong[i+2*n]){
            cout<<-1<<endl;
            return 0;
        }
    }
    int k=0;
    for(int i=0;i<2*n;++i){
        if(belong[i]<belong[i+2*n]){
            ++k;
        }
    }
    cout<<k<<endl;
    for(int i=0;i<2*n;++i){
        if(belong[i]<belong[i+2*n]){
            if(i<n){
                cout<<"row "<<i<<endl;
            }else{
                cout<<"col "<<i-n<<endl;
            }
        }
    }
    return 0;
}