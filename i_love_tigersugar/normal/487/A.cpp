#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int INF=(int)1e9+7;
int mh,ma,md,eh,ea,ed,ch,ca,cd;
inline int ceil(int a,int b) {
    if (b==0) return (INF);
    return (a/b+(a%b>0));
}
int minAtk(int h,int d,int t) {
    if (t==0) return (INF);
    int needA=ceil(h+t*d,t);
    return (needA<=ma?0:ca*(needA-ma));
}
int minCost(int a,int t) {
    if (md>=a) return (0);
    int res=INF;
    FOR(d,md,a) {
        int buyD=cd*(d-md);
        int needH=t*a-t*d+1;
        res=min(res,buyD+ch*max(0,needH-mh));
    }
    return (res);
}
int main(void) {
    cin>>mh>>ma>>md>>eh>>ea>>ed>>ch>>ca>>cd;
    int res=INF;
    FOR(t,0,150) res=min(res,minAtk(eh,ed,t)+minCost(ea,t));
    cout<<res;
    return 0;
}