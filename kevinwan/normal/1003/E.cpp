#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=1e6+10;
void die(){
    printf("NO");
    exit(0);
}
int p[mn],cur=1,dep[mn];
int main(){
    int n,d,k;
    scanf("%d%d%d",&n,&d,&k);
    if(n-1<d)die();
    if(k==1){
        if(n==2&&d==1)printf("YES\n1 2");
        else printf("NO");
        return 0;
    }
    d++;
    int i;
    dep[1]=1;
    for(i=2;i<=d;i++){
        cur++;
        p[cur]=cur-1;
        dep[cur]=dep[p[cur]]+1;
    }
    for(i=2;i<=d;i++)dep[i]=max(dep[i],d+1-i);
    stack<pii>s;
    for(i=2;i<d;i++)s.push({i,k-2});
    while(cur!=n&&s.size()){
        int a=s.top().first,b=s.top().second;
        s.pop();
        if(!b)continue;
        if(b-1)s.push({a,b-1});
        cur++;
        p[cur]=a;
        dep[cur]=dep[p[cur]]+1;
        if(dep[cur]!=d)s.push({cur,k-1});
    }
    if(cur!=n)die();
    printf("YES\n");
    for(i=2;i<=n;i++)printf("%d %d\n",i,p[i]);
}