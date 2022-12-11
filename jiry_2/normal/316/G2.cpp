#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct tree{
    int val,father,w[13],next[28];
}t[1300100];
int last,len,n,m,c[1300010],x[1300010],l[20],r[20];
char ch[100010];
void insert(int k,int k1){
    int np=++len,p=last; t[np].val=t[p].val+1; t[np].w[k1]=1; for (;p&&t[p].next[k]==0;p=t[p].father) t[p].next[k]=np;
    if (p==0){last=np; t[np].father=1; return;} int q=t[p].next[k];
    if (t[q].val-1==t[p].val){last=np; t[np].father=q; return;}
    int nq=++len; memcpy(t[nq].next,t[q].next,sizeof t[q].next); t[nq].val=t[p].val+1; t[nq].father=t[q].father; t[q].father=nq; t[np].father=nq;
    for (;p&&t[p].next[k]==q;p=t[p].father) t[p].next[k]=nq; last=np;
}
int main(){
    scanf("%s",ch+1); len=1; memset(t,0x00,sizeof t); last=1; scanf("%d",&n);
    for (int i=1;i<=strlen(ch+1);i++) insert(ch[i]-'a',0); insert(26,n+1);
    for (int i=1;i<=n;i++){scanf("%s",ch+1); for (int j=1;j<=strlen(ch+1);j++) insert(ch[j]-'a',i); insert(26,n+1); scanf("%d%d",&l[i],&r[i]);}
    for (int i=1;i<=len;i++) c[t[i].val]++;
    for (int i=1;i<=len;i++) c[i]+=c[i-1];
    for (int i=1;i<=len;i++){x[c[t[i].val]]=i; c[t[i].val]--;}
    for (int i=len;i;i--)
        for (int j=0;j<=n;j++) t[t[x[i]].father].w[j]+=t[x[i]].w[j];
    long long ans=0;
    for (int i=1;i<=len;i++)
        if (t[i].w[0]){
            int flag=0;
            for (int j=1;j<=n;j++) if (t[i].w[j]<l[j]||t[i].w[j]>r[j]){flag=1; break;}
            if (flag==0) ans+=t[i].val-t[t[i].father].val;
        }
    cout<<ans<<endl; return 0;
}