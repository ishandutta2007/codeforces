//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 1E6+7;
ll n,s;
int cnt[N],A[N];

bool F(int lim){
    for(int i = 1;i<=n;++i)
        A[i] = cnt[i];
    if (lim==1)
        for(int i = 1;i<=n;++i){
            if (cnt[i]>1)
                return 0;
        }
    int need = 0;
    for(int i = 2;i<=n;++i){
        ll dif = max(0ll,ll(ll(A[i])-ll(A[i-1])*lim));
        need+=dif;
        A[i+1]+=dif;
        A[i]-=dif;
    }
    int ptr = 2;
    for(int i = n;i>=1;--i){
        while(A[i]!=0) {
            while (A[ptr] == A[ptr - 1] * lim)
                ++ptr;
            if (i <= ptr)
                break;
            int dif = min(need, i - ptr);
            if (dif==0)
                break;
            need -= dif;
            A[i]--;
            A[i - dif]++;
        }
    }
    if (need)
        return 0;
    return 1;
}
void solve(){
    cin>>n>>s;
    for(int i = 1;i<=n;++i)
        cnt[i] = 1;
    ll sum = n*(n+1)/2;
    int ptr = n;
    while(sum>s){
        while(cnt[ptr]==0)
            --ptr;
        if (ptr<=2)
            break;
        ll dif = min(sum-s,ll(ptr-2));
        cnt[ptr]--;
        cnt[ptr-dif]++;
        sum-=dif;
    }
    if (sum!=s){
        cout<<"No\n";
        return;
    }

    cout<<"Yes\n";
    int l = 1,r = n;
    while(l!=r){
        int tm = (l+r)/2;
        if (F(tm))
            r = tm;
        else l = tm+1;
    }
    F(l);
    vector<int> prev = {1},cur;
    ptr = 1;
    for(int i = 2;i<=n;++i){
        for(int j = 1;j<=A[i];j+=l){
            for(int k = j;k<=min(A[i],j+l-1);++k){
                cout<<prev.back()<<' ';
                cur.push_back(++ptr);
            }
            prev.pop_back();
        }
        swap(prev,cur);
        cur.clear();
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}