#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<=(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long ll;
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
int a[MAX];
int n;
int main(void) {
    ios::sync_with_stdio(false);
    n=nextInt();
    FOR(i,1,n) a[i]=nextInt();
    sort(a+1,a+n+1,greater<int>());
    int cnt=n;
    ll s=1LL*n*a[1];
    FOR(i,2,n) {
        s+=1LL*a[i]*cnt;
        cnt--;
    }
    cout<<s;
    return 0;
}