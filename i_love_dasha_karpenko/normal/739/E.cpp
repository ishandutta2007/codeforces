#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e3+7;
const ld eps = 1e-7;
ld A[N][2];
pair<ld,pair<int,int> > dp[2];
int n,a,b;

pair<ld,pair<int,int> > F(ld lambda1,ld lambda2){
    int t = 0;
    dp[t] = {0,{0,0} };
    for(int pos = 1;pos<=n;++pos){
        dp[t^1] = dp[t];

        dp[t^1] = max(dp[t^1],{dp[t].first+A[pos][1]-lambda2,{dp[t].second.first,dp[t].second.second+1}});

        dp[t ^ 1] = max(dp[t ^ 1], {dp[t].first + A[pos][0]-lambda1, {dp[t].second.first+1,dp[t].second.second}});
        dp[t ^ 1] = max(dp[t ^ 1],{dp[t].first + A[pos][0] + A[pos][1] - A[pos][0] * A[pos][1] - lambda1 - lambda2,{dp[t].second.first+1,dp[t].second.second+1}});


        t^=1;
    }
    return dp[t];
}
int main() {

    cin>>n>>a>>b;
    for(int c = 0;c<2;++c)
    for(int i = 1;i<=n;++i){
        cin>>A[i][c];
    }
    ld cl1 = 0,cr1 = 1;
    for(int step1 = 0;step1<50;++step1){
        ld mid1 = (cl1+cr1)/2;
        ld cl2 = 0,cr2 = 1;
        for(int step2 = 0;step2<50;++step2){
            ld mid2 = (cl2+cr2)/2;
            if (F(mid1,mid2).second.second>b)
                cl2 = mid2;
            else cr2 = mid2;
        }
        if (F(mid1,cr2).second.first>a)
            cl1 = mid1;
        else cr1 = mid1;
    }
    ld cl2 = 0,cr2 = 1;
    for(int step2 = 0;step2<50;++step2){
        ld mid2 = (cl2+cr2)/2;
        if (F(cr1,mid2).second.second>b)
            cl2 = mid2;
        else cr2 = mid2;
    }
    pair<ld,pair<int,int> > ans = F(cr1,cr2);
    //assert(ans.second==b);

    cout<<fixed<<setprecision(10)<<ans.first+cr1*a+cr2*b<<endl;
    return 0;
}