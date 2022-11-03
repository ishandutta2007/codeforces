#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e5+10;
const double eps=1e-10;

int n,pro;
int a[N],b[N];
bool check(double need){
    double over=0;
    for(int i=0;i<n;i++) over+=max(.0,a[i]*need-b[i]);
    if (over>pro*need) return 0;
    return 1;
}
void solve(){
    ll sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    if (pro>=sum){
        printf("-1");
        return;
    }
    double L=0,R=1e12;
    for(int i=1;i<=300;i++){
        double mid=(L+R)/2;
        if (check(mid)) L=mid+eps;
        else R=mid-eps;
    }
    printf("%.9f",R);
}
int main(){
    cin>>n>>pro;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    solve();
}