#pragma GCC Optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long ld;
typedef unsigned long long ull;

#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define po(x) (ull(1)<<x)

const int K = 10;
const int N = 41;

ull act_mask[K];
ull pref[K][N];
int n,k;
bool solve(ull mask,ull act,int k){
    if (k==::k) {
        bool prev = 0;
        bool flag = 0;
        for(int bit = 0;bit<n;++bit){
            if (!(act&po(bit))){
                if (flag)
                    return 0;
                flag = 1;

                bool prev = 0,next = 1;
                if (bit>0)
                    prev = (mask&po(bit-1))>>(bit-1);
                if (bit+1<n)
                    next = (mask&po(bit+1))>>(bit+1);
                if (prev!=0 || next!=1)
                    return 0;
                continue;
            }
            bool cur = (mask&po(bit))>>bit;
            if (prev>cur)
                return 0;
            prev = cur;
        }
        return 1;
    }
    ull one_mi = __builtin_popcountll(mask&(act&act_mask[k]));
    ull undef = __builtin_popcountll((po(n)-1-act)&act_mask[k]);
    ull new_act = act|act_mask[k];
    for(int ones = one_mi;ones<=one_mi+undef;++ones){
        ull nmask = (mask-(mask&act_mask[k]))|pref[k][ones];
        if (nmask<mask){
            int h;
            ++h;
        }

        if (!solve((mask-(mask&act_mask[k]))|pref[k][ones],new_act,k+1))
            return 0;
    }
    return 1;
}

void solve(){

    cin>>n>>k;
    for(int i = 0;i<k;++i){
        int len;
        cin>>len;
        vector<int> pz;
        for(int j = 0;j<len;++j){
            int pos;
            cin>>pos;
            --pos;
            pz.push_back(pos);
            act_mask[i]^=po(pos);
        }
        reverse(all(pz));
        for(int j = 0;j<len;++j){
            pref[i][j+1] = pref[i][j]^po(pz[j]);
        }
    }
    if (solve(0,0,0))
        cout<<"ACCEPTED\n";
    else cout<<"REJECTED\n";
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}