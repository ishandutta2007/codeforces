#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
vector<int>g[mn*2],id[mn*2];
int at[mn*2];
bool u[mn*2],ans[mn*2];
bool hail(int i){ while(at[i]<g[i].size()&&u[id[i][at[i]]])at[i]++;return at[i]<g[i].size();}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(mn+b);
        g[mn+b].push_back(a);
        id[a].push_back(i);
        id[b+mn].push_back(i);
    }
    int ln=-1;
    int ex=n;
    for(int i=1;i<mn*2;i++){
        if(g[i].size()&1){
            if(ln==-1)ln=i;
            else {
                g[ln].push_back(i);
                g[i].push_back(ln);
                id[i].push_back(ex);
                id[ln].push_back(ex++);
                ln=-1;
            }
        }
    }
    for(int i=1;i<mn*2;i++){
        int x=i;
        while(hail(x)){
            int y=g[x][at[x]],it=id[x][at[x]];
            if(x<y)ans[it]=1;
            else ans[it]=0;
            u[it]=1;
            x=y;
        }
    }
    for(int i=0;i<n;i++)printf("%c",ans[i]?'r':'b');
}