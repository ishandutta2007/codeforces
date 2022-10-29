#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
  
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int n,a[100005],freq[100005],cnt[100005],f[100005];
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        freq[a[i]]++;
    }
    rep(i,1,100001){
        // cnt[i] = freq[i] + freq[2i] . .
        for(int j=i;j<=100000;j+=i){
            cnt[i] += freq[j];
        }
    }
    for(int g=100000;g>=1;g--){
        int total = (expo(2, cnt[g], hell) - 1 + hell) % hell; // logn
        // f[g] = total - f[2g] - f[3g] . . ;
        f[g] = total;
        for(int j=2*g;j<=100000;j+=g){
            f[g] = (f[g] - f[j] + hell) % hell;
        }
    }
    cout<<f[1]<<endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}