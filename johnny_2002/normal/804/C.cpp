#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define X first
#define Y second

const int N=6e5+10;
const int MOD=1e9+7;


int n,m;

vector <int> gr[N],v[N];

struct BIT{
    int b[N];
    void add(int x,int val){
        while (x<N){
            b[x]+=val;
            x+=x&-x;
        }
    }
    int findfirstfree(){
        int ans=0;
        for(int i=20;i>=0;i--){
            int cur=ans+(1<<i);
            if (cur>=N) continue;
            if (b[cur]==(1<<i)) ans=cur;
        }
        return ans+1;
    }
    int get(int x){
        int ans=0;
        while (x){
            ans+=b[x];
            x-=x&-x;
        }
        return ans;
    }
}mbit;


int q[N],pa[N];
void BFS(){
    int top=1,bot=1;
    q[1]=1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (y!=pa[x]){
            pa[y]=x;
            q[++bot]=y;
        }
    }
}
int ansc[N];
int pans[N];
void solve(){
    BFS();
    int ansn=1;
    for(int pha=1;pha<=n;pha++){
        int x=q[pha];
        for(auto y:gr[x]) if (ansc[y])
            if (mbit.get(ansc[y])==mbit.get(ansc[y]-1))
                mbit.add(ansc[y],1);
        for(auto y:gr[x]) if (!ansc[y]){
            ansc[y]=mbit.findfirstfree();
            if (ansc[y]>ansn) ansn++;
            if (mbit.get(ansc[y])==mbit.get(ansc[y]-1))
                mbit.add(ansc[y],1);
        }
        for(auto y:gr[x]) if (mbit.get(ansc[y])!=mbit.get(ansc[y]-1))
            mbit.add(ansc[y],-1);
    }
    for(int i=1;i<=m;i++) if (!ansc[i]) ansc[i]=1;
    cout<<ansn<<'\n';
    for(int i=1;i<=m;i++) cout<<ansc[i]<<" ";
}
void prepare(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        int n1,x;
        scanf("%d",&n1);
        while (n1--){
            scanf("%d",&x);
            gr[i].push_back(x);
        }
    }
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
int main(){
    prepare();
    solve();
}