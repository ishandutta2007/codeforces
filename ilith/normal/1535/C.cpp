#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define mid ((l+r)>>1)
using namespace std;
const int Type=2;
const int maxn=201000;
int n;
char s[maxn];
long long f[maxn][2];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int GetT(){
    if(Type==1)return 1;
    return read();
}
void proc(){
    scanf("%s",s+1);
    n=strlen(s+1);
    long long ans=0;
    for(int i=1;i<=n;++i){
        if(s[i]=='0'){
            f[i][1]=0;
            f[i][0]=f[i-1][1]+1;
            ans+=f[i][0]+f[i][1];
        }
        else if(s[i]=='1'){
            f[i][0]=0;
            f[i][1]=f[i-1][0]+1;
            ans+=f[i][0]+f[i][1];
        }
        else{
            int j=i;
            while(j<n&&s[j+1]=='?')++j;
            ans+=1ll*(j-i+1)*(j-i+2)/2;
            ans+=1ll*(f[i-1][0]+f[i-1][1])*(j-i+1);
            f[j][0]=((j-i+1)%2==0?f[i-1][0]:f[i-1][1]);
            f[j][1]=((j-i+1)%2==0?f[i-1][1]:f[i-1][0]);
            if(j<n){
                f[j][s[j+1]=='0']+=j-i+1;
            }
            i=j;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int T=GetT();
    while(T--)proc();
    return 0;
}