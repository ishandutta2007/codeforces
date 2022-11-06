// // ?.?fg?jdK>hd<8?tgs|]7^ri+a

// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define int long long

// #define all(X) (X).begin(), (X).end()
// #define reset(X) memset(X, 0, sizeof(X))
// #define mp(a, b) make_pair(a, b)
// #define pb push_back
// #define endl '\n'
// #define fi first
// #define se second

// using namespace __gnu_pbds;
// using namespace std;
// // const int mod = 1e9+7;
// // const int mod3 = 1e6 + 3;
// const int mod=998'244'353;
// //const int mod=1e9+9;

// // const int MOD = mod;

// const int INF=2e18+10;
// // const int INF = 4e8 + 10;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// #define read(n) \
// int n;      \
// cin >> n;
// #define readv(x, n)   \
// vector<int> x(n); \
// for (auto &i : x) \
//     cin >> i;

// typedef vector<int> vi;
// typedef vector<vector<int>> vvi;
// typedef pair<int, int> pii;

// template <typename T1, typename T2>
// void set_min(T1 &a, T2 b){
//     a = min(a, (T1)b);
// }
// /* template <typename T1, typename T2> */
// bool sort_by_sec(pair<int, int> a, pair<int,int> b)
// {
//     return make_pair(a.se, a.fi)<make_pair(b.se,b.fi);
// }

// template<typename T>
// vector<int> coordinate_compress(vector<T > a)
// {
//     set<T> s;
//     for(T elem:a)
//         s.insert(elem);

//     vector<T> temp;
//     for(T elem:s)
//         temp.push_back(elem);
//     map<T, int> counter;
//     for(int i=0;i<temp.size();i++)
//         counter[temp[i]] = i;
//     vector<int> to_return;
//     for(T elem:a)
//         to_return.push_back(counter[elem]);
//     return to_return;

// }

// int multiply(int a, int b, int in_mod) { return (int)(1LL*a * b % in_mod );}
// int mult_identity(int a) { return 1; }


// vector<int >multiply(const vector<int>& a, const vector<int>& b,int mod);
// vector<int> mult_identity(vector<int> a)
// {
//     return {1};
// }




// int power(int a, int b, int in_mod)
// {

//     int prod = mult_identity(a);
//     int mult = a % in_mod;
//     b%=(mod-1);
//     while (b != 0)
//     {
//         if (b % 2)
//         {
//             prod = multiply(prod, mult, in_mod);
//         }
//         mult = multiply(mult, mult, in_mod);
//         b /= 2;
//     }
//     return prod;
// }
// int mod_inv(int q, int in_mod)
// {

//     return power(q, in_mod - 2, in_mod);
// }

// // Finds the primitive root modulo p
// int generator(int p) {
//     vector<int> fact;
//     int phi = p-1, n = phi;
//     for (int i = 2; i * i <= n; ++i) {
//         if (n % i == 0) {
//             fact.push_back(i);
//             while (n % i == 0)
//                 n /= i;
//         }
//     }
//     if (n > 1)
//         fact.push_back(n);

//     for (int res = 2; res <= p; ++res) {
//         bool ok = true;
//         for (int factor : fact) {
//             if (power(res, phi / factor, p) == 1) {
//                 ok = false;
//                 break;
//             }
//         }
//         if (ok) return res;
//     }
//     return -1;
// }

// // const int root = generator(mod);
// // const int root_1 = mod_inv(root, mod);
// // const int root_pw = 1<<20;

// // const int mod = 998244353;
// const int root  = 15311432;
// const int root_pw = 1<<23;
// // const int root_1 = mod_inv(root, mod);
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


// void solve()
// {
//     int n;
//     cin>>n;
//     int dx1, dy1;
//     int dx2, dy2;
//     cin>>dx1>>dy1;
//     cin>>dx2>>dy2;


//     if(dx1 * dy2 == dy1 * dx2)
//     {
//         cout<<"NO"<<endl;
//         return;
//     }

//     int gx = abs(__gcd( dx1, dx2));

//     int a = -dx2/gx;
//     int b = dx1/gx;

//     int off1 = abs(a * dy1 + b * dy2);

//     int off2 = abs(gx);

