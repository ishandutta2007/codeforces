#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> ii;

#define X first
#define Y second

const int N=2e5+10;
const int MOD=1e9+7;

int n,deg[N];

int q[N],h[N];
vector <int> v1[N],v2[N];
int BFS1(int st){
    int top=1,bot=1;
    q[1]=st;
    while (top<=bot){
        int x=q[top++];
        h[x]=1;
        for(auto y:v1[x]) q[++bot]=y;
    }
    return bot;
}

int BFS2(int st){
    int top=1;
    q[1]=st;
    while (1){
        int x=q[top];
//    cout<<x<<'\n';
        h[x]=top;
        int y=v2[x][0];
        if (h[y]==-1){
            for(int i=1;i<=top;i++) h[q[i]]=-1;
            return 1;
        }
        if (h[y]) {
            int len=(top-h[y]+1);
            for(int i=1;i<=top;i++) h[q[i]]=-1;
            return 1+(len>1);
        }
        q[++top]=y;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v1[y].push_back(x);
        v2[x].push_back(y);
        deg[x]++;
    }
    ll ans=1;
    for(int st=1;st<=2*n;st++) if (deg[st]==0)
        ans=(ans*BFS1(st))%MOD;
//    cout<<"tick\n";
    for(int st=1;st<=2*n;st++) if (!h[st]) ans=(ans*BFS2(st))%MOD;
    cout<<ans;
}