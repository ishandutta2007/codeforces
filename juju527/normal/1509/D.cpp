#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxN=3e5+5;
int n;
char a[maxn],b[maxn],c[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int len;
char res[maxN];
int x[maxn],y[maxn];
void solve(char *s,char *t,bool op,int z1,int z2){
    len=0;
    int z=min(z1,z2);
    int c1=0,c2=0;
    for(int i=1;i<=2*n;i++)if(s[i]==('0'^op))x[++c1]=i;
    for(int i=1;i<=2*n;i++)if(t[i]==('0'^op))y[++c2]=i;
    for(int i=1;i<=z;i++){
        for(int j=x[i-1]+1;j<x[i];j++)res[++len]=s[j];
        for(int j=y[i-1]+1;j<y[i];j++)res[++len]=t[j];
        res[++len]=(char)('0'^op);
    }
    for(int j=x[z]+1;j<=2*n;j++)res[++len]=s[j];
    for(int j=y[z]+1;j<=2*n;j++)res[++len]=t[j];
    return ;
}
int main(){
    int T;
    T=read();
    while(T--){
        n=read();
        scanf("%s",a+1);scanf("%s",b+1);scanf("%s",c+1);
        int z1=0,z2=0,z3=0;
        bool s1,s2,s3;
        for(int i=1;i<=2*n;i++){
            if(a[i]=='0')z1++;
            if(b[i]=='0')z2++;
            if(c[i]=='0')z3++;
        }
        s1=(z1<n);s2=(z2<n);s3=(z3<n);
        if(s1==s2)solve(a,b,s1,max(2*n-z1,z1),max(2*n-z2,z2));
        else if(s1==s3)solve(a,c,s1,max(2*n-z1,z1),max(2*n-z3,z3));
        else solve(b,c,s2,max(2*n-z2,z2),max(2*n-z3,z3));
        for(int i=1;i<=len;i++)printf("%c",res[i]);
        puts("");
    }
    return 0;
}