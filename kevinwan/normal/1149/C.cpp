#include <bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
int v[mn],seg[mn*3][5],laz[mn*3];
#define mid (l+r>>1)
inline void prop(int x){
    seg[x][0]+=laz[x];
    seg[x][1]-=2*laz[x];
    seg[x][2]-=laz[x];
    seg[x][3]-=laz[x];
    if(x<mn*3/2){
        laz[x*2]+=laz[x];
        laz[x*2+1]+=laz[x];
    }
    laz[x]=0;
}
inline void eval(int x){
    prop(x*2);
    prop(x*2+1);
    seg[x][0]=max(seg[x*2][0],seg[x*2+1][0]);
    seg[x][1]=max(seg[x*2][1],seg[x*2+1][1]);
    seg[x][2]=max(max(seg[x*2][2],seg[x*2+1][2]),seg[x*2][0]+seg[x*2+1][1]);
    seg[x][3]=max(max(seg[x*2][3],seg[x*2+1][3]),seg[x*2][1]+seg[x*2+1][0]);
    seg[x][4]=max(max(seg[x*2][4],seg[x*2+1][4]),max(seg[x*2][2]+seg[x*2+1][0],seg[x*2][0]+seg[x*2+1][3]));
}
void init(int x,int l,int r){
    if(l==r){
        seg[x][0]=v[l];
        seg[x][1]=-2*v[l];
        seg[x][2]=seg[x][3]=-v[l];
    }
    else{
        init(x*2,l,mid);
        init(x*2+1,mid+1,r);
        eval(x);
    }
}
void update(int x,int l,int r,int a,int b,int c){
    if(l==a&&r==b)laz[x]+=c;
    else{
        prop(x);
        if(b<=mid)update(x*2,l,mid,a,b,c);
        else if(a>mid)update(x*2+1,mid+1,r,a,b,c);
        else update(x*2,l,mid,a,mid,c),update(x*2+1,mid+1,r,mid+1,b,c);
        eval(x);
    }
}
int main()
{
    int n,q,i;
    scanf("%d%d",&n,&q);
    string s;
    cin>>s;
    n=2*n-2;
    s=" "+s;
    int cur=0;
    for(i=1;i<=n;i++){
        if(s[i]=='(')v[i]=v[i-1]+1;
        else v[i]=v[i-1]-1;
    }
    init(1,0,n);
    printf("%d\n",seg[1][4]);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        update(1,0,n,a,b-1,s[a]==')'?2:-2);
        swap(s[a],s[b]);
        prop(1);
        printf("%d\n",seg[1][4]);
    }
}