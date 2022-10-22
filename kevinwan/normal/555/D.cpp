#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=2e5+10;
const ll mod=1e9+7;
ll inf=0x3f3f3f3f3f3f3f3f;
int p[mn];
int n,m;
int gr(int x,int l){
    int cur=x;
    for(int i=1<<17;i;i>>=1){
        if(cur+i>=n)continue;
        if(p[cur+i]-p[x]<=l)cur+=i;
    }
    return cur;
}
int gl(int x,int l){
    int cur=x;
    for(int i=1<<17;i;i>>=1){
        if(cur-i<0)continue;
        if(p[x]-p[cur-i]<=l)cur-=i;
    }
    return cur;
}
int main(){
    scanf("%d%d",&n,&m);
    vector<int>o(n);
    for(int i=0;i<n;i++)scanf("%d",p+i);
    iota(o.begin(),o.end(),0);
    sort(o.begin(),o.end(),[](int a,int b){return p[a]<p[b];});
    vector<int>ro(n);
    for(int i=0;i<n;i++)ro[o[i]]=i;
    sort(p,p+n);
    while(m--){
        int a,l;
        scanf("%d%d",&a,&l);
        a--;
        a=ro[a];
        int b=gr(a,l);
        l-=p[b]-p[a];
        a=b;
        while(1){
            int cont=0;
            b=gl(a,l);
            int d=p[a]-p[b];
            if(d) {
                int num = l / d;
                l %= d;
                if (num & 1)a = b;
                cont=1;
            }
            b=gr(a,l);
            d=p[b]-p[a];
            if(d) {
                int num = l / d;
                l %= d;
                if (num & 1)a = b;
                cont=1;
            }
            if(!cont)break;
        }
        printf("%d\n",o[a]+1);
    }
}