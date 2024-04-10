#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define SQR(x) (1LL*(x)*(x))
using namespace std;
int main(void) {
    int x1,y1,x2,y2,r;
    cin>>r>>x1>>y1>>x2>>y2;
    if (x1==x2 && y1==y2) return (cout<<0<<endl,0);
    r*=2;
    long long dis=SQR(x1-x2)+SQR(y1-y2);
    long long tmp=dis/SQR(r)+(dis%SQR(r)>0);
    long long res=sqrt(tmp);
    FOR (i,-7,7) if (res+i>0 && SQR(res+i)>=tmp) return (cout<<res+i<<endl,0);
    return 1;
}