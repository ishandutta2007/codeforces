#pragma GCC optimize("Ofast")
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <fstream>
#include <numeric>
#include <tuple>
#include <ctime>
#include <random>
#include <array>
#include <cassert>
#include <complex>
#include <valarray>
#include <set>
#include <chrono>
#include <cstring>
using namespace std;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
const int LOG = 64;
ll dp[LOG][2][2];
// bit, carry, odd
void solve(){
    ll n,m;
    cin>>n>>m;
    m -= 1;
    ll res = 0,res1 = 0;
    for(int lim = LOG-1;lim>=-1;lim-=1){
        if (lim!=-1 && (m>>lim)%2==0){
            continue;
        }
        ll dl = 0;
        if (lim>=0){
            dl = 1ll<<lim;
        }
      //  cout<<"GDB "<<lim<<endl;
        for(int add = (0<=lim?0:(m>>0)%2);add<=(0<lim?1:((m xor dl)>>0)%2);add+=1){
       //     cout<<"A "<<add<<endl;
            int cbit = n%2;
            int cur = (cbit+add)%2;
            int carry = (cbit+add)/2;
            dp[0][carry][(cur+add)%2] += 1;
        }
       // cout<<"R "<<dp[0][0][0]<<endl;
        for(int bit = 1;bit<LOG;bit+=1){
            int cbit = (n>>bit)%2;
            for(int carry = 0;carry<2;carry+=1){
                for(int odd = 0;odd<2;odd+=1){
                    for(int add = (bit<=lim?0:(m>>bit)%2);add<=(bit<lim?1:((m xor dl)>>bit)%2);add+=1){
                        int cur = (cbit+carry+add)%2;
                        int nxt = (cbit+carry+add)/2;
                        dp[bit][nxt][(odd+cur+add)%2] += dp[bit-1][carry][odd];
                    }
                }
            }
        }
      //  cout<<"RB "<<dp[2][0][1]<<endl;
        res += dp[LOG-1][0][1];
        res1 += dp[LOG-1][0][0];
        //res1 += dp[LOG-1][0][0];
     //   cout<<(1ll<<lim)-dp[LOG-1][0][1]-dp[LOG-1][0][0]<<endl;
        //cout<<"G "<<dp[LOG-1][0][1]<<' '<<dp[LOG-1][0][0]<<' '<<dp[LOG-1][1][0]<<' '<<dp[LOG-1][1][1]<<endl;
        memset(dp,0,sizeof(dp));
    }
   // cout<<(m+1)-(res+res1)<<endl;
    cout<<res<<endl;//<<' '<<res1<<endl;
}
int32_t main() {
   // freopen("a.in","r",stdin);
    cin.tie(0);
    int tt=1;
    cin>>tt; 
    while (tt--){
        solve();
    }
    return 0; 
}