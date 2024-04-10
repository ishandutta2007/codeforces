#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct atom{
    int l,r;
}x[110000];
vector<int>l[110000];
char ch[110000];
int n,m,L[110000],R[110000],pd[110000],num;
struct number{
    int x[10];
    void print(){
        for (int i=0;i<=9;i++) printf("%d ",x[i]); printf("\n");
    }
}ans[110000],now;
number operator + (number k1,number k2){
    for (int i=0;i<10;i++) k1.x[i]+=k2.x[i]; return k1;
}
number operator - (number k1,number k2){
    for (int i=0;i<10;i++) k1.x[i]-=k2.x[i]; return k1;
}
int find(int *A,int k){
    if (A[k]==k) return k;
    A[k]=find(A,A[k]); return A[k];
}
int del(int k){
    int k1=find(L,k-1),k2=find(R,k+1); L[k]=k1; R[k]=k2;
}
struct atom3{
    int where,w;
};
int operator < (atom3 k1,atom3 k2){
    return k1.w<k2.w;
};
priority_queue<atom3>A,B;
int main(){
    scanf("%d%d",&n,&m); scanf("%s",ch+1);
    for (int i=1;i<=m;i++) scanf("%d%d",&x[i].l,&x[i].r);
    for (int i=0;i<=n+1;i++) L[i]=i; for (int i=0;i<=n+1;i++) R[i]=i;
    for (int i=1;i<=m;i++) l[x[i].l].push_back(i); 
    int where=0,go=1,llim=0;
    memset(pd,0x00,sizeof pd);
    while(1){
        int k1; //cout<<where<<" "<<ch+1<<endl;
        num=max(num,where);
        if (go==1){
            k1=find(R,where+1);
            for (int i=0;i<l[k1].size();i++) 
                if (pd[l[k1][i]]==0){
                //  cout<<"ins "<<l[k1][i]<<endl;
                    ans[l[k1][i]]=ans[l[k1][i]]-now; pd[l[k1][i]]=1;
                    A.push((atom3){l[k1][i],-x[l[k1][i]].r});
                    B.push((atom3){l[k1][i],x[l[k1][i]].l});
                }
        } else if (go==-1) k1=find(L,where-1);
        while (!A.empty()&&A.top().w>-k1){
            int k2=A.top().where; A.pop();
            if (pd[k2]==1){pd[k2]=2; ans[k2]=ans[k2]+now;}
        }
        while (!B.empty()&&B.top().w>k1){
            int k2=B.top().where; B.pop();
            if (pd[k2]==1){pd[k2]=2; ans[k2]=ans[k2]+now;}
        }
        if (where!=llim){
            if (ch[where]>'9'||ch[where]<'0'){
                if (ch[k1]>'9'||ch[k1]<'0') del(where);
            } else {
                ch[where]--; if (ch[where]<'0') del(where);
            }
        }
        if (k1>n) break;
        if (k1>0){
            if (ch[k1]=='>') go=1; else if (ch[k1]=='<') go=-1; else now.x[ch[k1]-'0']++; where=k1;
        } else{
            where=num; go=1; llim=where; if (where>n) break;
        }
    }
    for (int i=1;i<=m;i++) ans[i].print(); return 0;
}