#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int INF = 1e9+7;
int gi(char ch){
    return ch-'0';
}
int sum(string &s){
    int res = 0;
    int n = s.size();
    for(int i = 1;i<n-1;i+=1){
        res += gi(s[i])*11;
    }
    res += gi(s[0])*10;
    res += gi(s[n-1])*1;
    return res;
}
int rep(string &s,int pos,bool val){
    int ps = -1;
    for(int i = 0;i<s.size();i+=1){
        if (gi(s[i])==val && (ps==-1 || abs(pos-ps)>abs(pos-i))){
            ps = i;
        }
    }
    if (ps==-1){
        return INF;
    }
    swap(s[pos],s[ps]);
    return abs(pos-ps);
}

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int res = sum(s);
    for(int bg = 0;bg<2;bg+=1){
        for(int en = 0;en<2;en+=1){
            string dum = s;
            int ss = rep(dum,0,bg);
            ss += rep(dum,n-1,en);
            if (ss<=k) {
                res = min(res,sum(dum));
            }
        }
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}