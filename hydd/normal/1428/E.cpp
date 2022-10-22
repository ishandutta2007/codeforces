#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[110000];
ll ans;
ll sqr(ll x){ return x*x;}
struct node{
    int x,c;
    node(int _x=0,int _c=0):x(_x),c(_c){}
    ll getval(int y) const{
        return (x%y)*sqr(x/y+1)+(y-x%y)*sqr(x/y);
    }
    ll calc() const{ return getval(c)-getval(c+1);}
    bool operator<(const node &a) const{
        return calc()<a.calc();
    }
};
priority_queue<node> que;
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]); ans+=sqr(a[i]);
        que.push(node(a[i],1));
    }
    k-=n;
    while (k--){
        node u=que.top(); que.pop();
        ans-=u.calc(); u.c++; que.push(u);
    }
    printf("%lld\n",ans);
    return 0;
}//