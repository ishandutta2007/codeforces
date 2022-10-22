#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+9;
const int B=89;
int n;
int la[M];
ll p[M],ans;
char s[M];
map<ll,int>mp;
int main(){
    cin>>(s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;++i)p[i]=s[i]-'0'+p[i-1];
    for(int i=1,last=0;i<=n;++i){
        if(s[i]=='1')last=i;
        la[i]=last;
    }
    for(int k=1;k<=B;++k){
        mp.clear();
        for(int i=0;i<=n;++i){
            ans+=mp[1ll*i-1ll*k*p[i]]++;
        }
    }
    for(int i=1;i<=n;++i){
        int l=la[i];
        for(int j=1;;++j){
            int R=min(i-B*j,l);
            if(R<=0)break;
            int L=la[l-1];
            if(L<=R)ans+=(i-L)/j-(i-R)/j;
            l=L;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
111111111
*/