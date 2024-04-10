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


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int a = 0, b = 1;
    vvii pos(2*n-1);
    loop(i,0,n) loop(j,0,n) pos[i+j].pb({i+1,j+1});
    int i = 0, j = 0;
    bool comp = 0;
    int dig = 1;
    loop(kkk,0,n*n){
        int p; cin>>p;
        if (comp){
            auto pp = pos[a][i++];
            if (p == dig){
                cout << 3 << " " << pp.x << " "<< pp.y << endl;
            }
            else{
                cout << dig << " " << pp.x << " "<< pp.y << endl;
            }
            if (i == pos[a].size()){
                a = b+1, i = 0;
                b = a+1, j = 0;
                comp = 0;
            }
        }
        else{
            if (p==dig){ // do j
                if (b == pos.size()){
                    auto pp = pos[a][i++];
                    cout << 3 << " " << pp.x << " "<< pp.y << endl;
                }
                else{
                    auto pp = pos[b][j++];
                    cout << (3-dig) << " " << pp.x << " "<< pp.y << endl;
                    if (j == pos[b].size()){
                        comp = 1, j = 0;
                    }
                }
            }
            else{ // do i
                auto pp = pos[a][i++];
                cout << dig << " " << pp.x << " "<< pp.y << endl;
                if (i == pos[a].size()){
                    a = b, i = j;
                    b = a+1, j = 0;
                    dig = 3-dig;
                }
            }
        }
    }
    return 0;
}
/*
color a
cls
g++ b.cpp -D_GLIBCXX_DEBUG -o a & a
3

*/