#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
char str[50005],tt[50005];
int Cnt,cur;
struct node{int ch[26],l,pre;}t[1100005];int ndtot=1,last;
int sz[1100005][10]={0};
int up[10],lo[10];
int lon[1100005]={0},sho[1100005]={0};
int cn[1100005]={0},seq[1100005];
int add(int c,int bo=1){
    int p=last;
    if(!t[p].ch[c]){
        int np=++ndtot;sz[np][cur]+=bo;
        cn[t[np].l=t[p].l+1]++;
        for(;p && !t[p].ch[c];p=t[p].pre)t[p].ch[c]=np;
        if(!p)t[np].pre=1;
        else{
            int q=t[p].ch[c];
            if(t[q].l==t[p].l+1)t[np].pre=q;
            else{
                int nq=++ndtot;t[nq]=t[q];
                cn[t[nq].l=t[p].l+1]++;
                t[np].pre=t[q].pre=nq;
                for(;p && t[p].ch[c]==q;p=t[p].pre)t[p].ch[c]=nq;
            }
        }
        return np;
    }else{
        int q=t[p].ch[c];
        if(t[q].l==t[p].l+1){
            sz[q][cur]+=bo;
            return q;
        }else{
            int nq=++ndtot;sz[nq][cur]+=bo;
            t[nq]=t[q];cn[t[nq].l=t[p].l+1]++;
            t[q].pre=nq;
            for (;p && t[p].ch[c]==q;p=t[p].pre)t[p].ch[c]=nq;
            return nq;
        }
    }
}
int n;int lef[50005],rig[50005];
int s[50005],cnt[50005],tmp1[50005],tmp2[50005],sa[50005],*rk,m=27,h[50005];
void doub(){
    int len,num,i,j,*x=tmp1,*y=tmp2;
    for (i=0;i<m;i++)cnt[i]=0;
    for (i=0;i<n;i++)cnt[s[i]]++;
    for (i=1;i<m;i++)cnt[i]+=cnt[i-1];
    for (i=n-1;i>=0;i--)sa[--cnt[s[i]]]=i;
    for (num=i=1,x[sa[0]]=0;i<n;i++)x[sa[i]]=s[sa[i]]==s[sa[i-1]]?num-1:num++;
    for (len=1;num<n;len<<=1){
        for (j=0;j<len;j++)y[j]=n-j-1;
        for (i=0;i<n;i++)if(sa[i]>=len)y[j++]=sa[i]-len;
        for (i=0;i<num;i++)cnt[i]=0;
        for (i=0;i<n;i++)cnt[x[i]]++;
        for (i=1;i<num;i++)cnt[i]+=cnt[i-1];
        for (i=n-1;i>=0;i--)sa[--cnt[x[y[i]]]]=y[i];
        swap(x,y);
        for (num=i=1,x[sa[0]]=0;i<n;i++)x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+len]==y[sa[i-1]+len]?num-1:num++;
    }
    rk=x;
}
void ch(){
    int i,l=0;
    for (i=0;i<n-1;h[rk[i++]]=l){
        for (l?l--:0;s[i+l]==s[sa[rk[i]-1]+l];l++);
    }
}
int main()
{
    scanf("%s",str);
    last=1;
    for(int i=0;str[i];i++)last=add(str[i]-'a',0);
    scanf("%d",&Cnt);
    for (cur=0;cur<Cnt;cur++){
        scanf("%s",tt);
        last=1;
        for (int i=0;tt[i];i++)last=add(tt[i]-'a');
        scanf("%d%d",&lo[cur],&up[cur]);
    }
    cn[0]=1;for (int i=1;cn[i];i++)cn[i]+=cn[i-1];
    for (int i=1;i<=ndtot;i++)seq[cn[t[i].l]--]=i;
    for (int j=ndtot;j>=2;j--){
        int i=seq[j],pr=t[i].pre;
        for (int m=0;m<Cnt;m++)sz[pr][m]+=sz[i][m];
    }
    for (int i=1;i<=ndtot;i++){
        for(int m=0;m<Cnt;m++){
            if(sz[i][m]<lo[m])lon[i]=1;
            if(sz[i][m]>up[m])sho[i]=1;
        }
    }
    int p=1,le=0;
    for (int i=0;str[i];i++){
        int c=str[i]-'a';
        while(p!=1 && !t[p].ch[c])p=t[p].pre,le=t[p].l;
        if(t[p].ch[c])p=t[p].ch[c],le++;
        while(p!=1 && lon[p])p=t[p].pre,le=t[p].l;
        lef[i]=i-le+1;
    }
    p=1,le=0;
    for (int i=0;str[i];i++){
        int c=str[i]-'a';
        while(p!=1 && !t[p].ch[c])p=t[p].pre,le=t[p].l;
        if(t[p].ch[c])p=t[p].ch[c],le++;
        while(p!=1 && !sho[p])p=t[p].pre,le=t[p].l;
        rig[i]=i-le;
    }
    n=strlen(str);
    for (int i=0;i<n;i++)s[n-i-1]=str[i]-'a'+1;s[n++]=0;
    doub();
    ch();
    for (int i=0;i<n-1;i++)rig[i]=min(rig[i],i-h[rk[n-i-2]]);
    long long ans=0;
    for (int i=0;i<n-1;i++){
        if(lef[i]<=rig[i])ans+=rig[i]-lef[i]+1;
    }
    cout<<ans<<endl;
    return 0;
}