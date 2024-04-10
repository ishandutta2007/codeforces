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
using namespace std;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 357;
int A[N][N];
void solve(){
    int n;
    cin>>n;
    /*if (n==2){
        int a,b;
        cin>>a>>b;
        cout<<a<<' '<<a<<'\n'<<(1-b)<<' '<<b<<endl;
        return;
    }*/
    for(int i = 0;i<n;i+=1){
        int val;
        cin>>val;
        for(int sh = 0;sh<n;sh+=1){
            A[(sh+i)%n][i] = (val+sh*i)%n;
        }
    }
    for(int i = 0;i<n;i+=1){
            for(int j = 0;j<n;j+=1){
                cout<<A[i][j]<<' ';
            }
            cout<<endl;
        }
            
}
int32_t main() {
   // freopen("a.in","r",stdin);
    cin.tie(0);
    int tt=1;
    //cin>>tt; 
    while (tt--){
        solve();
    }
    return 0; 
}