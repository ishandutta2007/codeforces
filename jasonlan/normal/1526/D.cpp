#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
using namespace std;
const int maxn=210000;
int n;
char s[maxn];
int head[maxn],nxt[maxn];
int a[maxn];
long long ans;
int ord[10],oans[10];
int tr[maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
void add(int p,int x){
    while(p<=n)tr[p]+=x,p+=p&-p;
}
int query(int p){
    int res=0;
    while(p)res+=tr[p],p-=p&-p;
    return res;
}
void Proc(){
    long long pres=0;
    int cnt=0;
    for(int i=0;i<4;++i)
        for(int j=head[ord[i]];j;j=nxt[j])
            a[j]=++cnt;
    for(int i=1;i<=n;++i)
        tr[i]=0;
    for(int i=n;i;--i){
        pres+=query(a[i]);add(a[i],1);
    }
    if(pres>ans){
        ans=pres;
        for(int i=0;i<4;++i)
            oans[i]=ord[i];
    }
}
void proc(){
    scanf("%s",s+1);
    n=strlen(s+1);
    sort(ord,ord+4);
    for(int i=0;i<4;++i)
        head[ord[i]]=0;
    for(int i=n;i;--i){
        nxt[i]=head[s[i]];
        head[s[i]]=i;
    }
    ans=-10;
    do{
        Proc();
    }while(next_permutation(ord,ord+4));
    for(int i=0;i<4;++i){
        for(int j=head[oans[i]];j;j=nxt[j])
            putchar(s[j]);
    }
    puts("");
}
int main(){
    ord[0]='A';ord[1]='N';ord[2]='O';ord[3]='T';
    int T=read();
    while(T--)proc();
    return 0;
}