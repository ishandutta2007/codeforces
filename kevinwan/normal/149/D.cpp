#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
struct hail{
    ll h[3][3];
};
hail bas(){
    hail a;
    memset(a.h,0,sizeof(a.h));
    a.h[0][1]=a.h[0][2]=a.h[1][0]=a.h[2][0]=1;
    return a;
}
hail compose(hail a,hail b){
    hail c;
    memset(c.h,0,sizeof(c.h));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    if(k==l&&k>0)continue;
                    c.h[i][j]+=a.h[i][k]*b.h[l][j];
                    c.h[i][j]%=mod;
                }
            }
        }
    }
    return c;
}
hail ad(hail a){
    hail b;
    memset(b.h,0,sizeof(b.h));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if((i&&j)||(i==0&&j==0))continue;
            for(int k=0;k<3;k++){
                if(i==k&&i>0)continue;
                for(int l=0;l<3;l++){
                    if(j==l&&j>0)continue;
                    //if(a.h[k][l])cout<<i<<' '<<k<<' '<<l<<' '<<j<<endl;
                    b.h[i][j]+=a.h[k][l];
                    b.h[i][j]%=mod;
                }
            }
        }
    }
    return b;
}
const int mn=1000;
int p[mn];
hail solve(int l,int r){
    if(l+1==r)return bas();
    else if(p[l]==r)return ad(solve(l+1,r-1));
    else return compose(solve(l,p[l]),solve(p[l]+1,r));
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    stack<int>t;
    for(int i=0;i<n;i++){
        if(s[i]=='(')t.push(i);
        else{
            p[t.top()]=i;
            t.pop();
        }
    }
    hail h=solve(0,n-1);
    ll ans=0;
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)ans+=h.h[i][j];
    ans%=mod;
    printf("%lld",ans);
}