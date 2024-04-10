#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=201000,mod=1e9+7;
int f[maxn][10][10];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int qmod(int x){
    return x>=mod?x-mod:x;
}
void getf(){
    for(int i=0;i<=9;++i)
        f[0][i][i]=1;
    for(int i=1;i<=200000;++i){
        for(int j=0;j<9;++j)
            for(int k=0;k<=9;++k)
                f[i][k][j+1]=f[i-1][k][j];
        for(int j=0;j<=9;++j){
            f[i][j][0]=qmod(f[i][j][0]+f[i-1][j][9]);
            f[i][j][1]=qmod(f[i][j][1]+f[i-1][j][9]);
        }
    }
}
void proc(){
    string s;int n;
    cin>>s;n=read();
    int ans=0;
    for(int i=0;i<s.length();++i)
        for(int j=0;j<=9;++j)
            ans=qmod(ans+f[n][s[i]-'0'][j]);
    printf("%d\n",ans);
}
int main(){
    getf();
    int T=read();
    while(T--)proc();
	return 0;
}