#include<bits/stdc++.h>
typedef long long ll;
const ll mod = 1e9+7;
ll len,cnt=1;
char x[100005];

int main()
{
    scanf("%s",&x);
    len = strlen(x);
    for(ll i=0;i<len;i++) {
        if('0'<=x[i] && x[i]<='9') x[i]-='0';
        else if('A'<=x[i] && x[i]<='Z') x[i]-='A'-10;
        else if('a'<=x[i] && x[i]<='z') x[i]-='a'-36;
        else if(x[i]=='-') x[i] = 62;
        else x[i] = 63;
        for(ll j=0;j<6;j++) {
            if(x[i]%2==0) cnt=(cnt*3)%mod;
            x[i] /= 2;
        }
    }
    printf("%lld",cnt);
}