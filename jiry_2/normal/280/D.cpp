#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int n,m;
struct ansnum{
    int w,l,r;
};
struct atom{
    int w,where;
};
struct tree{
    ansnum ma,mi;
    atom lmi,lma,rmi,rma;
    int tot,A;
    void reverse(){
        swap(ma,mi); swap(lmi,lma); swap(rmi,rma);
        tot=-tot; ma.w=-ma.w; mi.w=-mi.w;
        lmi.w=-lmi.w; lma.w=-lma.w; 
        rmi.w=-rmi.w; rma.w=-rma.w; A^=1;
    }
    void change(int k,int where){
        tot=k; 
        if (k>=0){
            ma=(ansnum){k,where,where}; lma=(atom){k,where}; rma=(atom){k,where}; 
            mi=(ansnum){0,0,0}; lmi=(atom){0,where-1}; rmi=(atom){0,where+1};
        } else {
            mi=(ansnum){k,where,where}; lmi=(atom){k,where}; rmi=(atom){k,where}; 
            ma=(ansnum){0,0,0}; lma=(atom){0,where-1}; rma=(atom){0,where+1};
        }
    }
}t[1000000];
ansnum operator + (const atom k1,const atom k2){
    return (ansnum){k1.w+k2.w,k1.where,k2.where};
}
atom operator + (const atom k1,int k2){
    return (atom){k1.w+k2,k1.where};
}
int operator < (ansnum k1,ansnum k2){
    return k1.w<k2.w;
}
int operator > (ansnum k1,ansnum k2){
    return k1.w>k2.w;
}
int operator < (atom k1,atom k2){
    return k1.w<k2.w;
}
int operator > (atom k1,atom k2){
    return k1.w>k2.w;
}
tree operator + (const tree k1,const tree k2){
    tree k3; k3.A=0;
    k3.ma=max(k1.ma,max(k2.ma,k1.rma+k2.lma));
    k3.mi=min(k1.mi,min(k2.mi,k1.rmi+k2.lmi));
    k3.lmi=min(k1.lmi,k2.lmi+k1.tot);
    k3.rmi=min(k1.rmi+k2.tot,k2.rmi);
    k3.lma=max(k1.lma,k2.lma+k1.tot);
    k3.rma=max(k1.rma+k2.tot,k2.rma);
    k3.tot=k1.tot+k2.tot; return k3;
}
void pushdown(int k){
    if (t[k].A){
        t[k*2].reverse(); t[k*2+1].reverse(); t[k].A=0;
    }
}
void change(int k1,int k2,int k3,int k4,int k5){
    if (k2==k3){t[k1].change(k5,k4); return;}
    int mid=k2+k3>>1; pushdown(k1);
    if (mid>=k4) change(k1*2,k2,mid,k4,k5); else change(k1*2+1,mid+1,k3,k4,k5);
    t[k1]=t[k1*2]+t[k1*2+1];
}
void reverse(int k1,int k2,int k3,int k4,int k5){
//  cout<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<endl;
    if (k2>k5||k3<k4) return;
    if (k2>=k4&&k3<=k5){t[k1].reverse(); return;}
    int mid=k2+k3>>1; pushdown(k1);
    reverse(k1*2,k2,mid,k4,k5); reverse(k1*2+1,mid+1,k3,k4,k5);
    t[k1]=t[k1*2]+t[k1*2+1];
}
tree find(int k1,int k2,int k3,int k4,int k5){
    if (k2>=k4&&k3<=k5) return t[k1];
    int mid=k2+k3>>1; pushdown(k1);
    if (mid>=k5) return find(k1*2,k2,mid,k4,k5);
    if (mid<k4) return find(k1*2+1,mid+1,k3,k4,k5);
    return find(k1*2,k2,mid,k4,k5)+find(k1*2+1,mid+1,k3,k4,k5);
}
void print(int k1,int k2,int k3){
    cout<<k1<<" "<<k2<<" "<<k3<<" "<<t[k1].ma.l<<" "<<t[k1].ma.r<<" "<<t[k1].ma.w<<" "<<t[k1].mi.l<<" "<<t[k1].mi.r<<" "<<t[k1].mi.w<<endl;
    int mid=k2+k3>>1; if (k2==k3) return; pushdown(k1); print(k1*2,k2,mid); print(k1*2+1,mid+1,k3);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int k1; scanf("%d",&k1); change(1,1,n,i,k1);
    }
    scanf("%d",&m);
    for (;m;m--){
        int k1,k2,k3; scanf("%d",&k1);
        if (k1==0){
            scanf("%d%d",&k2,&k3); change(1,1,n,k2,k3); //print(1,1,n);
        } else {
            scanf("%d%d%d",&k1,&k2,&k3); int ans=0;
            vector<int>Lwhere,Rwhere;
            for (int i=1;i<=k3;i++){
                tree k4=find(1,1,n,k1,k2); ans+=k4.ma.w; int where1=k4.ma.l,where2=k4.ma.r; //cout<<where1<<" "<<where2<<" "<<ans<<endl;
                reverse(1,1,n,where1,where2);// print(1,1,n);
                Lwhere.push_back(where1); Rwhere.push_back(where2);
            }
            printf("%d\n",ans);
            for (int i=Lwhere.size();i;i--) reverse(1,1,n,Lwhere[i-1],Rwhere[i-1]);
        }
    }
    return 0;
}