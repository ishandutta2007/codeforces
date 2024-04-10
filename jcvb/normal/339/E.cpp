#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[1005];
pair<int,int> t[500];int tot=0;
int sol[5],sor[5];
void rev(int i,int j){ 
    for (int k=1;i+k-1<j-k+1;k++){
        swap(t[i+k-1],t[j-k+1]);
    }
    for (int k=i;k<=j;k++)swap(t[k].first,t[k].second);
}
int check(int s){
    int su=1;
    for (int i=2;i<=tot;i++){
        if(abs(t[i].first-t[i-1].second)!=1)su++;
    }
    if(su>1)return su;
    if(t[1].first!=1 ||t[tot].second!=n)return su;
    printf("%d\n",s);
    for (int i=s;i>=1;i--){
        int l=sol[i],r=sor[i];
        int su=0;
        for (int k=1;k<l;k++)su+=abs(t[k].first-t[k].second)+1;
        printf("%d ",su+1);
        for (int k=l;k<=r;k++)su+=abs(t[k].first-t[k].second)+1;
        printf("%d\n",su);
        rev(l,r);
    }
    exit(0);
}
void dfs(int s){
    int tt=check(s-1);
    if(tt>(4-s)*2+1)return;
    if(s<=3){
        for (int i=1;i<=tot;i++)
            for (int j=i;j<=tot;j++){
                sol[s]=i,sor[s]=j;
                if(i==j && t[i].first==t[i].second)continue;
                rev(i,j);
                dfs(s+1);
                rev(i,j);
            }
    }
}
int cut[1005]={0};
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);a[n+1]=1000000;
    for (int i=2,st=1;i<=n+1;i++)
        if(abs(a[i]-a[i-1])!=1){
            int j=a[st],k=a[i-1];
            if(j>k)swap(j,k);
            cut[j-1]=cut[k+1]=1;
        }
    for (int i=2,st=1;i<=n+1;i++)
        if(abs(a[i]-a[i-1])!=1||cut[a[i]]||cut[a[i-1]]){
            t[++tot]=make_pair(a[st],a[i-1]);
            st=i;
        }
    dfs(1);
    return 0;
}