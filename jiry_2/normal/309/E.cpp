#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
struct atom{
    int l,r,id;
    int if_link(atom k1){
        return min(k1.r,r)>=max(k1.l,l);
    }
}x[2100],y[2100];
int operator < (const atom k1,const atom k2){
    return (k1.r<k2.r)||(k1.r==k2.r&&k1.l<k2.l)||(k1.r==k2.r&&k1.l==k2.l&&k1.id>k2.id);
}
set<atom>S;
vector<atom>rem;
int n,A[2100],len,pd[2100];
int check(int k){
    for (int i=1;i<=n;i++) y[i]=x[i];
    sort(y+1,y+n+1);
    for (int i=1;i<=n;i++){
        len=0;
        for (int j=i+1;j<=n;j++) if (y[i].if_link(y[j])) A[++len]=j;
        memset(pd,0x00,sizeof pd);
        if (len>k) return 0; if (A[len]<=i+k) continue;
        S.clear();
        int ipos=i+k+1;
        for (int j=1;j<=len;j++) if (i+k-(len-j)<A[j]){
            pd[A[j]]=1; S.insert(y[A[j]]); ipos--;
        }
        rem.clear();
        for (int j=i+1;j<=n;j++) if (pd[j]==0) rem.push_back(y[j]);
        for (int j=ipos;j<=i+k;j++){
            atom k1=y[j];
            if (S.find(y[j])==S.end()) k1=*S.begin();
            S.erase(k1); y[j]=k1;
        }
        vector<atom>::iterator now=rem.begin();
        for (int j=i+1;j<=n;j++)
            if (j<ipos||j>i+k){
                y[j]=*now; now++;
            }
    }
    return 1;
}
int main(){
    scanf("%d",&n); for (int i=1;i<=n;i++) {scanf("%d%d",&x[i].l,&x[i].r); x[i].id=i;}
    int l=1,r=n,ans;
    while (l<r){
        int mid=l+r>>1;
        if (check(mid)){
            ans=mid; r=mid;
        } else l=mid+1;
    }
    check(ans); for (int i=1;i<=n;i++) printf("%d ",y[i].id); cout<<endl;
    return 0;
}