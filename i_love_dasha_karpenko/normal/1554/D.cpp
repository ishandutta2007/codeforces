//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int ALP = 27;
const int DIM = 1E5+7;
int ans[DIM];
char to_ch(int x){
    return char('a'+x-1);
}
void solve(){
    int n;
    cin>>n;
    int symb = 1,z_cnt = 0,pos = 0;
    while(n){
        int bit = 1;
        while(bit*2<=n)
            bit*=2;
        if (bit==2){
            bit = 1;
        }
        if (bit==1){
            ans[++pos] = symb;
            --n;
            ++symb;
            continue;
        }
        int a = bit/2-1;
        for(int i = 1;i<=a;++i)
            ans[++pos] = symb;
        ans[++pos] = -1;

        for(int i = 1;i<=a+1;++i)
            ans[++pos] = symb;
        ++symb;
        n-=bit;
    }
    for(int i = 1;i<=pos;++i){
        if (ans[i]==-1)
            ++z_cnt;
    }
    if (z_cnt%2==0)
        --z_cnt;
    for(int i = 1;i<=pos;++i){
        if (ans[i]!=-1)
            cout<<to_ch(ans[i]);
        else if (z_cnt){
            --z_cnt;
            cout<<to_ch(26);
        }
        else cout<<to_ch(25);
    }
    cout<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/**
1
6 3
111001
111100
10 3
1101000000
1011000000

**/