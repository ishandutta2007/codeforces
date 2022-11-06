//#define ASC
//#define DBG_LOCAL

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")


#define int long long

#define all(X) (X).begin(), (X).end()

#define pb push_back
#define endl '\n'
#define fi first
#define se second

// const int mod = 1e9 + 7;
const int mod=998'244'353;


const long long INF = 2e18 + 10;
// const int INF=1e9+10;

#define readv(x, n)   \
    vector<int> x(n); \
    for (auto &i : x) \
        cin >> i;



template <typename T>
    using v = vector<T>;

template <typename T>
    using vv = vector<vector<T>>;

template <typename T>
    using vvv = vector<vector<vector<T>>>;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef vector<vector<double>> vvd;

typedef pair<int, int> pii;



int multiply(int a, int b, int in_mod) { return (int)(1LL * a * b % in_mod); }
int mult_identity(int a) { return 1; }



const double PI = acosl(-1);


auto power(auto a, auto b, const int in_mod)
{

    auto prod = mult_identity(a);
    auto mult = a % 2;
    while (b != 0)
    {
        if (b % 2)
        {
            prod = multiply(prod, mult, in_mod);
        }
        if(b/2)
        mult = multiply(mult, mult, in_mod);
        b /= 2;
    }
    return prod;
}
auto mod_inv(auto q, const int in_mod)
{
    return power(q, in_mod - 2, in_mod);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define stp cout << fixed << setprecision(20);

#define double long double
double ncr(int n, int r)
{
    if( r >n)
        return 0;

    if( r== n)
        return 1;


    if( n< 0)
        return 0;


    double ans = 1;

    for(int i = n ;i>= (n-r + 1);i--)
        ans *= i;

    for(int i = 1;i<=r;i++)
        ans /= i;

    return ans;

}
void solv()
{

    int n;
    cin>>n;

    double p;
    cin>>p;


    for(int k = 0;k<=n;k++)
    {
        double prob = ncr(k,3) / ncr(n,3) + ncr(k,2)*ncr(n-k,1) / ncr(n,3) + ncr(k,1) * ncr(n-k,2) / ncr(n,3) * 1 / 2.0;

        if( prob >=p)
        {
            cout<<k<<endl;
            return;
        }
    }
    
    assert(false);
  


}


void solve()
{

    int t = 1;
    // cin>>t;
    for(int i = 1;i<=t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solv();
    }

}




signed main()
{



    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cerr.tie(NULL);

#ifdef ONLINE_JUDGE
    #ifdef ASC

    namespace fs = std::filesystem;
    std::string path = "./";
    string filename;
    for (const auto & entry : fs::directory_iterator(path)){
        if( entry.path().extension().string() == ".in"){
            filename = entry.path().filename().stem().string();
        }
    }
    if(filename != ""){
        string input_file = filename +".in";
        string output_file = filename +".out";
        if (fopen(input_file.c_str(), "r"))
        {
            freopen(input_file.c_str(), "r", stdin);
            freopen(output_file.c_str(), "w", stdout);
        }
    }
    #endif
#endif
    auto clk = clock();
    // -------------------------------------Code starts here---------------------------------------------------------------------

    signed t = 1;
    // cin >> t;

    for (signed test = 1; test <= t; test++)
    {
        // cout<<"Case #"<<test<<": ";
        // cout<<endl;

        solve();
    }

    // -------------------------------------Code ends here------------------------------------------------------------------

    clk = clock() - clk;

    #ifndef ONLINE_JUDGE
    cerr << fixed << setprecision(6) << "\nTime: " << ((float)clk) / CLOCKS_PER_SEC << "\n";
    #endif
    return 0;
}