#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int b[N],n,q,t[N];
stack <int> s;
void add(int x,int v){
    while (x<=n){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
int findfre(int v){
    int ans=n+1,pos=0;
    for(int i=1<<int(log2(n));i>0;i>>=1){
        int cur=pos+i;
        if (cur>n) continue;
        if (v>b[cur]) v-=b[cur],pos=cur;
        else if (v==b[cur]) ans=cur;
    }
    return ans;
}
int root(int x){
    while (t[x]>0){
        s.push(x);
        x=t[x];
    }
    while (!s.empty()) t[s.top()]=x,s.pop();
    return x;
}
void merge(int x,int y){
    x=root(x),y=root(y);
    if (x==y) return;
    if (t[x]<t[y]) t[x]+=t[y],t[y]=x;
    else t[y]+=t[x],t[x]=y;
}
int main(){
    scanf("%d%d",&n,&q);
    //
    FOR(i,1,n) add(i,1);
    memset(t,-1,sizeof(t));
    //
    int type,x,y;
    while (q--){
        scanf("%d%d%d",&type,&x,&y);
        if (type==3){
            if (root(x)==root(y)) printf("YES\n");
            else printf("NO\n");
        }else if (type==2){
            int v=get(x-1)+1;
            while (1){
                int cur=findfre(v);
                if (cur<y){
                    merge(cur,cur+1);
                    add(cur,-1);
                }else break;
            }
        }else merge(x,y);
    }
}