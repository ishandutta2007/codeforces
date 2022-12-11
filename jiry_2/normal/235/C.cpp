#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct tree{
    int val,father,w,next[26];
}t[2000100];
int last,len,n,m,pd[2100000],x[2010000],c[2010000];
char ch[1000010];
void insert(int k){
    int np=++len,p=last; t[np].val=t[p].val+1; t[np].w=1; for (;p&&t[p].next[k]==0;p=t[p].father) t[p].next[k]=np;
    if (p==0){last=np; t[np].father=1; return;} int q=t[p].next[k];
    if (t[q].val-1==t[p].val){last=np; t[np].father=q; return;}
    int nq=++len; memcpy(t[nq].next,t[q].next,sizeof t[q].next); t[nq].val=t[p].val+1; t[nq].father=t[q].father; t[q].father=nq; t[np].father=nq;
    for (;p&&t[p].next[k]==q;p=t[p].father) t[p].next[k]=nq; last=np;
}
int main(){
    scanf("%s",ch+1); len=1; last=1; n=strlen(ch+1);
    for (int i=1;i<=n;i++) insert(ch[i]-'a'); scanf("%d",&m);
    for (int i=1;i<=len;i++) c[t[i].val]++;
    for (int i=1;i<=len;i++) c[i]+=c[i-1];
    for (int i=1;i<=len;i++){
        x[c[t[i].val]]=i; c[t[i].val]--;
    }
    for (int i=len;i;i--) t[t[x[i]].father].w+=t[x[i]].w;
    //for (int i=1;i<=len;i++) cout<<t[i].val<<" "<<t[i].w<<" "<<t[i].father<<" "<<t[i].next[0]<<" "<<t[i].next[1]<<endl;
    for (;m;m--){
        scanf("%s",ch+1); int now=1,ans=0; n=strlen(ch+1); len=0;
        for (int i=1;i<=n;i++){
            while (now&&t[now].next[ch[i]-'a']==0) {now=t[now].father; len=t[now].val;}
            if (now==0){now=1; len=0;} else {now=t[now].next[ch[i]-'a']; len++;}
        }
        for (int i=1;i<=n;i++){
            while (now&&t[t[now].father].val>=n) {now=t[now].father; len=t[now].val;}
            if (len>=n&&pd[now]!=m){pd[now]=m; ans+=t[now].w;}
            while (now&&t[now].next[ch[i]-'a']==0) {now=t[now].father; len=t[now].val;}
            if (now==0){now=1; len=0;} else {now=t[now].next[ch[i]-'a']; len++;}
        }
        printf("%d\n",ans);
    }
    return 0;
}