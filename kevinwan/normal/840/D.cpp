#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=3e5+10;
int a[mn];
vector<int>p[mn];
int seg[20][mn][5];
int num[5];
#define mid ((l+r)>>1)
int cnt[mn];
void init(int lev,int l,int r){
    memset(num,0,sizeof(num));
    for(int i=mid;i>=l;i--){
        cnt[a[i]]++;
        for(int j=0;j<5;j++)if(a[i]==num[j]){
            for(int k=j;k<4;k++)num[k]=num[k+1];
            num[4]=0;
            break;
        }
        for(int j=0;j<5;j++){
            if(cnt[a[i]]>cnt[num[j]]){
                for(int k=4;k>=j;k--)num[k+1]=num[k];
                num[j]=a[i];
                break;
            }
        }
        for(int j=0;j<5;j++)seg[lev][i][j]=num[j];
    }
    for(int i=mid;i>=l;i--)cnt[a[i]]--;
    memset(num,0,sizeof(num));
    for(int i=mid+1;i<=r;i++){
        cnt[a[i]]++;
        for(int j=0;j<5;j++)if(a[i]==num[j]){
                for(int k=j;k<4;k++)num[k]=num[k+1];
                num[4]=0;
                break;
            }
        for(int j=0;j<5;j++){
            if(cnt[a[i]]>cnt[num[j]]){
                for(int k=4;k>=j;k--)num[k+1]=num[k];
                num[j]=a[i];
                break;
            }
        }
        for(int j=0;j<5;j++)seg[lev][i][j]=num[j];
    }
    for(int i=mid+1;i<=r;i++)cnt[a[i]]--;
    if(l!=r){
        init(lev+1,l,mid);
        init(lev+1,mid+1,r);
    }
}
int ans=0x3f3f3f3f;
int f,s,k;
void query(int lev,int l,int r){
    if(s<=mid)query(lev+1,l,mid);
    else if(f>mid)query(lev+1,mid+1,r);
    else{
        for(int i=0;i<5;i++){
            int x=seg[lev][f][i];
            int val=upper_bound(p[x].begin(),p[x].end(),s)-lower_bound(p[x].begin(),p[x].end(),f);
            if(val*k>s-f+1)ans=min(ans,x);
            x=seg[lev][s][i];
            val=upper_bound(p[x].begin(),p[x].end(),s)-lower_bound(p[x].begin(),p[x].end(),f);
            if(val*k>s-f+1)ans=min(ans,x);
        }
    }
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",a+i),p[a[i]].push_back(i);
    init(0,1,n);
    while(q--){
        scanf("%d%d%d",&f,&s,&k);
        if(f==s){
            printf("%d\n",a[f]);
            continue;
        }
        ans=0x3f3f3f3f;
        query(0,1,n);
        if(ans<=n)printf("%d\n",ans);
        else printf("-1\n");
    }
}