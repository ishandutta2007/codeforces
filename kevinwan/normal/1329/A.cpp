#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=2e5+10;
void die(){
    printf("-1");
    exit(0);
}
int num[mn],l[mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    ll s=0;
    for(int i=1;i<=m;i++){
        scanf("%d",l+i);
        s+=l[i];
        if(i+l[i]-1>n)die();
    }
    if(s<n)die();
    int dis=n-(m+l[m]-1);
    for(int i=1;i<=m-1;i++)num[i]=1;
    for(int i=m-1;i>=1;i--){
        while(dis>0&&num[i]<l[i])num[i]++,dis--;
        dis=min(dis,n-(i+l[i]-1));
    }
    int x=1;
    for(int i=1;i<=m;i++){
        printf("%d ",x);
        x+=num[i];
    }
}