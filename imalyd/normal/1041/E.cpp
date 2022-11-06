//Problem E
#include<bits/stdc++.h>
using namespace std;
#define NO {printf("NO");return 0;}
const int N=1005;
int n,y[N],c[N];
//struct node{int v,id;}nod[N];
//bool operator<(node a,node b){return a.v<b.v;}
//multiset<node>S;
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        if(y!=n)NO
        ++c[x];
    }
    ++c[n];
    int sz=1;
    for(int i=1;i<=n;i++)if(c[i])y[sz]=i,sz+=c[i];
    int last=1,lust=1;
    while(last<=n){
        if(!c[last]){
            while(y[lust])++lust;
            y[lust]=last;
        }
        ++last;
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,y[i]);
        --c[mx];
    }
    for(int i=1;i<=n;i++)if(c[i])NO
    printf("YES");
    for(int i=1;i<n;i++)printf("\n%d %d",y[i],y[i+1]);
    return 0;
}