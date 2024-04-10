#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=2e5+10;
struct ht{
    const static ll p=1e9+7,q=1e9+9;
    ll a,b;
    ht operator+(ht ot){return {(a+ot.a)%p,(b+ot.b)%q};}
    ht operator-(ht ot){return {(a-ot.a)%p,(b-ot.b)%q};}
    ht operator*(ht ot){return {(a*ot.a)%p,(b*ot.b)%q};}
    bool operator==(ht ot){return (a-ot.a)%p==0&&(b-ot.b)%q==0;}
    ll vesh(){return (p+a)%p*q+(b+q)%q;}
    ht(){a=b=0;}
    ht(ll x){a=b=x;}
    ht(ll x,ll y){a=x,b=y;}
};
ht m=rng()+43276583;
string s;
ht h[mn][26];
ht po[mn];
ht hsh(int i,int l,int r){
    return h[r][i]-h[l-1][i]*po[r-l+1];
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++)h[i][j]=h[i-1][j]*m;;
        h[i][s[i]-'a']=h[i][s[i]-'a']+1;
    }
    po[0]=1;
    for(int i=1;i<=n;i++)po[i]=po[i-1]*m;
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        vector<ll>aa,bb;
        for(int i=0;i<26;i++)aa.push_back(hsh(i,a,a+c-1).vesh()),bb.push_back(hsh(i,b,b+c-1).vesh());
        sort(aa.begin(),aa.end());
        sort(bb.begin(),bb.end());
        bool gud=1;
        for(int i=0;i<26;i++)if(aa[i]!=bb[i])gud=0;
        if(gud)printf("YES\n");
        else printf("NO\n");
    }
}