//     // cerr<<off1<<" "<<off2<<endl;

//     if (n!= off1 * off2)
//     {
//         cout<<"NO"<<endl;
//         return;
//     }
//     else
//     {
//         vector<pair<int, int>> generator;
//         int cnt = 0;
//         bool flag = false;
//         for(int i= 0;i< off1;i++)
//         {
//             if(flag)
//                 break;
//             for(int j=0;j<off2;j++)
//             {
//                 generator.pb({j,i});
//                 cnt++;
//                 if(cnt>=n)
//                 {
//                     flag = true;
//                     break;
//                 }
//             }
//         }


//         assert((int)generator.size()==n);
//         cout<<"YES"<<endl;
//         for(auto i:generator)
//         {
//             cout<<i.fi<<" "<<i.se<<endl;
//         }
//     }


// }




// // void solve()
// // {
// //     int n;
// //     cin>>n;

// //     int x1, y1, x2,y2;
// //     cin>>x1>>y1>>x2>>y2;

// //     vector<pair<int, int>> o;
// //     int mx = 10;
// //     for(int i = -mx;i<=mx;i++)
// //     {
// //         for(int j = -mx;j<=mx;j++)
// //         {
// //             o.pb({i*x1 + j * x2, i*y1 + j* y2});
// //         }
// //     }
// //     sort(all(o));
// //     for(auto i:o)
// //     {
// //         cout<<i.fi<<" "<<i.se<<endl;
// //     }
// // }

// signed main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cerr.tie(NULL);
// #ifndef ONLINE_JUDGE
//     if (fopen("INPUT.txt", "r"))
//     {
//         freopen("INPUT.txt", "r", stdin);
//         freopen("OUTPUT.txt", "w", stdout);
//     }
// #endif
//     auto clk = clock();
//     // -------------------------------------Code starts here---------------------------------------------------------------------

//     int t = 1;
//     // cin >> t;
// //
//     for (int test = 1; test <= t; test++)
//     {
//         // cout<<"Case #"<<test<<": ";

//         solve();
//         //cout<<endl;
//     }

//     // -------------------------------------Code ends here------------------------------------------------------------------

//     clk = clock() - clk;
//     cerr << fixed << setprecision(6) << "Time: " << ((long double)clk) / CLOCKS_PER_SEC << "\n";
//     return 0;
// }


#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
const ll mod=998244353;
// ll mod=1000000007;
ll INF=1e18+5;
ll po(ll a,ll b){
    ll re=1;
    while(b)
    {
        if(b%2==1)
        {
            re=(re*a);
            re%=mod;
        }
        a=(a*a);
        a%=mod;
        b>>=1;
    }
    return re;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    int test=1;
    // cin>>test;
    spre
    while(test--)
    {
        int n;
        cin>>n;
        ll h;
        ll x[n],y[n];
        double ans=0,a,b;
        ll p,q;
        ll x1,x2,y1,y2;
        cin>>h;
        FOR(i,0,n)
        {
            cin>>x[i]>>y[i];
        }
        FOR(i,0,n)
        {
            x[i]=x[n-1]-x[i];
            y[i]=y[i]-h-y[n-1];
        }
        a=x[n-1]-x[n-2];
        b=y[n-1]-y[n-2];
        ans+=sqrt(a*a+b*b);
        q=x[n-2];
        p=y[n-2];
        FORD(i,n-2,0)
        {
            // cout<<ans<<'\n';
            if((y[i]*q)>=(p*x[i]))
            {
                x1=x[i];
                x2=x[i+1];
                y1=y[i];
                y2=y[i+1];
                if(q*(y1-y2)==p*(x1-x2))
                {
                    a=x1-x2;
                    b=y1-y2;
                }
                else
                {
                    a=(x1*(double(y1)-y2)-y1*(double(x1)-x2))/((double(y1)-y2)-p*(double(x1)-x2)/q);
                    b=p*a/q;
                    a=x[i]-a;
                    b=y[i]-b;
                }
                // cout<<a<<' '<<b<<' ';
                ans+=sqrt(a*a+b*b);
                p=y[i];
                q=x[i];
            }
        }
        cout<<ans;
    }
    return 0;
}