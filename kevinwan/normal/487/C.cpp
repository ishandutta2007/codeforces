#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
ll p[mn];
int mod;
bool isp(int n){
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    if(n==1)printf("YES\n1");
    else if(n==2)printf("YES\n1\n2");
    else if(n==4)printf("YES\n1\n3\n2\n4");
    else if(isp(n)){
            int i;
        printf("YES\n");
        p[0]=1;
        mod=n;
        vector<int>fact;
        for(i=2;i<n-1;i++){
            if((n-1)%i==0)fact.push_back(i);
        }
        int prim=-1;
        for(i=2;i<n;i++){
            bool fail=0;
            for(int x:fact){
                if(po(i,x)==1){
                    fail=1;
                }
            }
            if(!fail){
                prim=i;
                break;
            }
        }

        for(i=1;i<n;i++)p[i]=p[i-1]*prim%n;
        for(i=0;i<n-1;i++){
            if(i&1)printf("%d\n",p[i]);
            else printf("%d\n",p[n-1-i]);
        }
        printf("%d",n);
    }
    else printf("NO");
}