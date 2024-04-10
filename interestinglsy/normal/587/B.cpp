#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 233;
void add(LL &x,LL y) {x+=y;x%=MOD;}
pii a[MAXN];
int b[MAXN];
LL dp[MAXN];

int main(){
    int n,k;
	LL l;
    scanf("%d%I64d%d",&n,&l,&k);
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    int m=n*k;
    for(int i=0;i<m;i++){
        a[i].first=b[i%n];
        a[i].second=i;
		dp[i]=0;
    }
    sort(a,a+m);
    
	LL ans=l%MOD;
    int yu=l%n;
    for(int i=0;i<m;i++){
        int id=a[i].second;
        if(id<n)add(dp[id/n],1);
        else add(dp[id/n],dp[id/n-1]);
        if(id<l   &&   id>=n){
            LL cnt=(l-1)/n-id/n+1;
            if(yu&&(id%n)>yu-1)cnt--;
            add(ans,cnt%MOD*dp[id/n-1]%MOD);
        }
    }
    printf("%I64d\n",ans);
    return 0;
}