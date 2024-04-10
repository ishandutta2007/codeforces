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

struct Data{
    int mat[3][3];
    //vvi mat;
    void init(){
        loop(i,0,3) loop(j,0,3) mat[i][j] = 0;
        //mat.resize(3, vi(3,0));
    }
    Data(){init();}
    Data(int c){
        init();
        //loop(i,0,3) loop(j,i,3) if(i<=c && c<=j) mat[i][j] = 1;
        mat[c][c] = 1;
    }
    Data(const Data &a, const Data &b){
        init();
        /*loop(i,0,3) mat[i][i] = a.mat[i][i] + b.mat[i][i];
        loop(i,0,2){
            mat[i][i+1] = a.mat[i][i+1] + b.mat[i+1][i+1];
        }*/
        loop(i,0,3) loop(j,i,3){
            mat[i][j] = INF;
            loop(k,i,j+1) chkmin(mat[i][j], a.mat[i][k]+b.mat[k][j]);
        }
    }
};

struct Seg{
    int sz;
    vector<Data> a;
    Seg(int n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
    }
    void update(int i, int c){
        i+=sz, a[i] = Data(c);
        for(i/=2; i; i/=2) a[i] = Data(a[2*i], a[2*i+1]);
    }
    int query(int l, int r){
        /*Data la, ra; bool ll = 0, rr = 0;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2==1){
                if (!ll) ll = 1, la = a[l++];
                else la = Data(la, a[l++]);
            }
            if (r%2==0){
                if (!rr) rr = 1, ra = a[r--];
                else ra = Data(a[r--], ra);
            }
        }
        if (!ll) return ra.mat[0][2];
        if (!rr) return la.mat[0][2];
        return Data(la, ra).mat[0][2];*/
        return a[1].mat[0][2];
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    Seg seg(n);
    string s; cin>>s; loop(i,0,n) seg.update(i, s[i]-'a');
    loop(i,0,q){
        int p; char c; cin>>p>>c; p--;
        seg.update(p, c-'a');
        cout << seg.query(0,n-1) << endl;
        /*s[p] = c;
        Data ans(s[0]-'a');
        loop(i,1,n) {
            //cout<<ans.mat<<endl;
            ans = Data(ans, Data(s[i]-'a'));
        }
        cout << ans.mat[0][2]<<endl;*/
    }
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
9 12
aaabccccc
4 a
4 b
2 b
5 a
1 b
6 b
5 c
2 a
1 a
5 a
6 b
7 b


*/