#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=2e5+10;
const ll mod=998244353;
struct vesh{
    int dp[5][5];
};
inline vesh add(vesh a,vesh b){
    vesh c=vesh();
    memset(c.dp,0x3f,sizeof(c.dp));
    for(int i=0;i<=4;i++){
        for(int j=i;j<=4;j++){
            for(int k=i;k<=j;k++){
                c.dp[i][j]=min(c.dp[i][j],a.dp[i][k]+b.dp[k][j]);
            }
        }
    }
    return c;
}
string s;
vesh seg[mn*4];
#define mid ((l+r)>>1)
void init(int x,int l,int r){
    if(l==r){
        for(int i=0;i<=4;i++)seg[x].dp[i][i]=0;
        if(s[l]=='2')seg[x].dp[0][0]=1,seg[x].dp[0][1]=0;
        else if(s[l]=='0')seg[x].dp[1][1]=1,seg[x].dp[1][2]=0;
        else if(s[l]=='1')seg[x].dp[2][2]=1,seg[x].dp[2][3]=0;
        else if(s[l]=='7')seg[x].dp[3][3]=1,seg[x].dp[3][4]=0;
        else if(s[l]=='6')seg[x].dp[3][3]=seg[x].dp[4][4]=1;
    }
    else{
        init(x*2,l,mid);
        init(x*2+1,mid+1,r);
        seg[x]=add(seg[x*2],seg[x*2+1]);
    }
}
vesh query(int x,int l,int r,int a,int b){
    if(l==a&&r==b)return seg[x];
    else{
        if(b<=mid)return query(x*2,l,mid,a,b);
        else if(a>mid)return query(x*2+1,mid+1,r,a,b);
        else return add(query(x*2,l,mid,a,mid),query(x*2+1,mid+1,r,mid+1,b));
    }
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    cin>>s;
    memset(seg,0x3f,sizeof(seg));
    init(1,0,n-1);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        int ans=query(1,0,n-1,a,b).dp[0][4];
        if(ans==0x3f3f3f3f)printf("-1\n");
        else printf("%d\n",ans);
    }
}