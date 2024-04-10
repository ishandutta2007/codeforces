#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<ctime>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
//#define endl '\n'
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
const int N = 2e5+7;
const int MXLEN = 2000;
int ask(int len){
    cout<<"? "<<len<<endl;
    int ret;
    cin>>ret;
    return ret;
}
void solve(){
    int n;
    cin>>n;
    int l = n,r = n-1+n*MXLEN;

    while(l!=r){
        int mid = (l+r)/2;
        int val = ask(mid);
        if (val!=1){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    int len = l;
    int cur = len;
    int rlen = len-(n-1);
    int last = 1;
    for(int k = n;k>last;--k){
        int w = (cur-1)/k;
        while(w>0 && w*k-rlen>=(n-k) && ask(w)==k){
            --w;
            ++last;
        }
        ++w;

        cur = min(cur,w*k);
    }
    cout<<"! "<<cur<<endl;
}
signed main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}