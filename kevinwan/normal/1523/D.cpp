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
const int mn=2e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;
string s[mn];
int num[1<<15];
int ans[60];
int anslen;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int ttt=0;ttt<50;ttt++){
        int r=rng()%n;
        //cerr<<r<<endl;
        vi v;
        for(int i=0;i<m;i++)if(s[r][i]=='1')v.push_back(i);
        int k=v.size();
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            int msk = 0;
            for(int j=0;j<k;j++){
                if(s[i][v[j]]=='1')msk|=(1<<j);
            }
            num[msk]++;
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<1<<k;j++)if((j>>i)&1){
                num[j-(1<<i)]+=num[j];
            }
        }
        //for(int j=0;j<1<<k;j++)cerr<<num[j]<<endl;
        for(int i=0;i<1<<k;i++)if(num[i]>=(n+1)/2){
            //cerr<<__builtin_popcount(i)<<endl;
            if(__builtin_popcount(i)>anslen){
                anslen = __builtin_popcount(i);
                memset(ans,0,sizeof(ans));
                for(int j=0;j<k;j++)if((i>>j)&1)
                    ans[v[j]]=1;
            }
        }
        //cerr<<endl;
    }
    for(int i=0;i<m;i++)printf("%d",ans[i]);
}