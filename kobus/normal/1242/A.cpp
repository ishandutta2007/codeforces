#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
 
#define MOD 1000000007
#define pii pair<int,int>
#define pdd pair<long double,long double>
#define ld long double
#define f first
#define s second
#define inf 2e9

#define EL printf("\n")
#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define ll long long

#define ld long double
#define eps 1e-8

#define int long long


vector<int> dp;

void fdp(int x){
    int xx=x;
    int num=2;
    while(x>1){
        //cout<<num<<endl;
        if(x%num==0){
            dp.pb(num);
            while(x%num==0)x=x/num;
            if(x!=1){
                cout<<1<<endl;
                exit(0);
            }
        }
        if(num*num>xx && x==xx){
            dp.pb(xx);
            break;
        }
        if(dp.size()>=2)break;
        num++;
    }
}


int32_t main(){
    
    int n;
    cin>>n;

    fdp(n);

    if(n==1){
        cout<<1<<endl;
    }
    else cout<<dp[0]<<endl;


}