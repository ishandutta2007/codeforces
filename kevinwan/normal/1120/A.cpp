#include<bits/stdc++.h>
using namespace std;
mt19937 rng(0);
typedef long long ll;
const int mn=5e5+10;
int a[mn],b[mn],c[mn],d[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int m,k,n,s,x,i,j;
    cin>>m>>k>>n>>s;
    for(i=1;i<=m;i++)cin>>a[i];
    for(i=1;i<=s;i++)cin>>x,b[x]++;
    memcpy(c,b,sizeof(c));
    int rem=s;
    for(i=1,j=0;i<=m;i++){
        while(j<m&&(rem||j<i+k-1)){
            j++;
            d[a[j]]++;
            if(d[a[j]]<=b[a[j]])rem--;
        }
        if(j-i<k-1||rem)i=m+1;
        if((i-1)/k+(m-j)/k>=n-1)break;
        d[a[i]]--;
        if(d[a[i]]<b[a[i]])rem++;
    }
    if(i==m+1)printf("-1");
    else{
        vector<int>v;
        int l=i,r=j;
        for(i=min(n-1,(l-1)/k)*k+1;i<l;i++)v.push_back(i);
        for(i=l;i<=r;i++){
            if(!c[a[i]])v.push_back(i);
            else c[a[i]]--;
        }
        for(i=0;i<k-s;i++)v.pop_back();
        for(i=0;v.size()<m-n*k;i++)v.push_back(r+1+i);
        printf("%d\n",m-n*k);
        for(int x:v)printf("%d ",x);
    }
}