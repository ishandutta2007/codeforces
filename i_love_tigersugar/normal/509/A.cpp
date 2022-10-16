#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
long long a[13][13];
int main(void) {
    int n;
    cin>>n;
    FOR(i,1,n) FOR(j,1,n) a[i][j]=i==1||j==1? 1:a[i-1][j]+a[i][j-1];
    long long res=0;
    FOR(i,1,n) FOR(j,1,n) res=max(res,a[i][j]);
    cout<<res<<endl;
    return 0;
}