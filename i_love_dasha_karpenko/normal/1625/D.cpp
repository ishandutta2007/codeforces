#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int N = 3e5+7;
vector<int> ans;
int solve(vector<pair<int,int> > &V,int k,int bit){
    if (V.empty())
        return 0;
    if (bit<0){
        if (k==0){
            for (auto [to, pos]:V)
                ans.push_back(pos);
            return V.size();
        }
        else {
            ans.push_back(V[0].second);
            return 1;
        }
    }
    vector<pair<int,int> > A,B;
    for(auto [to,pos]:V)
        if (to&(1<<bit))
            B.push_back(mp(to,pos));
        else A.push_back(mp(to,pos));
    if (bit==4){
        int h;
        ++h;
    }
    if (k&(1<<bit)){
        unordered_map<int,int> M[bit+1];
        for(auto [to,pos]:A){
            int bit_mask = 0;
            for(int b = bit;b>=0;--b){
                bit_mask += to&(1<<b);
                M[b][bit_mask] = pos;
            }
        }
        for(auto [to,pos]:B){
            int bit_mask = 0;
            int kmask = 0;
            for(int b = bit;b>=0;--b){
                bit_mask += to&(1<<b);
                kmask += k&(1<<b);
                if (k&(1<<b))
                    continue;
                if (M[b].count(kmask^bit_mask^(1<<b))){
                    ans.push_back(M[b][kmask^bit_mask^(1<<b)]);
                    ans.push_back(pos);
                    return 2;
                }
            }
            if (M[0].count(kmask^bit_mask)){
                ans.push_back(M[0][kmask^bit_mask]);
                ans.push_back(pos);
                return 2;
            }
        }
        ans.push_back(V[0].second);
        return 1;
    }
    else{
        return solve(A,k,bit-1)+solve(B,k,bit-1);
    }
}
void solve() {
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> > V(n);
    for(int i = 0;i<n;++i)
        cin>>V[i].first,V[i].second = i+1;
    int qnt = solve(V,k,30);
    if (qnt<2){
        cout<<"-1\n";
    }
    else{
        cout<<qnt<<endl;
        for(int to:ans)
            cout<<to<<' ';
        cout<<endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}