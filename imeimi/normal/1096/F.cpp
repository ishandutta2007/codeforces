#include <cstdio>
int fen[200001];
void update(int i) {while(i<=200000)++fen[i],i+=i&-i;}
int query(int i){
int ret=0;
while(i){
ret+=fen[i];
i-=i&-i;
}
return ret;
}
const int mod = 998244353;
long long pw(long long x, long long p){
long long r=1;
while(p){
if(p&1) r=r*x%mod;
x=x*x%mod;
p>>=1;
}
return r;
}
int n;
int a[200001];
int l[200001];
int s[200001];
int main(){
scanf("%d", &n);
for (int i = 1; i <= n; ++i){
++s[i];
scanf("%d", &a[i]);
l[i]=l[i-1]+(a[i]==-1);
if(a[i]!=-1)--s[a[i]];
}
for(int i=1;i<=n;++i) s[i]+=s[i-1];
long long ans = 0;
long long inv = pw(l[n],mod-2);
for(int i=1;i<=n;++i){
if(a[i]==-1)continue;
update(a[i]);
ans += query(200000) - query(a[i]);
ans += l[i]*inv%mod*(s[n]-s[a[i]]);
ans += (l[n]-l[i])*inv%mod*s[a[i]];
ans%=mod;
}
ans += l[n]*(l[n]-1ll)%mod*pw(4,mod-2);
printf("%lld", ans%mod);
}