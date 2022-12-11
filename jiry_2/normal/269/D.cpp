#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
struct atom{
    int h,l,r;
    void scan(){
        scanf("%d%d%d",&h,&l,&r);
    }
}x[101000];
set<int>go[110000];
struct atom2{
    int w,k1,k2;
}y[201000];
struct atom3{
    int where,h;
};
int operator < (atom3 k1,atom3 k2){
    return k1.h<k2.h;
}
set<atom3>S;
int compare(atom2 k1,atom2 k2){
    return (k1.w<k2.w)||(k1.w==k2.w&&k1.k2<k2.k2);
}
int pd[110000],n,len,f[110000],t,A[110000];
int compare2(int k1,int k2){
    return x[k1].h<x[k2].h;
}
int main(){
    scanf("%d%d",&n,&t); for (int i=1;i<=n;i++) x[i].scan();
    for (int i=1;i<=n;i++){
        y[++len]=(atom2){x[i].l,i,1}; y[++len]=(atom2){x[i].r,i,-1};
    }
    sort(y+1,y+len+1,compare);
    for (int i=1;i<=len;i++){
        atom3 k=(atom3){y[i].k1,x[y[i].k1].h};
        if (y[i].k2==-1) S.erase(k); else {
            set<atom3>::iterator k1=S.lower_bound(k),k2=k1; 
            int flag=1;
            if (k2==S.end()) flag=0; else go[(*k2).where].insert(y[i].k1);
            if (k1!=S.begin()) {k1--; go[y[i].k1].insert((*k1).where);} else flag=0;
            if (flag) go[(*k2).where].erase((*k1).where);
            S.insert(k);
        }
    } 
    memset(pd,0x00,sizeof pd);
    for (int i=1;i<=n;i++)
        for (set<int>::iterator j=go[i].begin();j!=go[i].end();j++) pd[*j]=1; 
    int ans=-1; 
    for (int i=1;i<=n;i++) A[i]=i; sort(A+1,A+n+1,compare2); 
    for (int k1=1;k1<=n;k1++){
        int k=A[k1]; 
        if (go[k].size()==0){f[k]=x[k].r-x[k].l; continue;}
        for (set<int>::iterator i=go[k].begin();i!=go[k].end();i++){
            int j=(*i); f[k]=max(f[k],min(f[j],min(x[k].r,x[j].r)-max(x[k].l,x[j].l)));
        }
    }
    for (int i=1;i<=n;i++) if (pd[i]==0) ans=max(ans,f[i]);
    cout<<ans<<endl; return 0;
}