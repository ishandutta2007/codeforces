//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define endl '\n'
const int N = 5007;
int n,k;
int cnt = 1000,F = 1;
int ask(int pos){
    if (!cnt && F)
        while(1);
    assert(cnt);
    pos%=n;
    cout<<"? "<<pos+1<<endl;
    --cnt;
    ll ret;
    cin>>ret;
    return ret;
}
void solve(int n){
    for(int i = 1;i<=n/2;++i){
        ask(0);
    }
    vector<int> V;
    pair<int,int> mx = {0,0};
    for(int i = 0;i<n;++i){
        V.push_back(ask(i));
    }
    for(int i = 0;i<n;++i){
        if (V[(i+n-1)%n]<=V[i] && V[i]<=V[(i+1)%n] && V[i]==k){
            cout<<"! "<<i+1<<endl;
            exit(0);
        }
    }
    assert(0);
}
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>k;
    if (n<500)
       solve(n);
    int sq = sqrt(n)+1;
    for(int i = 1;i<=sq;++i)
        ask(0);
    int pos = -1,val = 0;
    for(int i = 0;i<n;i+=sq){
        val = ask(i);
        if (val!=k){
            pos = i;
            break;
        }
    }
    F = 1;
    //assert(pos!=-1);
    int flag = 0,turn = -1;
    while(val!=k){
        if (!flag){
            if (val<k){
                pos = (pos+15)%n;

                if (turn==1){
                    flag = 1;
                }
                turn = 0;
                val = ask(pos);
            }
            else{
                pos = (pos+n-15)%n;
                if (turn==0){
                    flag = 1;
                }
                turn = 1;
                val = ask(pos);

            }
        }
        else{
            if (val<k){
                pos = (pos+1)%n;
                val = ask(pos);
            }
            else{
                pos = (pos+n-1)%n;
                val = ask(pos);
            }
        }
    }
    //assert(val==k);
    cout<<"! "<<pos+1<<endl;

    return 0;
}