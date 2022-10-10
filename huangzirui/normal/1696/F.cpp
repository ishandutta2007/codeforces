#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int i,j,k,n,m,a[maxn],is[maxn][maxn][maxn],t[maxn][maxn],dist[maxn][maxn];
vector<pair<int,int> >V;
vector<int>E[maxn];
string S;
void dfs(int X,int Y){
    // cerr<<"dfs "<<X<<' '<<Y<<endl;
    if(X>Y)swap(X,Y);
    if(t[X][Y])return;
    t[X][Y]=1;
    V.push_back(make_pair(X,Y));
    for(int Z=1;Z<=n;Z++){
        if(is[X][Z][Y] || is[Z][X][Y]){
            // cerr<<X<<' '<<Z<<' '<<Y<<endl;
            dfs(Y,Z);
        }
        if(is[Y][Z][X] || is[Z][Y][X]){
            dfs(X,Z);
        }
    }
}
bool B;int chs;
void dfs2(int now,int fa){
    // cerr<<"dfs2 "<<now<<' '<<fa<<' '<<dist[chs][now]<<endl;
    for(int u:E[now]){
        // cerr<<now<<" -> "<<u<<endl;
        if(u==fa)continue;
        if(dist[chs][u]){B=false;return;}
        if(!B)return;
        // cerr<<"OK1"<<endl;
        dist[chs][u]=dist[chs][now]+1;
        dfs2(u,now);
    }
}
void out(){
    puts("Yes");
    for(int i=1;i<=n;i++)
        for(int u:E[i])if(u>i)printf("%d %d\n",i,u);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                t[i][j]=0;
        for(i=1;i<n;i++){
            for(j=1;j<=n-i;j++){
                cin>>S;
                for(k=1;k<=n;k++)
                    is[i][i+j][k]=is[i+j][i][k]=(S[k-1]=='1');
            }
        }
        bool flg=false;
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++){
                if(flg)break;
                V.clear();
                dfs(i,j);
                for(auto P:V){
                    // cerr<<P.first<<' '<<P.second<<endl;
                }
                if(V.size()==n-1){
                    for(k=1;k<=n;k++)E[k].clear();
                    for(k=0;k<n-1;k++){
                        E[V[k].first].push_back(V[k].second);
                        E[V[k].second].push_back(V[k].first);
                    }
                    B=true;
                    for(k=1;k<=n;k++){
                        chs=k;
                        for(int h=1;h<=n;h++)dist[k][h]=0;
                        // cerr<<"try "<<k<<endl;
                        dfs2(k,0);
                        if(!B)break;
                    }
                    for(int X=1;X<=n;X++)
                        for(int Y=X+1;Y<=n;Y++)
                            for(int Z=1;Z<=n;Z++)
                                if((dist[X][Z]==dist[Y][Z]) != is[X][Y][Z])
                                    B=false;
                    if(B){out();flg=true;break;}
                }
            }
        if(!flg)puts("No");
    }
}