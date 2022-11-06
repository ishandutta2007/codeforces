//Problem C
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,d,tot,ans[N];
struct node{int v,id;}nod[N];
bool operator<(node a,node b){return a.v<b.v;}
multiset<node>S;
int main(){
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=n;i++)scanf("%d",&nod[i].v),nod[i].id=i;
    sort(nod+1,nod+n+1);
    for(int i=1;i<=n;i++){
        int v=nod[i].v,u=v-d-1;
        multiset<node>::iterator it=S.upper_bound((node){u,i});
        int get;
        if(it==S.begin())get=++tot;
        else get=(*(--it)).id,S.erase(it);
        ans[nod[i].id]=get,S.insert((node){v,get});
    }
    printf("%d\n",tot);
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}