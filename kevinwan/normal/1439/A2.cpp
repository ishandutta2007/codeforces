#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=2e5+10;
const ll mod=1e9+7;

struct mv{int a,b,c,d,e,f;};
vector<mv>uu;
string a[mn];
void add(int aa,int b,int c,int d,int e,int f){
    uu.push_back({aa,b,c,d,e,f});
    a[aa][b]^=1;
    a[c][d]^=1;
    a[e][f]^=1;
}
void bac(){
    mv v=uu.back();
    uu.pop_back();
    a[v.a][v.b]^=1;
    a[v.c][v.d]^=1;
    a[v.e][v.f]^=1;
}
int hailveshy(){
    int n,m;
    cin>>n>>m;
    uu.clear();
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(char&c:a[i])c-='0';
    }
    for(int i=n-1;i>=2;i--){
        if(a[i][0])add(i,0,i-1,0,i-1,1);
        for(int j=1;j<m;j++)if(a[i][j]){
            add(i,j,i-1,j,i-1,j-1);
        }
    }
    for(int j=m-1;j>=2;j--){
        if(a[0][j])add(0,j,0,j-1,1,j-1);
        if(a[1][j])add(1,j,0,j-1,1,j-1);
    }
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)for(int l=0;l<2;l++){
        if(i)add(0,1,1,0,1,1);
        if(j)add(0,0,1,0,1,1);
        if(k)add(0,0,0,1,1,1);
        if(l)add(0,0,0,1,1,0);
        //printf("%d %d\n%d %d\n\n",a[0][0],a[0][1],a[1][0],a[1][1]);
        if(!a[0][0]&&!a[0][1]&&!a[1][0]&&!a[1][1]){
            break;
        }
        for(int m=0;m<i+j+k+l;m++)bac();
    }
    printf("%d\n",uu.size());
    for(auto v:uu)printf("%d %d %d %d %d %d\n",v.a+1,v.b+1,v.c+1,v.d+1,v.e+1,v.f+1);
    return 0;
}

int main(){
#ifdef LOCAL
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        hailveshy();
    }
}