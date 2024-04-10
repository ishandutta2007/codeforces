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
const int mn=4e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;


string s[mn];
int a,b;
bool tst(int r,int c){
    for(int i=max(0,r-1);i<=min(a-1,r+1);i++)
        for(int j=max(0,c-1);j<=min(b-1,c+1);j++)
            if(s[i][j]=='1')return 0;
    return 1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        
        cin>>a>>b;
        for(int i=0;i<a;i++)s[i].assign(b,'0');
        for(int i=0;i<b;i++){
            if(tst(0,i))s[0][i]='1';
        }
        for(int i=0;i<a;i++){
            if(tst(i,b-1))s[i][b-1]='1';
        }
        for(int i=b-1;i>=0;i--){
            if(tst(a-1,i))s[a-1][i]='1';
        }
        for(int i=a-1;i>=0;i--){
            if(tst(i,0))s[i][0]='1';
        }
        for(int i=0;i<a;i++)printf("%s\n",s[i].c_str());
        printf("\n");
    }
}