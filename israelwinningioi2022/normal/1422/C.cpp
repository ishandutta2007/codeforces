#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9 + 7;

void add(int &a, int b){
    a =(a+b)%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    string s; cin>>s;
    int n = s.size();
    vi pref(n+1,0), suf(n+1);
    loop(i,0,n) pref[i+1] = (pref[i]*10 + s[i]-'0')%MOD;
    int mult = 1;
    loopr(i,0,n) suf[i] = (suf[i+1] + mult*(s[i]-'0'))%MOD, mult = mult*10%MOD;
    int ans = 0; mult = 1;
    loopr(i,0,n){
        //cout<<"SUF: "<<suf[i]<< " "<<i<<endl;
        add(ans, suf[i] * i);
        add(ans, pref[i]*mult);
        mult = (mult*10 + 1)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
107


*/