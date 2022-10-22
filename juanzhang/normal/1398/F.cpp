#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
const int maxn=1e6+10;
int n,leq[maxn],req[maxn],lef[maxn],rig[maxn];
char str[maxn];
int main(){
    scanf("%d%s",&n,str+1);
    int pos[2] = {0};
    rep(i,1,n){
        if(str[i]!='?')lef[i]=pos[(str[i]-'0')^1]+1,pos[str[i]-'0']=i;
        else lef[i]=lef[i-1];
    }
    pos[0]=pos[1]=n+1,rig[n+1]=n;
    per(i,n,1){
        if(str[i]!='?')rig[i]=pos[(str[i]-'0')^1]-1,pos[str[i]-'0']=i;
        else rig[i]=rig[i+1];
    }
    rep(k,1,n){
        int st=1,ass=0;
        while(1){
            if(st+k-1>n)break;
            if(rig[st]-st+1>=k){
                st=st+k,ass++;
            }else{
                int ps=st+k;
                st=ps<=n?lef[ps]:n+1;
            }
        }
        printf("%d ",ass);
    }
    return 0;
}