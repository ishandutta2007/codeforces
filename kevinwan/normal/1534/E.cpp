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
const int mn=500+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;
bool rev;
bool o[mn];
int n,k;
int query(vector<int>&v){
    printf("?");
    memset(o,0,sizeof(o));
    for(int x:v)o[x]=1;
    for(int i=1;i<=n;i++)if(o[i]^rev)printf(" %d",i);
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
void report(int x){
    printf("! %d\n",x);
    fflush(stdout);
    exit(0);
}

int main(){
    scanf("%d%d",&n,&k);
    if(n%2==1&&k%2==0){
        printf("-1\n");
        return 0;
    }
    int ans=0;
    if(n%2==0&&k%2==1&&n<2*k)rev=1,k=n-k;
    //cerr<<rev;
    if(n%k==0){
        for(int i=0;i<n/k;i++){
            vi v;
            for(int j=0;j<k;j++)v.push_back(i*k+j+1);
            ans^=query(v);
        }
        report(ans);
    }
    if(n<2*k){
        //cerr<<"sm";
        vi v;
        for(int i=1;i<=k;i++)v.push_back(i);
        ans^=query(v);
        v.clear();
        for(int i=1;i<=k;i++)v.push_back(i+(n-k)/2);
        ans^=query(v);
        v.clear();
        for(int i=(n-k)/2+1;i<=k;i++)v.push_back(i);
        for(int i=k+(n-k)/2+1;i<=n;i++)v.push_back(i);
        ans^=query(v);
        report(ans);
    }
    int num=(n+k-1)/k;
    if(k*num%2!=n%2)num++;
    int nrem=(k*num-n)/2;
    vi v;
    for(int i=1;i<=k-nrem;i++){
        v.push_back(i);
    }
    for(int i=(k-nrem)*2+1;i<=(k-nrem)*2+nrem;i++)v.push_back(i);
    ans^=query(v);
    v.clear();
    for(int i=k-nrem+1;i<=(k-nrem)*2;i++){
        v.push_back(i);
    }
    for(int i=(k-nrem)*2+1;i<=(k-nrem)*2+nrem;i++)v.push_back(i);
    ans^=query(v);
    v.clear();
    for(int i=0;i<num-2;i++){
        for(int j=(k-nrem)*2+i*k+1;j<=(k-nrem)*2+i*k+k;j++)v.push_back(j);
        ans^=query(v);
        v.clear();
    }
    report(ans);
}