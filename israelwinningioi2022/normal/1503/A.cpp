#include <bits/stdc++.h>
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
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e9, MOD = 1e9+7;

template <class A, class B> pair<A,B> operator+(pair<A,B>& a, pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(pair<A,B>& a, pair<A,B>& b) {
    return {a.x-b.x, a.y-b.y}; }
template <class A, class B> istream& operator>>(istream& is, pair<A,B>& a) {
    return is >> a.x >> a.y; }
template <class A, class B> ostream& operator << (ostream& os, const pair<A,B>& a) {
    return os << "< " << a.x << " , " << a.y << " >"; }

template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; loop(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);

int solve(){
    int n; cin>>n;
    string s; cin>>s; 
    for(auto &c:s) c-='0';
    vi good(n+1);
    loopr(i,0,n) good[i] = good[i+1] + s[i];
    vi a(n), b(n);
    int x = 0, y = 0;
    loop(i,0,n){ 
        if (s[i]){
            int lft = n-i-1;
            int g = good[i+1], bb = lft - g;
            int xx = max(x,y), yy = min(x,y);
            int amt = min(bb, (xx-yy)/2);
            bb-=amt;
            xx-=amt, yy+=amt;
            if (xx==yy && bb%2==1) xx++, yy--, bb = 0;
            if (g >= xx+1){
                a[i] = b[i] = 1;
                x++, y++;
            }
            else{
                a[i] = b[i] = 0;
                x--, y--;
            }
        }
        else{
            if (x > y){
                a[i] = 0;
                b[i] = 1;
                x--, y++;
            }
            else{
                a[i] = 1, b[i] = 0;
                x++, y--;
            }
        }
        if (x<0 || y<0) return cout<<"NO"<<endl,0;
    }
    if (x!=0 || y!=0) return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    for(int v:a) cout<<(v?"(":")"); cout<<endl;
    for(int v:b) cout<<(v?"(":")"); cout<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ a.cpp -D_GLIBCXX_DEBUG -o a & a
3
6
101101
10
1001101101
4
1100


*/