#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 10010;
const int mod = 1000000007;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here -------------------------------------

map<int,int> Or[maxn], And[maxn];

int qor(int i,int j){
    cout << "or " << i << ' ' << j << '\n';
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

int qand(int i,int j){
    cout << "and " << i << ' ' << j << '\n';
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

void qres(int res){
    cout << "finish " << res << '\n';
    cout.flush();
    exit(0);
}

bool compare(int a,int b,int c){
    int orand = ( And[a][c] | And[b][c] );
    int norand = ((1<<30)-1) - orand;
    return And[a][c] + ( Or[a][c] & norand ) < And[b][c] + ( Or[b][c] & norand );
}

int find_value(int a,int b,int c){
    int nor = ((1<<30)-1) - Or[b][c];
    return ( ( And[a][b] | And[a][c] ) | ( ( Or[a][c] | Or[b][c] ) & nor ) );
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, k;
    cin >> n >> k;

    vector<int> a;
    for(int i=2; i<=n; i++){
        a.push_back(i);
        Or[1][i] = Or[i][1] = qor(1,i);
        And[1][i] = And[i][1] = qand(1,i);
    }

    sort(a.begin(),a.end(),[&](int i,int j){
        int orand = ( And[i][1] | And[j][1] );
        int norand = ((1<<30)-1) - orand;
        return And[i][1] + ( Or[i][1] & norand ) < And[j][1] + ( Or[j][1] & norand );
    });

    vector<int> arr;
    arr = { 1 , a[k-2-(k==n)+(k==1)] , a[k-1-(k==n)+(k==1)] };

    Or[arr[1]][arr[2]] = Or[arr[2]][arr[1]] = qor(arr[1],arr[2]);
    And[arr[1]][arr[2]] = And[arr[2]][arr[1]] = qand(arr[1],arr[2]);

    if( compare(arr[0],arr[1],arr[2]) ){
        if( k == 1 ){ qres(find_value(arr[0],arr[1],arr[2])); }
        if( k < n ){ qres(find_value(arr[1],arr[0],arr[2])); }
            else{ qres(find_value(arr[2],arr[0],arr[1])); }
    }
    if( k == 1 ){
        qres(find_value(arr[1],arr[0],arr[2]));
    }

    if( compare(arr[0],arr[2],arr[1]) ){
        if( k < n ) qres(find_value(arr[0],arr[1],arr[2]));
            else qres(find_value(arr[2],arr[0],arr[1]));
    }
    else{
        if( k < n ) qres(find_value(arr[2],arr[0],arr[1]));
            else qres(find_value(arr[0],arr[1],arr[2]));
    }

    return 0;
}