#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define int long long
using namespace std; using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pii;
template <typename T, class cmp = less<T>> using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename X = null_type> using hash_map = gp_hash_table<T, X>;

const int sq2 = 200;
const int sq = 100100/sq2;
int hm[100005*(sq2+5)];
int freq[2500005];
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    int ans = 0;
    if(true){
        //cerr << "nae\n";
        for(int i = 0; i<=sq2; i++){
        
            int mx = 0;
            for(int j = 1; j<=n; j++){
                hm[a[j]+i*(n-j)]++;
                mx = max(mx,hm[a[j]+i*(n-j)]);
            }
            for(int j = 1; j<=n; j++){
                hm[a[j]+i*(n-j)] = 0;
                //mx = max(mx,hm[a[j]+i*(n-j)]);
            }
            ans = max(ans,mx);
        }
        reverse(a.begin()+1,a.end());
    }
    if(true){
        //cerr << "nae\n";
        for(int i = 0; i<=sq2; i++){
        
            int mx = 0;
            for(int j = 1; j<=n; j++){
                hm[a[j]+i*(n-j)]++;
                mx = max(mx,hm[a[j]+i*(n-j)]);
            }
            for(int j = 1; j<=n; j++){
                hm[a[j]+i*(n-j)] = 0;
                //mx = max(mx,hm[a[j]+i*(n-j)]);
            }
            ans = max(ans,mx);
        }
        reverse(a.begin()+1,a.end());
    }
    if(true){
        map<pair<int,int>,int>hm;
        for(int i = 1; i<=min(sq,n); i++){
            for(int j = i+1; j<=min(sq,n); j++){
                if((a[j]-a[i])%(j-i)==0){
                    int d = (a[j]-a[i])/(j-i);
                    int st = a[j]-d*j;
                    int v = hm[{st,d}];
                    freq[v]--;
                    hm[{st,d}]++;
                    freq[v+1]++;
                }
            }
        }
        //cout << *--s.end() << "\n";
        for(int j = 1; j<=sq+5; j++){
            if(freq[j*(j-1)/2])ans = max(ans,j);
        }
        for(int i = sq+1; i<=n; i++){
            for(int j = i-sq+1; j<i; j++){
                if((a[i]-a[j])%(i-j)==0){
                    int d = (a[i]-a[j])/(i-j);
                    int st = a[j]-d*j;
                    int v = hm[{st,d}];
                    freq[v]--;
                    hm[{st,d}]++;
                    freq[v+1]++;
                }
                if((a[j]-a[i-sq])%(j-(i-sq))==0){
                    int d = (a[j]-a[i-sq])/(j-(i-sq));
                    int st = a[j]-d*j;
                    int v = hm[{st,d}];
                    freq[v]--;
                    hm[{st,d}]--;
                    freq[v-1]++;
                    if(hm[{st,d}]==0)hm.erase({st,d});
                }
            }
            for(int j = 1; j<=sq+5; j++){
                if(freq[j*(j-1)/2])ans = max(ans,j);
            }
        }
    }
    cout << n-ans << "\n";
    
    return 0;
}