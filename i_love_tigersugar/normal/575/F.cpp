#include<bits/stdc++.h>
#define MAX   5050
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int main(void) {
    int n,x,l,r;
    scanf("%d%d",&n,&x);
    l=r=x;
    long long sum=0;
    REP(love,n) {
        int a,b;
        scanf("%d%d",&a,&b);
        if (max(a,l)<=min(b,r)) {
            l=max(a,l);
            r=min(b,r);
        } else if (b<l) {
            sum+=l-b;
            r=l;
            l=b;
        } else {
            sum+=a-r;
            l=r;
            r=a;
        }
    }
    cout<<sum<<endl;
    return 0;
}