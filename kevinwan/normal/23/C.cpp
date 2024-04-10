#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef pair<ld,ld>pld;
const int mn=3e5+10;
const ll mod=1e9+7;
int a[mn],b[mn];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<2*n-1;i++)scanf("%d%d",a+i,b+i);
        vector<int>o(2*n-1);
        iota(o.begin(),o.end(),0);
        sort(o.begin(),o.end(),[](int x,int y){return a[x]>a[y];});
        vector<int>ans;
        ans.push_back(o[0]);
        for(int i=1;i<2*n-1;i+=2){
            if(b[o[i]]>b[o[i+1]])ans.push_back(o[i]);
            else ans.push_back(o[i+1]);
        }
        printf("YES\n");
        for(int x:ans)printf("%d ",x+1);
        printf("\n");
    }
}