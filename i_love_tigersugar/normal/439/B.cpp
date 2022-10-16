#include<bits/stdc++.h>
#define MAX   100100
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
int a[MAX],n,x;
void process(void) {
    cin>>n>>x;
    REP(i,n) cin>>a[i];
    ll res=0;
    sort(a,a+n);
    REP(i,n) {
        res+=1LL*x*a[i];
        if (x>1) x--;
    }
    cout<<res;
}
int main(void) {
    process();
    return 0;
}