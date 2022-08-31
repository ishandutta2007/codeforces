#include<bits/stdc++.h>
using namespace std;
using LL=long long;
class Solver{
private:
    static constexpr int MAX_N=1e6+5;
    int n,k;
    bool isprime[MAX_N];
    vector<int> prime;
    int phi[MAX_N];
public:
    void solve(){
        memset(isprime,true,sizeof(isprime));
        LL ans=0;
        cin>>n>>k;
        phi[1]=1;
        for(int i=2;i<=n;++i){
            if(isprime[i]){
                prime.push_back(i);
                phi[i]=i-1;
            }
            for(int p:prime){
                if(p*i>n){
                    break;
                }
                isprime[i*p]=false;
                if(i%p==0){
                    phi[p*i]=phi[i]*p;
                    break;
                }else{
                    phi[p*i]=phi[i]*(p-1);
                }
            }
        }
        sort(phi+1,phi+n+1);
        for(int i=1;i<=k+2;++i){
            ans+=phi[i];
        }
        cout<<ans-(k==1)<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}