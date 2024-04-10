#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi() int(x-'0')
#define div dsfds
const ll MOD = 1e13+123;
const int N = 1e6+7;
int div[N];
ll po[N];
struct number_set{
    bool vis[N];
    int cnt;
    ll val;
    number_set(){
        cnt = 0;
        memset(vis,0,sizeof(vis));
    }
    void add_simp(int simp){
        cnt-=vis[simp];
        val-=po[simp]*vis[simp];
        vis[simp]^=1;
        cnt+=vis[simp];
        val+=po[simp]*vis[simp];
        val-=MOD*(val>=MOD);
        val+=MOD*(val<0);
    }
    void add_num(int num){
        while(num>1){
            int dv = div[num];
            bool cnt = 0;
            while(num%dv==0)
                num/=dv,cnt^=1;
            if (cnt)
                add_simp(dv);
        }
    }
    void clear(){
        for(int i = 0;i<N;++i)
            vis[i] = 0;
        cnt = 0;
        val = 0;
    }
};
number_set A;
bool nt[N];
void solve() {
    int n;
    cin>>n;

    if (!(n&3)){
        int k = n>>1;
        for(int i = 1;i<=k;++i)
            A.add_simp(i);
        cout<<n-(A.cnt!=0)<<endl;
        for(int i = 1;i<=n;++i)
            if (A.cnt==0 || i!=k)
                cout<<i<<' ';
        cout<<endl;
    }
    else{
        int k = n>>1;
        int lst = 0;
        if (n&1)
            lst = n;
        for(int i = 1;i<=k;++i){
            A.add_num(i);
        }
        for(int i = 1;i<=lst;++i){
            A.add_num(i);
        }
        if (k&1)
            A.add_num(2);
        if (A.cnt!=0){
            map<ll,int> M;
            M[A.val] = 0;
            bool flag = 0;
            for(int i = 1;i<=n;++i){
                A.add_num(i);
                if (A.cnt==0){
                    nt[i] = 1;
                    flag = 1;
                    break;
                }
                M[A.val] = i;
            }
            if (!flag){
                A.clear();
                for(int i = 1;i<=n;++i){
                    A.add_num(i);
                    if (M[A.val]){
                        flag = 1;
                        nt[M[A.val]] = 1;
                        nt[i] = 1;
                        break;
                    }
                }
                if (!flag){
                    nt[2] = nt[k] = nt[n] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i = 1;i<=n;++i)
            cnt+=nt[i]^1;
        cout<<cnt<<endl;
        for(int i = 1;i<=n;++i)
            if (!nt[i])
                cout<<i<<' ';
        cout<<endl;
    }
}
signed main(){
    po[0] = 1;
    for(int i = 1;i<N;++i)
        po[i] = (po[i-1]<<1)%MOD;

    div[1] = 1;
    for(int i = 2;i<N;++i){
        if (div[i])
            continue;
        div[i] = i;
        for(ll j = ll(i)*i;j<N;j+=i)
            div[j] = i;
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //+cin>>t;

    while(t--)
        solve();
}