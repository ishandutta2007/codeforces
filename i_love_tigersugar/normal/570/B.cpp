#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
int m,n;
int prob(int a) {
    if (m==a) return (0);
    if (a<m) {
        int c=(a+m)%2==0?(a+m)/2-1:(a+m)/2;
        return (max(0,c));
    } else {
        int c=(a+m)/2+1;
        return (max(0,n-c+1));
    }
}
int main(void) {
    cin>>n>>m;
    int best=m;
    FOR(i,m-10,m+10) if (1<=i && i<=n && prob(i)>prob(best)) best=i;
    cout<<best<<endl;
    return 0;
}