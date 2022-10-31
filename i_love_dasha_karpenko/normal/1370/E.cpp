#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E6+7;
const ll INF = 2E15;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM],B[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    ll cnt = 0,cnt1 = 0;
    forn(i,n){
        char ch;
        cin>>ch;
        if (ch=='1')A[i] = 1;
        cnt+=A[i];
    }
    forn(i,n){
        char ch;
        cin>>ch;
        if (ch=='1')B[i] = 1;
        cnt1+=B[i];
    }
    if (cnt!=cnt1){
        cout<<"-1\n";
        return 0;
    }
    ll S[2],C[2];
    S[0] = S[1] = 0;
    C[0] = C[1] = 0;
    ll res = 0;
    forn(i,n){
        if (A[i]==B[i]){
        }
        else{
            if (S[B[i]]>0){
                --S[B[i]];
                ++C[B[i]];
                --C[A[i]];
            }
            else {
                ++S[A[i]];
                if (C[A[i]]==0)++C[B[i]];
                else{
                    --C[A[i]];
                    ++C[B[i]];
                }
            }
        }


    }
    cout<<C[0]+C[1]<<endl;
    return 0;
}
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,