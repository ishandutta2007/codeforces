#include<cstdio>
#include<iostream>
#define MAX    500500
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
using namespace std;
typedef long long ll;
inline int nextint(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
ll s[MAX];
int main(void) {
    int n=nextint();
    FOR(i,1,n) s[i]=s[i-1]+nextint();
    int cnt=0;
    if (s[n]%3!=0) {
        cout<<0;
        return 0;
    }
    ll res=0;
    FORD(i,n-1,2) {
        if (s[i]==s[n]/3*2) cnt++;
        if (s[i-1]==s[n]/3) res+=cnt;
    }
    cout<<res;
    return 0;
}