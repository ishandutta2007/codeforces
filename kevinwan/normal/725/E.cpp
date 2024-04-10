#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int num[mn],nxt[mn],c;
bool eval(int x){
    bool u=0;
    int v=c,lf=inf;
    while(1){
        int y=nxt[min(v,lf)];
        if(!y)break;
        if(!u&&y<=x&&x<=v){
            u=1;
            v-=x;
            continue;
        }
        int ex=min(num[y],v/y);
        v-=ex*y;
        lf=y-1;
    }
    return v>0;
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>c>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        num[a]++;
    }
    for(int i=1;i<=c;i++){
        if(num[i])nxt[i]=i;
        else nxt[i]=nxt[i-1];
    }
    for(int i=1;i<=c;i++)if(eval(i)){printf("%d",i);return 0;}
    printf("Greed is good");
}