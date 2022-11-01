#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define po(x) (1ll<<x)
const int N = 2e5+7;
ll B[2][N],A[N];
int cnt_bit[N];
void NO(){
    cout<<"-1\n";
    exit(0);
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll sum = 0;
    for(int c = 0;c<2;++c)
        for(int i = 1;i<=n;++i) {
            cin >> B[c][i];
            sum += B[c][i];
        }
    if (sum%(n*2))
        NO();
    ll asum = sum/(n*2);
    const int mxbit = 40;
    for(int i = 1;i<=n;++i){
        A[i] = B[0][i]+B[1][i]-asum;
        if (A[i]<0 || A[i]%n)
            NO();
        A[i]/=n;
        for(int bit = 0;bit<=mxbit;++bit){
            if (A[i]&po(bit))
                ++cnt_bit[bit];
        }
    }
    for(int i = 1;i<=n;++i){
        ll b = 0,c = 0;
        for(int bit = 0;bit<=mxbit;++bit){
            if (A[i]&po(bit))
                b+=po(bit)*cnt_bit[bit],c+=po(bit)*n;
            else
                c+=po(bit)*cnt_bit[bit];
        }
        if (B[0][i]!=b || B[1][i]!=c)
            NO();
    }
    for(int i = 1;i<=n;++i)
        cout<<A[i]<<' ';
    cout<<endl;
    return 0;
}