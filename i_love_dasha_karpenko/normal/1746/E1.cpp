//#pragma GCC optimize("Ofast")
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
#define mod asdsad
#define div sadfasd
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
int n;
bool ask(int bit){
    vector<int> V;
    for(int i = 1;i<=n;i+=1){
        if ((i>>bit)%2==1){
            V.push_back(i);
        }
    }
    cout<<"? "<<V.size()<<' ';
    for(int to:V){
        cout<<to<<' ';
    }
    cout<<endl;
    cout.flush();
    string ret;
    cin>>ret;
    return ret=="YES";
}
bool ask(int mask,int bit){
    vector<int> V;
    for(int i = 1;i<=n;i+=1){
        if (i%(1<<(bit+1))==mask){
            V.push_back(i);
        }
    }
    cout<<"? "<<V.size()<<' ';
    for(int to:V){
        cout<<to<<' ';
    }
    cout<<endl;
    cout.flush();
    string ret;
    cin>>ret;
    return ret=="YES";
}
bool ask(int mask1,int mask2,int bit){
    vector<int> V;
    for(int i = 1;i<=n;i+=1){
        if (i%(1<<(bit+1))==mask1 || i%(1<<(bit+1))==mask2){
            V.push_back(i);
        }
    }
    cout<<"? "<<V.size()<<' ';
    for(int to:V){
        cout<<to<<' ';
    }
    cout<<endl;
    cout.flush();
    string ret;
    cin>>ret;
    return ret=="YES";
}
pair<int,int> get(int a1,int a2,int a3,int bit){
    bool ans1 = ask(a1,a3,bit);
    if (ans1==1){
        bool ans2 = ask(a2,bit);
        if (ans2==0){
            return {a1,a3};
        }
        else{
            bool ans3 = ask(a1,a2,bit);
            if (ans3==1){
                return {a1,a2};
            }
            else{
                return {a2,a3};
            }
        }
    }
    else{
        bool ans2 = ask(a1,a2,bit);
        if (ans2==1){
            return {a1,a2};
        }
        else{
            return {a2,a3};
        }
    }                    
}
void solve(){
    
    cin>>n;
    int msk[2] = {0,1};
    for(int bit = 1;(1<<bit)<=n;bit+=1){
        bool ans1 = ask(bit);
        bool ans2 = ask(msk[0],bit-1);
        vector<int> cand;
        for(int v1 = 0;v1<2;v1+=1){
            for(int v2 = 0;v2<2;v2+=1){
                if (v1==!ans1 && v2==!ans2){
                    continue;
                }
                cand.push_back(msk[1-v2] xor (v1<<bit));
            }
        }
      //  cout<<"GDB "<<cand[0]<<' '<<cand[1]<<' '<<cand[2]<<endl;
        pair<int,int> ret = get(cand[0],cand[1],cand[2],bit);
        msk[0] = ret.first;
        msk[1] = ret.second;
    }
    for(int i = 0;i<2;i+=1){
        msk[i] = max(msk[i],1);
        msk[i] = min(n,msk[i]);
    }
    cout<<"! "<<msk[0]<<endl;
    cout.flush();
    string ret;
    cin>>ret;
    if (ret==":)"){
        return;
    }
    cout<<"! "<<msk[1]<<endl;
    cout.flush();
    cin>>ret;
}
int32_t main() {
    //freopen("a.in","r",stdin);
    cin.tie(0);
    int tt=1;
    //cin>>tt; 
    while (tt--){
        solve();
    }
    return 0; 
}