#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;

ll po[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int tc;
    cin>>tc;
    po[0]=1;
    for(int i=1;i<=18;i++)po[i]=po[i-1]*10;
    while(tc--){
        int n,k;
        cin>>n>>k;
        ll ans=inf;
        for(int i=0;i<=9;i++){
            if(i+k<=9){
                int r=n;
                for(int j=i;j<=i+k;j++)r-=j;
                if(r<0)continue;
                if(r%(k+1))continue;
                r/=k+1;
                string pro;
                while(r){
                    if(r<9)pro+='0'+r,r=0;
                    else pro+='9',r-=9;
                }
                reverse(pro.begin(),pro.end());
                pro+='0'+i;
                cerr<<pro<<endl;
                ans=min(ans,stoll(pro.c_str()));
            }
            else{
                int r=n;
                for(int j=i;j<=i+k;j++)r-=j%10+j/10;
                int a=10-i,b=k+1-a;
                for(int j=0;j<=18;j++){
                    int rr=r;
                    rr-=9*j*a;
                    if(rr<0)continue;
                    if(rr%(k+1))continue;
                    rr/=k+1;
                    string pro;

                    for(int k=0;k<j;k++)pro+='9';
                    if(rr<8)pro+='0'+rr,rr=0;
                    else pro+='8',rr-=8;
                    while(rr){
                        if(rr<9)pro+='0'+rr,rr=0;
                        else pro+='9',rr-=9;
                    }
                    reverse(pro.begin(),pro.end());
                    pro+='0'+i;
                    ans=min(ans,stoll(pro.c_str()));
                }
            }
        }
        printf("%lld\n",ans==inf?-1:ans);
    }
}