#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int ans2=1e9,ans3=-1e9;
long long ans1;
bool isp=true,ism=true;
int main(){
    scanf("%d",&n);
    if(n==1){
        scanf("%d",&n);
        cout<<n<<endl;
        return 0;
    }
    for(register int i=1,x;i<=n;++i){
        scanf("%d",&x);
        ans1+=abs(x);
        if(x>=0){
            ism=false;
            ans2=min(ans2,x);
        }
        if(x<=0){
            isp=false;
            ans3=max(ans3,x);
        }
    }
    if(isp)cout<<ans1-2*ans2<<endl;
    else if(ism)cout<<ans1+2*ans3<<endl;
    else cout<<ans1<<endl;
    return 0;
}