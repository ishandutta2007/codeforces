#include<bits/stdc++.h>
using namespace std;
int n,a[100005],c1,c2,lim,tmp,cx,cy;
int aw,bw,lw;
struct Count {
    int x,y;
};
Count operator +(Count q1,Count q2) {
    return {q1.x+q2.x,q1.y+q2.y};
}
bool comp(Count q1,Count q2) {
    if(q1.x<q2.x)return true;
    if(q1.x==q2.x && q1.y<q2.y)return true;
    return false;
}
Count sp[100005][25],sum[100005];
vector<Count>ans;
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
        sp[i][0]={(a[i]==1),(a[i]==2)};
        c1+=(a[i]==1);
        c2+=(a[i]==2);
    }
    sum[n-1]=sp[n-1][0];
    for(i=n-2;i>=0;i--) {
        sum[i]=sum[i+1]+sp[i][0];
    }
    for(i=1;i<17;i++) {
        for(j=0;j<n;j++) {
            if(j+(1<<i)<n) {
                sp[j][i]=sp[j][i-1]+sp[j+(1<<(i-1))][i-1];
            }
            else {
                sp[j][i]={-1,-1};
            }
        }
    }
    lim=max(c1,c2);
    for(i=1;i<=lim;i++) {
        for(j=0;;) {
            cx=0;
            cy=0;
            if(j==n) {
                if((lw==1 && aw<=bw) || (lw==2 && aw>=bw))break;
                ans.push_back({max(aw,bw),i});
                break;
            }
            if(max(sum[j].x,sum[j].y)<i)break;
            for(k=16;k>=0;k--) {
                if(sp[j][k].x==-1)continue;
                if(max(sp[j][k].x+cx,sp[j][k].y+cy)<i) {
                    cx+=sp[j][k].x;
                    cy+=sp[j][k].y;
                    j+=(1<<k);
                }
            }
            cx+=sp[j][0].x;
            cy+=sp[j][0].y;
            j++;
            aw+=(cx==i);
            bw+=(cy==i);
            lw=(cx==i)+(cy==i)*2;
        }
        aw=0;
        bw=0;
    }
    sort(ans.begin(),ans.end(),comp);
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++) {
        printf("%d %d\n",ans[i].x,ans[i].y);
    }
}