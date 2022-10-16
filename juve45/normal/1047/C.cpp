#include <iostream>
#include <algorithm>
using namespace std;

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


int n, a[300010], cmmdc, x, r, f[15004001], nmax, lg, lgmax, c[15000100];
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n;
    cin>>a[1];
    cmmdc=a[1];

    for(int i=2; i<=n; i++) {
        cin>>x;
        a[i]=x;
        cmmdc = __gcd(cmmdc, x);
    }

    for(int i=1; i<=n; i++)
        a[i]=a[i]/cmmdc;
                
    for(int i = 1; i <= n; i++) {
        f[a[i]]++;
    }


    for(int i=2; i <= 15000000; i++) {
        int tmp = 0;
        if(c[i]) continue;
        for(int j = i; j <= 15000000; j += i) {
            tmp += f[j];
            c[j] = 1;
        }
        lgmax = max(lgmax, tmp);
    }

    if(lgmax==0)
        cout<<-1;
    else
        cout<<n-lgmax;
    return 0;
}