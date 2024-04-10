#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct atom{
    int x[26];
}num[1000000],A,zero,a[1000000];
atom operator + (atom k1,atom k2){
    for (int i=0;i<26;i++) A.x[i]=k1.x[i]+k2.x[i]; return A;
}
atom operator - (atom k1,atom k2){
    for (int i=0;i<26;i++) A.x[i]=k1.x[i]-k2.x[i]; return A;
}
atom operator / (atom k1,int k2){
    for (int i=0;i<26;i++) A.x[i]=k1.x[i]/2; return A;
}
int n,m,pd[1000000];
char ch[110000];
void buildtree(int k1,int k2,int k3){
    if (k2==k3) {num[k1].x[ch[k2]-'a']++; return;}
    int mid=k2+k3>>1; buildtree(k1*2,k2,mid); buildtree(k1*2+1,mid+1,k3); 
    num[k1]=num[k1*2]+num[k1*2+1];
}
atom get(atom k1,int l,int r){
    int now=0,rem=l;
    for (;;now++) if (k1.x[now]<rem){rem-=k1.x[now]; k1.x[now]=0;} else {k1.x[now]-=rem-1; break;}
    rem=r-l+1;
    for (;now<26;now++){int k2=min(rem,k1.x[now]); rem-=k2; k1.x[now]=k2;}
    return k1;
}
atom getrev(atom k1,int l,int r){
    int now=25,rem=l;
    for (;;now--) if (k1.x[now]<rem){rem-=k1.x[now]; k1.x[now]=0;} else {k1.x[now]-=rem-1; break;}
    rem=r-l+1;
    for (;now>=0;now--){int k2=min(rem,k1.x[now]); rem-=k2; k1.x[now]=k2;}
    return k1;
}
void changeall(int k1,atom k2){
    pd[k1]=1; num[k1]=k2; a[k1]=k2;
}
void changeallrev(int k1,atom k2){
    pd[k1]=2; num[k1]=k2; a[k1]=k2;
}
void pushdown(int k1,int k2,int k3){
    if (pd[k1]==0) return;
    int mid=k2+k3>>1;
    if (pd[k1]==1){
        atom k4=get(a[k1],1,mid-k2+1); changeall(k1*2,k4); changeall(k1*2+1,a[k1]-k4);
    } else {
        atom k4=getrev(a[k1],1,mid-k2+1); changeallrev(k1*2,k4); changeallrev(k1*2+1,a[k1]-k4);
    }
    pd[k1]=0;
}
void change(int k1,int k2,int k3,int k4,int k5,atom k6,int k7){
    if (k2>k5||k3<k4) return;
    if (k2>=k4&&k3<=k5){if (k7==1) changeall(k1,get(k6,k2-k4+1,k3-k4+1)); else changeallrev(k1,getrev(k6,k2-k4+1,k3-k4+1)); return;}
    pushdown(k1,k2,k3);
    int mid=k2+k3>>1; change(k1*2,k2,mid,k4,k5,k6,k7); change(k1*2+1,mid+1,k3,k4,k5,k6,k7); num[k1]=num[k1*2]+num[k1*2+1];
}
atom find(int k1,int k2,int k3,int k4,int k5){
    if (k2>k5||k3<k4) return zero;
    if (k2>=k4&&k3<=k5) return num[k1]; pushdown(k1,k2,k3);
    int mid=k2+k3>>1; return find(k1*2,k2,mid,k4,k5)+find(k1*2+1,mid+1,k3,k4,k5);
}
void change(int k1,int k2,int k3,int k4,int k5){
    if (k2==k3){num[k1]=zero; num[k1].x[k5]=1; return;} pushdown(k1,k2,k3);
    int mid=k2+k3>>1; if (mid>=k4) change(k1*2,k2,mid,k4,k5); else change(k1*2+1,mid+1,k3,k4,k5);
    num[k1]=num[k1*2]+num[k1*2+1];
}
void print(int k1,int k2,int k3){
//  cout<<k1<<" "<<k2<<" "<<k3<<" "<<num[k1].x['r'-'a']<<endl;
    if (k2==k3){
        for (int i=0;i<26;i++) if (num[k1].x[i]) putchar('a'+i); return;
    }
    pushdown(k1,k2,k3); int mid=k2+k3>>1; print(k1*2,k2,mid); print(k1*2+1,mid+1,k3);
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m); scanf("%s",ch+1); buildtree(1,1,n); memset(pd,0x00,sizeof pd);
    for (;m;m--){
        int k1,k2; scanf("%d%d",&k1,&k2); atom k3=find(1,1,n,k1,k2); int where=-1;
        for (int i=0;i<26;i++) if (k3.x[i]%2){if (where==-1) where=i; else {where=-2; break;}}
    //  for (int i=0;i<26;i++) cout<<k3.x[i]<<" "; cout<<endl;
        if (where==-2) continue;
        if (where==-1){
            k3=k3/2; int mid=k1+k2>>1; change(1,1,n,k1,mid,k3,1); change(1,1,n,mid+1,k2,k3,2);
        } else {
            k3=k3/2; int mid=k1+k2>>1; change(1,1,n,k1,mid-1,k3,1); change(1,1,n,mid+1,k2,k3,2); change(1,1,n,mid,where);
        }
    }
    print(1,1,n); cout<<endl; return 0;
}