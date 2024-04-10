#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) int((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int N;
void move(int n,int x, int y){
    cout << n << " " << x << " " << y << endl;
    cout.flush();
}
vector<pii> va,vb;
void ma(int a, int c){
    move(c,va[a].fi+1,va[a].se+1);
}void mb(int a, int c){
    move(c,vb[a].fi+1,vb[a].se+1);
}
void solve(){
    cin >> N;
    int c;
    int a = 0, b = 0, q = N*N,cs;

    FOR(i,N)FOR(j,N){
        if((i+j)%2)va.pb({i,j});
        else vb.pb({i,j});
    }
    FOR(kek,N*N){
        cin >> c;
        if(c != 1){
            if(a < q/2)ma(a++,1);
            else mb(b++,5-c);
        }else{
            if(b <= (q-1)/2){
                mb(b++,2);
            }else ma(a++,3);
        }
    }

    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}