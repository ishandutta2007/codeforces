#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'a')
const int INF = 1e6+7;
const int N = 1e6+7;
int P[N][4],A[N],V[N][4];
void add(int val,int pos){
    for(int i = 0;i<4;++i)
        V[pos][i] = INF,P[pos][i] = -1;
    for(int i = 0;i<4;++i) {
        if (V[pos-1][i]==INF)
            continue;
        int f, s;
        if (i < 2)
            s = V[pos - 1][i], f = A[pos - 1];
        else f = V[pos - 1][i], s = A[pos - 1];
        if (i==0)
            f = -f;
        if(i==2) s = -s;
        if (val < f)
            continue;
        if (-val < f && f < val && val < s) {
            if (V[pos][1] > s) {
                V[pos][1] = s;
                P[pos][1] = i;
            }
        }
        if (f < -val && val < s) {
            if (V[pos][0] > s) {
                V[pos][0] = s;
                P[pos][0] = i;
            }
        }
        if (-val < f && s < val) {
            if (V[pos][3] > f) {
                V[pos][3] = f;
                P[pos][3] = i;
            }
        }
        if (f < -val && -val < s && s < val) {
            if (V[pos][0] > s) {
                V[pos][0] = s;
                P[pos][0] = i;
            }
            if (V[pos][3] > f) {
                V[pos][3] = f;
                P[pos][3] = i;
            }
        }
        if (s < -val) {
            if (V[pos][2] > f) {
                V[pos][2] = f;
                P[pos][2] = i;
            }
        }
    }
}
bool F = 0;
void solve() {
    int n;
    cin>>n;

    cin>>A[1];
    for(int i = 0;i<4;++i)
        V[1][i] = INF;
    V[1][2] = -INF;
    for(int i = 2;i<=n;++i){
        cin>>A[i];
        add(A[i],i);
    }
    int en = -1;
    for(int i = 0;i<4;++i)
        if (V[n][i]!=INF){
            en = i;
        }
    int pos = n;
    if (en!=-1){

        while(pos!=0){
            if (!(en&1))
                A[pos] = -A[pos];
            en = P[pos][en];
            --pos;
        }
        bool flag = 0;
        pair<int,int> p = {-INF,-INF};
        for(int i = 1;i<=n;++i){
            if (A[i]<p.first){
                flag = 1;
                break;
            }
            if (A[i]>p.second)
                p.second = A[i];
            else if (A[i]>p.first)
                p.first = A[i];
        }
        if (F || flag) {
            cout<<"YES\n";
            for (int i = 1; i <= n; ++i)
                cout << A[i] << ' ';
            cout <<endl;
        }
        if (flag)
            return;
    }
    else
        if (F)
        cout<<"NO\n";
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
        F = 1;
    while(t--)
        solve();
}