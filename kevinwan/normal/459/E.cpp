#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> ppi;
#define F first
#define S second
#define mp(a,b,c) make_pair(a,make_pair(b,c))
int ml[300001],ln[300001],me[300001];
ppi e[300001];
int main(){
    int n,m,a,b,c,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)scanf("%d%d%d",&a,&b,&c),e[i]=mp(c,a,b);
    sort(e,e+m);
    for(i=0;i<m;i++){
        a=e[i].S.F,b=e[i].S.S,c=e[i].F;
        int pot;
        if(me[a]==c)pot=ln[a]+1;
        else pot=ml[a]+1;
        if(pot>ml[b]){
            if(me[b]!=c)ln[b]=ml[b];
            ml[b]=pot,me[b]=c;
        }
    }
    int ans=0;
    for(i=1;i<=n;i++)ans=max(ans,ml[i]);
    printf("%d",ans);
}