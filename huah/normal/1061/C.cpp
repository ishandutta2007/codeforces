#include<bits/stdc++.h>
#define LiangJiaJun main
#define ll long long
#define MOD 1000000007
using namespace std;
vector<int>v[100004];
int n,f[1000004];
int w33ha(){
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[i].clear();
        for(int j=1;j<=sqrt(x);j++){
            if(x%j==0){
                v[i].push_back(j);
                if(x!=j*j)v[i].push_back(x/j);
            }
        }
        sort(v[i].begin(),v[i].end());
    }
    ll ans=0;
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=v[i].size()-1;j>=0;j--){
            f[v[i][j]]=(f[v[i][j]]+f[v[i][j]-1])%MOD;
            ans=(ans+f[v[i][j]-1])%MOD;
        }
    }
    printf("%d\n",ans);
    return 0;
}
int LiangJiaJun(){
    while(scanf("%d",&n)!=EOF)w33ha();
    return 0;
}