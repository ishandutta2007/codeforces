#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
int main() {
    int n,s,mi=10*10*10*10*10*10*10*10*10;
    cin >> n;
    ll t,su=0,ans=0;
    cin >> t;
    int a[n];
    vector<int> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mi=min(mi,a[i]);
    }
    while(t>=mi){
            ll t1=t,sum=0,col=0;
            for(int u=0;u<n;u++){
                if (t1>=a[u]){
                    t1-=a[u];
                    sum+=a[u];
                    col++;

                }

            }

            ans+=(t/sum)*col;
            t=t%sum;
    }

    cout << ans;










    return 0;
}