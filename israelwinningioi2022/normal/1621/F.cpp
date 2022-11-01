#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e18, MOD = 1e9 + 7;

template <class A, class B> pair<A,B> operator+(const pair<A,B>& a, const pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(const pair<A,B>& a, const pair<A,B>& b) {
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
    int n,a,b,c; cin>>n>>a>>b>>c;
    string s; cin>>s; for(auto &c:s) c-='0';
    int z=0, o=0;
    int comp = -1;
    vi v, sz;
    loop(i,0,n){
        if (comp!=s[i]) comp = s[i], v.pb(comp), sz.pb(1);
        else{
            sz.back()++;
            if (comp) o++;
            else z++;
        }
    }
    //cout<<"ZO "<<z<<" "<<o<<endl;
    if (z<=o){
        int ans = 0;
        if (z==o){
            ans = z*b + z*a;
            o-=z, z = 0;
        }   
        else{
            ans = (z+1)*b + z*a;
            o-=z+1, z = 0;
        }
        //cout<<"ZO: "<<z<<" "<<o<<endl;
        for(auto x:v){
            if (x) o++;
            else z++;
        }
        int amt = min(o-1, z);
        //cout<<"ANS: "<<ans<<" "<<amt<<" "<<z<<" "<<o<<endl;
        if (c<b && amt>0) ans+=(b-c)*amt;
        cout << ans << endl;
    }
    else{
        vi zsz;
        loop(i,1,v.size()-1) if(v[i]==0) zsz.pb(sz[i]);
        sort(all(zsz));
        int ans = (o+1)*a + o*b;
        int amt = o, cnt=0;
        for(auto x:zsz){
            amt-=x-1;
            if (amt>=0) cnt++;
        }
        if (c<b) ans += (b-c)*cnt;
        //chkmax(ans, (o+1)*a + o*b);
        cout << ans << endl;
    }
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
g++ f.cpp -o a & a
2
4 2 5 1
1010
6 2 5 1
101100

3
5 2 2 1
01101
6 4 3 5
110001
6 3 2 1
011110


6
1 2 2 1
1
1 2 2 1
0
2 2 2 1
11
2 2 2 1
00
3 2 2 1
101
5 2 2 1
10111


3
5 2 2 1
01101
6 4 3 5
110001
6 3 2 1
011110





1
5 2 2 1
01010



101011
10111
1011
111
11
*/