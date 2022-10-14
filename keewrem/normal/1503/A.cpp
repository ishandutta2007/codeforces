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


void solve(){
    int N; string s;
    cin >> N >> s;
    if(s[0] == '0' || s[N-1] == '0'){cout << "NO\n"; return;}
    string k(N,'('),kk(N,'(');
    k[N-1] = ')'; kk[N-1] = ')';
    int bb = 0;
    for(int i = 1; i < N-1; i++){
        if(s[i] == '0')bb++;
    }
    int c = 0,cc = N-2-bb;
    if(bb % 2){cout << "NO\n"; return;}
    for(int i = 1; i < N-1; i++){
        if(s[i] == '0'){
            if(bb--%2)k[i] = ')';
            else kk[i] = ')';
        }else{
            if(++c > cc/2)k[i] = kk[i] = ')';
        }
    }
    int a = 0, b = 0;
    for(int i = 0; i < N; i++){
        if(k[i] == '(')a++;
        else a--;
        if(kk[i] == '(')b++;
        else b--;
        if(a < 0 || b < 0){cout << "NO\n"; return;}
    }
    cout <<"YES\n" << k << "\n" << kk << endl;
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}