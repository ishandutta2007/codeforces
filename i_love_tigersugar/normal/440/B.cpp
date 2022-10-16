#include<bits/stdc++.h>
#define MAX   50050
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
using namespace std;
typedef long long ll;
ll a[MAX],s;
ll r[MAX],l[MAX];
int n;
void process(void) {
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) s+=a[i];
    s/=n;
    r[1]=a[1]-s;
    ll res=0;
    FOR(i,2,n) {
        l[i]=r[i-1];
        a[i]+=l[i];
        r[i]=a[i]-s;
        res+=max(l[i],-l[i]);
    }
    cout<<res;
}
int main(void) {
    process();
    return 0;
}