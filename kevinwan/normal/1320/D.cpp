#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=2e5+10;
struct ht{
    const static ll mod1=1e9+7,mod2=1e9+9;
    ll a,b;
    ht(){a=b=0;}
    ht(ll x){a=b=x;}
    ht(ll x,ll y){a=x,b=y;}
    ht operator+(ht ot){return {(a+ot.a)%mod1,(b+ot.b)%mod2};}
    ht operator-(ht ot){return {((a-ot.a)%mod1+mod1)%mod1,((b-ot.b)%mod2+mod2)%mod2};}
    ht operator*(ht ot){return {a*ot.a%mod1,b*ot.b%mod2};}
    ll hail(){;return a*mod2+b;}
};
ll mul=rand()*234+14789;
ht hsh[mn],po[mn];
int num[mn],ps[mn],lgo[mn],rgo[mn];
int main()
{
    srand(time(0));
    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    s=" "+s;
    po[0]=1;
    for(int i=1;i<=n;i++)po[i]=po[i-1]*mul,lgo[i]=rgo[i]=i;
    for(int i=1;i<=n;i++){
        ps[i]=ps[i-1]+(s[i]=='1');
        num[i]=num[i-1],hsh[i]=hsh[i-1];
        if(s[i]=='1'){
            if(s[i-1]=='1')continue;
            int j;
            for(j=i;j<=n&&s[j]=='1';j++);
            for(int k=j-2;k>=i;k-=2)lgo[k]=j;
            for(int k=j-1;k>=i;k-=2)lgo[k]=j-1;
            for(int k=i;k<j;k+=2)rgo[k]=i;
            for(int k=i+1;k<j;k+=2)rgo[k]=i-1;
            if((j-i)%2==0)continue;
        }
        num[i]=num[i-1]+1;
        hsh[i]=hsh[i-1]*mul+s[i];
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(ps[a+c-1]-ps[a-1]!=ps[b+c-1]-ps[b-1]){
            printf("No\n");
            continue;
        }
        if(ps[a+c-1]-ps[a-1]==c){
            printf("Yes\n");
            continue;
        }
        int la=lgo[a],lb=lgo[b],ra=rgo[a+c-1],rb=rgo[b+c-1];
        if(s[la]!=s[lb]||s[ra]!=s[rb]){
            printf("No\n");
            continue;
        }
        if(s[la]=='1')la++;
        if(s[lb]=='1')lb++;
        if(s[ra]=='1')ra--;
        if(s[rb]=='1')rb--;
        if((hsh[ra]-hsh[la-1]*po[num[ra]-num[la-1]]).hail()==(hsh[rb]-hsh[lb-1]*po[num[rb]-num[lb-1]]).hail()){
            printf("Yes\n");
        }
        else printf("No\n");
    }
}