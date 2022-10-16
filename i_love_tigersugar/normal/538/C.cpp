#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
const string no="IMPOSSIBLE";
int x[MAX],y[MAX],n,m;
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d%d",&x[i],&y[i]);
}
void process(void) {
    int res=-1;
    FOR(i,1,m-1) {
        if (y[i+1]-y[i]>x[i+1]-x[i]) {
            cout<<no<<endl;
            return;
        }
        if (y[i]-y[i+1]>x[i+1]-x[i]) {
            cout<<no<<endl;
            return;
        }
        res=max(res,y[i]);
        res=max(res,y[i+1]);
        res=max(res,(y[i]+y[i+1]+x[i+1]-x[i])/2);
    }
    res=max(res,y[1]+x[1]-1);
    res=max(res,y[m]+n-x[m]);
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}