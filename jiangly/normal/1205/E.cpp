#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    static constexpr int MAX_N=1e5;
    static constexpr int MOD=1e9+7;
    int n,k;
    int pow_k[MAX_N];
    vector<int> prime_divisors[MAX_N*2];
    int dfs(int x,int y,int z,int l,int r,int coef){
        if(y==prime_divisors[x].size()){
            return coef*(r/z-(l-1)/z);
        }
        return dfs(x,y+1,z,l,r,coef)+dfs(x,y+1,z*prime_divisors[x][y],l,r,-coef);
    }
    int calc(int x,int l,int r){
        return dfs(x,0,1,l,r,1);
    }
    int Pow(int a,int b){
        int ans=1;
        while(b>0){
            if(b&1){
                ans=1ll*ans*a%MOD;
            }
            a=1ll*a*a%MOD;
            b>>=1;
        }
        return ans;
    }
public:
    void solve(){
        cin>>n>>k;
        pow_k[0]=1;
        for(int i=1;i<=n-1;++i){
            pow_k[i]=1ll*pow_k[i-1]*k%MOD;
        }
        int sum=0;
        for(int i=2;i<=n*2-2;++i){
            int x=i;
            for(int j=2;j*j<=x;++j){
                if(x%j==0){
                    prime_divisors[i].push_back(j);
                    while(x%j==0){
                        x/=j;
                    }
                }
            }
            if(x>1){
                prime_divisors[i].push_back(x);
            }
        }
        int ans=0;
        for(int gcd=1;gcd<=n-1;++gcd){
            int lim=(n-1)/gcd;
            for(int s=2;s<=lim*2;++s){
                int l=max(1,s-lim),r=min(s-1,lim);
                int cnt=calc(s,l,r);
                ans=(ans+1ll*cnt*pow_k[max(gcd,gcd*s-n)])%MOD;
            }
        }
        ans=1ll*ans*Pow(k,MOD-1-n)%MOD;
        cout<<ans<<endl;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}