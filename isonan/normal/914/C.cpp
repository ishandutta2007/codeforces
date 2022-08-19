#include <cstdio>
#include <cstring>

int str[1001],c[1001][1001],f[1001],k,P=1000000007;
char s[1010];
int main(){
    for(int i=2;i<=1000;i++)f[i]=f[__builtin_popcount(i)]+1;
    scanf("%s%d",s,&k);
    if(!k){
        puts("1");
        return 0;   
    }
    c[0][0]=1;
    for(int i=1;i<=1000;i++){
        c[i][0]=1;
        for(int j=1;j<=1000;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%P;
    }
    int len=strlen(s);
    int cnt=0,ans=0;
    for(int i=0;i<len;i++)
        if(s[i]=='1'){
            for(int j=cnt+(cnt==0);j<len;j++)
                if(f[j]==k-1){
                    (ans+=c[len-i-1][j-cnt])%=P;
                }
            cnt++;
        }
    if(k==1)--ans;
    if(f[cnt]==k-1)(++ans)%=P;
    printf("%d",ans);
}