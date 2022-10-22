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

int main(){
    int tcc;
    scanf("%d",&tcc);
    while(tcc--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)cin>>s[i];
        int col=-1;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            if(s[i][j]!='.'){
                int c = ((s[i][j]=='R')^i^j)&1;
                if(col!=-1&&col!=c)col=-2;
                else col = c;
            }
        }
        if(col==-2)printf("NO\n");
        else{
            printf("YES\n");
            if(col==-1)col=0;
            for(int i=0;i<n;i++)for(int j=0;j<m;j++){
                s[i][j]=(col^i^j)&1?'R':'W';
            }
            for(int i=0;i<n;i++)printf("%s\n",s[i].c_str());
        }
        
    }
}