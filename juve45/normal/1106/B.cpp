#include <bits/stdc++.h>
#define MAX 300010
using namespace std;
int n,m,x,y,st=1;
long long int ans;
struct food{
    int a,c;
    int poz;
};
food V[MAX],T[MAX];
food* P[MAX];
inline bool compar(food&A,food&B ){return A.c<B.c;}
int main(){
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;++i){
        cin>>V[i].a;
        V[i].poz=i;
    }
    for(i=1;i<=n;++i)cin>>V[i].c;
    sort(V,V+n+1,compar);
    for(i=1;i<=n;++i){
        P[V[i].poz]=&V[i];
    }
    for(j=0;j<m;++j){
        scanf("%d%d", &x, &y);
        ans=0;
        if(st>n){
            cout<<0<<'\n';
            continue;
        }
        if(P[x]->a>=y){
            P[x]->a-=y;
            ans=(long long int)1*y*P[x]->c;
        }else{
            ans=(long long int)1*P[x]->a*P[x]->c;
            y-=P[x]->a;
            P[x]->a=0;
            for(i=st;i<=n;++i){
                if(V[i].a>=y){
                    V[i].a-=y;
                    ans+=(long long int)1*y*V[i].c;
                    y=0;
                    break;
                }else{
                    ans+=(long long int)1*V[i].a*V[i].c;;
                    y-=V[i].a;
                    V[i].a=0;
                    ++st;
                }
            }
            if(y>0) ans=0;
        }
        cout<<ans<<'\n';
    }
    return 0;
}