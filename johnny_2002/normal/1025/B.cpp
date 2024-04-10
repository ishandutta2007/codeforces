#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,a[N][2];
int solve(){
        for(int j=0;j<=1;j++){
                long long cur=a[1][j];
                for(int i=2;i<=n;i++)
                        cur=__gcd(cur,1LL*a[i][0]*a[i][1]);
                if (cur==1) continue;
                for(int i=2;i*i<=cur;i++) if (cur%i==0) return i;
                return cur;
        }
        return -1;
}
int main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
        cout<<solve();
}