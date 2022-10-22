#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], b[maxn];
vector<int> a1, a2;
vector<int> u1, u2;
void work(vector<int> &d){
    fors(i,0,u1.size()){
        int x = u1[i];
        int pos = upper_bound(u2.begin(), u2.end(), x)-u2.begin();
        if(pos == u2.size()){
            u2.pb(x);
            d.pb(u2.size());
        }else{
            if(pos == 0) d.pb(0);
            else u2[pos] = x, d.pb(pos+1);
        }
    }
    return;
}
int sol(int l, int r){
    u1.clear(); u2.clear();
    a1.clear(); a2.clear();
    fors(i,l+1, r){
        u1.pb(a[i]-(i-l));
    }
    u2.pb(a[l]);
    work(a1);

    u1.clear(); u2.clear();
    for(int i = r-1; i > l; --i){
        u1.pb(-(a[i]+(r-i)));
    }
    u2.pb(-a[r]);
    work(a2);
    int num = a1.size();
    int ans = 0;
    fors(i,0,num){
        if(a1[i] && a2[num-1-i]) ans = max(a1[i]+a2[num-1-i]-3, ans);
    }
    ans = (r-l-1)-ans;
    return ans;
}
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    fors(i,1,n+1) scanf("%d", &a[i]);
    fors(i,1,k+1) scanf("%d", &b[i]);
    b[0] = 0; b[k+1] = n+1;
    a[0] = -5e8; a[n+1] = 1e9+5e8;
    int ans = 0;
    for(int i = 1; i <= k+1; ++i){
        if(b[i]-b[i-1] > a[b[i]]-a[b[i-1]]){
            puts("-1"); return 0;
        }
        ans += sol(b[i-1], b[i]);
       // cout<<"l:"<<b[i-1]<<" r:"<<b[i]<<" ans:"<<ans<<endl;
    }
    cout<<ans<<endl;
}