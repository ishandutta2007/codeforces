//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
//#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;
const int N = 10;
int po[N];
const int masksz = 1<<N;
const int AL = 52;
int dp[AL][masksz];
pair<int,int> P[AL][masksz];

int pos[N][AL][2];
int gi(char ch){
    if ('a'<=ch && ch<='z')
        return int(ch-'a');
    else return 26+int(ch-'A');
}
char gc(int ind){
    if (ind<26)
        return char(ind+'a');
    else return char(ind-26+'A');
}
int sz,n;
int calc(int symb,int mask){

    if (dp[symb][mask]!=-1)
        return dp[symb][mask];
    int valid = 1;
    for(int bit = 0;bit<n;++bit){
        int is_bit = (mask&po[bit])!=0;
        if (pos[bit][symb][is_bit]==-1){
            valid = 0;
            break;
        }
    }
    if (!valid){
        dp[symb][mask] = 0;
        P[symb][mask] = {-1,-1};
        return 0;
    }
    dp[symb][mask] = 1;
    P[symb][mask] = {-1,-1};
    for(int bit = 0;bit<n;++bit){
        int is_bit = (mask&po[bit])!=0;
        if (is_bit){
            int ret = calc(symb,mask^po[bit]);
            if (ret>dp[symb][mask]){
                dp[symb][mask] = ret;
                P[symb][mask] = P[symb][mask^po[bit]];
            }
        }
    }

    for(int prev = 0;prev<AL;++prev){
        int prmask = 0,can = 1;
        for(int bit = 0;bit<n;++bit){
            int is_bit = (mask&po[bit])!=0;
            if (pos[bit][prev][0]==-1 || pos[bit][prev][0]>=pos[bit][symb][is_bit]){
                can = 0;
                break;
            }
            if (pos[bit][prev][1]!=-1 && pos[bit][prev][1]<pos[bit][symb][is_bit])
                prmask^=po[bit];
        }
        if (!can)
            continue;
        int ret = calc(prev,prmask)+1;
        if (ret>dp[symb][mask]){
            dp[symb][mask] = ret;
            P[symb][mask] = {prev,prmask};
        }


    }
    return dp[symb][mask];
}
void solve(){
    cin>>n;
    sz = 1<<n;
    memset(dp,-1,sizeof(dp));
    memset(pos,-1,sizeof(pos));
    for(int i = 0;i<n;++i){
        string s;
        cin>>s;
        int len = s.size();
        for(int j = 0;j<len;++j){
            if (pos[i][gi(s[j])][0]==-1)
                pos[i][gi(s[j])][0] = j;
            else pos[i][gi(s[j])][1] = j;
        }
    }

    int res = 0,msk = -1,symb = -1;
    for(int c = 0;c<AL;++c)
        for(int mask = 0;mask<sz;++mask){
            int ret = calc(c,mask);
            if (ret>res){
                res = ret;
                msk = mask;
                symb = c;
            }
        }
    cout<<res<<endl;
    string ans;
    while(symb!=-1){
        ans+=gc(symb);
        pair<int,int> buf = P[symb][msk];
        symb = buf.first;
        msk = buf.second;
    }
    reverse(all(ans));
    cout<<ans<<endl;
}
signed main() {
    po[0] = 1;
    for(int i = 1;i<N;++i)
        po[i] = po[i-1]<<1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}