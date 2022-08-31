#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";}
// #define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
typedef long long ll;
typedef double ld;
#define pll pair<ll,ll>
#define pii pair<int, int>
#define pb push_back
#define mp(x, y) make_pair((x), (y))
#define F first
#define S second
#define I insert
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
//#define bitset<105> B;
const int N = 105;
int n , m , k , x;
bitset<105> A[N] , B[N];
bitset<105> nw;
int main(){
    //bitset<105> nw;
    cin >> n >> m >> k;
    for(int i = 0 ;i < n; i++){
        for(int j = 0 ;j < m; j++){
            cin >> x;
            A[i][j] = x;
            B[j][i] = x;
        }   
    }
    int ans = 20 , cnt ;
    if(n > k){
        for(int i = 0;i < n ; i++){
            // ith row is unchanged
            int diff = 0;
            for(int r1 = 0 ;r1 < n ;r1++){
                cnt = (A[i]^A[r1]).count();
                //cout << cnt << endl;
                diff += min(cnt , m-cnt);
            }
            ans = min(ans , diff);
        }
        if(ans > k)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    else{
        for(int f_row = 0; f_row < (1<<n) ; f_row++){
            for(int i = 0 ;i < n; i++)
                if(f_row&(1<<i))
                    nw[i] = 1;
            int diff = 0;
            for(int r1 = 0; r1 < m ; r1++){
                cnt = (nw^B[r1]).count();
                diff += min(cnt , n-cnt);
            }
            ans = min(ans , diff);
            for(int i =0;i < n; i++)
                nw[i] = 0;
        }
        if(ans > k)
        cout << -1 << '\n';
        else
        cout << ans << '\n';
        
    }
    return 0;
}