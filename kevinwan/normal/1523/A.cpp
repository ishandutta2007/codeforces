#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=610;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=998244353;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        for(int i=0;i<min(n,m);i++){
            string t=s;
            for(int j=0;j<n;j++){
                int num=int(j>=0&&t[j-1]=='1')+(j<n-1&&t[j+1]=='1');
                if(num==1)s[j]|=1;
            }
            //cerr<<s<<endl;
        }
        printf("%s\n",s.c_str());
    }
}