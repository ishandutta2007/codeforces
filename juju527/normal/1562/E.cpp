#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n;
char s[maxn];
int lcp[maxn][maxn];
int f[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool check(int i,int j){
    if(lcp[i][j]==n-j+1)return 0;
    return s[i+lcp[i][j]]<s[j+lcp[i][j]];
}
int main(){
    int T;
    T=read();
    while(T--){
        n=read();
        scanf("%s",s+1);
        for(int i=n;i>=1;i--){
            for(int j=n;j>i;j--){
                if(s[i]==s[j])lcp[i][j]=lcp[i+1][j+1]+1;
                else lcp[i][j]=0;
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            f[i]=n-i+1;
            for(int j=1;j<i;j++){
                int val=(check(j,i)?f[j]+n-i+1-lcp[j][i]:0);
                f[i]=max(f[i],val);
            }
            res=max(res,f[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}