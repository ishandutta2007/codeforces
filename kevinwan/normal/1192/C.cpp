#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int cst(char c){
    if(c<='9')return c-'0';
    if(c<='Z')return c-'A'+10;
    return c-'a'+36;
}
ll t[62][62];
ll num[62][62][62];
int main()
{
    int n,i,j,k,l,w;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    string s,rs;
    vector<string>v[11];
    for(i=0;i<n;i++){
        cin>>s;
        rs=s;
        reverse(rs.begin(),rs.end());
        v[s.size()].push_back(s);
        v[s.size()].push_back(rs);
    }
    ll ans=0;
    for(w=1;w<=10;w++){
        memset(t,0,sizeof(t));
        memset(num,0,sizeof(num));
        sort(v[w].begin(),v[w].end());
        v[w].resize(distance(v[w].begin(),unique(v[w].begin(),v[w].end())));
        for(auto ss:v[w])t[cst(ss[0])][cst(ss[ss.size()-1])]++;
        for(i=0;i<62;i++){
            for(j=i;j<62;j++){
                for(k=j;k<62;k++){
                    for(l=0;l<62;l++){
                        num[i][j][k]+=t[i][l]*t[j][l]%mod*t[k][l]%mod;
                        num[i][j][k]%=mod;
                    }
                }
            }
        }

        for(i=0;i<62;i++){
            for(j=i;j<62;j++){
                for(k=j;k<62;k++){
                    for(l=k;l<62;l++){
                        ll mul;
                        int cnt=0;
                        if(i==j)++cnt;
                        if(i==k)++cnt;
                        if(i==l)++cnt;
                        if(k==j)++cnt;
                        if(l==j)++cnt;
                        if(k==l)++cnt;
                        if(cnt==0)mul=24;
                        else if(cnt==1)mul=12;
                        else if(cnt==2)mul=6;
                        else if(cnt==3)mul=4;
                        else mul=1;
                        ans+=num[i][j][k]*num[i][j][l]%mod*num[i][k][l]%mod*num[j][k][l]%mod*mul;
                        ans%=mod;
                    }
                }
            }
        }
    }
    printf("%lld",ans);
}