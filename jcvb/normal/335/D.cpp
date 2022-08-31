#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define L 3000
int n;
int area[L+5][L+5]={0};
int up[L+5][L+5]={0};
int dow[L+5][L+5]={0};
int lef[L+5][L+5]={0};
int rig[L+5][L+5]={0};
vector<int> a[6000],b[6000];
struct rect{
    int x1,x2,y1,y2;
    void mark(int x){
        a[x1+y2].push_back(x);
        b[x2+y1].push_back(x);
        area[x1][y1]++;
        area[x1][y2+1]--;
        area[x2+1][y1]--;
        area[x2+1][y2+1]++;
        rig[x2][y2]++;rig[x1-1][y2]--;
        lef[x1][y1]++;lef[x2+1][y1]--;
        dow[x1][y1]++;dow[x1][y2+1]--;
        up[x2][y2]++;up[x2][y1-1]--;
    }
    int rd,lu;
}r[100005];

int seg[10000]={0};
int l1,r1,ans;
void que(int l,int r,int rt){
    if(l1<=l && r<=r1){if(::r[seg[rt]].rd>::r[ans].rd)ans=seg[rt];}
    else{
        int mid=l+r>>1;
        if(l1<=mid)que(l,mid,rt<<1);
        if(r1>mid)que(mid+1,r,rt<<1|1);
    }
}
int I,v;
void upd(int l,int r,int rt){
    if(l==r)seg[rt]=v;
    else{
        int mid=l+r>>1;
        if(I<=mid)upd(l,mid,rt<<1);
        else upd(mid+1,r,rt<<1|1);
        seg[rt]=::r[seg[rt<<1]].rd>::r[seg[rt<<1|1]].rd?seg[rt<<1]:seg[rt<<1|1];
    }
}
int out[100005];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d%d%d%d",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2);r[i].x1++,r[i].y1++;
        r[i].mark(i);
    }
    for (int i=1;i<=L;i++)
        for (int j=1;j<=L;j++)
            area[i][j]+=area[i][j-1];
    for (int i=1;i<=L;i++)
        for (int j=1;j<=L;j++)
            area[i][j]+=area[i-1][j];
    for (int i=1;i<=L;i++)
        for (int j=1;j<=L;j++)
            area[i][j]+=area[i][j-1];
    for (int i=1;i<=L;i++)
        for (int j=1;j<=L;j++)
            area[i][j]+=area[i-1][j];
    for (int j=1;j<=L;j++){
        int cur=0;
        for (int i=1;i<=L;i++){
            cur+=lef[i][j];
            if(cur)lef[i][j]=lef[i-1][j]+1;
            else lef[i][j]=0;
        }
        cur=0;
        for (int i=L;i>=1;i--){
            cur+=rig[i][j];
            if(cur)rig[i][j]=rig[i+1][j]+1;
            else rig[i][j]=0;
        }
    }
    for (int i=1;i<=L;i++){
        int cur=0;
        for (int j=1;j<=L;j++){
            cur+=dow[i][j];
            if(cur)dow[i][j]=dow[i][j-1]+1;
            else dow[i][j]=0;
        }
        cur=0;
        for (int j=L;j>=1;j--){
            cur+=up[i][j];
            if(cur)up[i][j]=up[i][j+1]+1;
            else up[i][j]=0;
        }
    }
#define full(x1,x2,y1,y2) ((area[x2][y2]-area[(x1)-1][y2]-area[x2][(y1)-1]+area[(x1)-1][(y1)-1])==((x2)-(x1)+1)*((y2)-(y1)+1))
    for (int i=1;i<=n;i++){
        int le=1,ri=min(rig[r[i].x1][r[i].y2],dow[r[i].x1][r[i].y2]),mi;
        while(le<=ri){
            mi=le+ri>>1;
            if(full(r[i].x1,r[i].x1+mi-1,r[i].y2-mi+1,r[i].y2))le=mi+1;
            else ri=mi-1;
        }
        r[i].rd=r[i].x1+ri-1;
        r[i].lu=r[i].x2-min(up[r[i].x2][r[i].y1],lef[r[i].x2][r[i].y1])+1;
    }
    r[0].rd=0;
    for (int i=2;i<=6000;i++)if(!a[i].empty() && !b[i].empty()){
        for (int j=0;j<a[i].size();j++){
            I=r[a[i][j]].x1;v=a[i][j];
            upd(1,L,1);
        }
        for (int j=0;j<b[i].size();j++){
            l1=r[b[i][j]].lu,r1=r[b[i][j]].x2,ans=0;
            que(1,L,1);
            if(r[ans].rd>=r[b[i][j]].x2){
                int x1=r[ans].x1,x2=r[b[i][j]].x2,y1=r[b[i][j]].y1,y2=r[ans].y2,tot=0;
                for (int k=1;k<=n;k++)if(r[k].x1>=x1 && r[k].x2<=x2 && r[k].y1>=y1 && r[k].y2<=y2)out[++tot]=k;
                printf("YES %d\n",tot);
                for (int k=1;k<=tot;k++){
                    if(k>1)printf(" ");
                    printf("%d",out[k]);
                }
                printf("\n");
                return 0;
            }
        }
        for (int j=0;j<a[i].size();j++){
            I=r[a[i][j]].x1;v=0;
            upd(1,L,1);
        }
    }
    printf("NO\n");
    return 0;
}