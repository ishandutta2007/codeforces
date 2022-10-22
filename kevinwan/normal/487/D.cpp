#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+9;
const int mn=1e5+10;
string s[mn];
int nxt[mn][12];
int seg[mn*4][12];
int t[12];
int n,m,q;
void mer(int c[12],int a[12],int b[12]){
    for(int i=1;i<=m;i++){
        if(b[i]>=mn)t[i]=b[i];
        else t[i]=a[b[i]];
    }
    memcpy(c,t,sizeof(t));
}
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int a){
    if(l==r)memcpy(seg[x],nxt[a],sizeof(seg[x]));
    else{
        if(a<=mid)upd(x*2,l,mid,a);
        else upd(x*2+1,mid+1,r,a);
        mer(seg[x],seg[x*2],seg[x*2+1]);
    }
}
void eval(int i){
    for(int j=1;j<=m;j++){
        if(j==1&&s[i][j]=='<')nxt[i][j]=mn*2+i;
        if(j==m&&s[i][j]=='>')nxt[i][j]=mn*3+i;
        if(s[i][j]=='^')nxt[i][j]=j;
        if(j<m&&s[i][j]=='>'&&s[i][j+1]=='<')nxt[i][j]=nxt[i][j+1]=4*mn;
    }
    for(int j=2;j<=m;j++)if(s[i][j]=='<')nxt[i][j]=nxt[i][j-1];
    for(int j=m-1;j;j--)if(s[i][j]=='>')nxt[i][j]=nxt[i][j+1];
    upd(1,0,n,i);
}
int qu(int x,int l,int r,int a,int b){
    if(r==a)return seg[x][b];
    if(a<=mid)return qu(x*2,l,mid,a,b);
    int v=qu(x*2+1,mid+1,r,a,b);
    if(v>=mn)return v;
    return qu(x*2,l,mid,mid,v);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(seg,0x3f,sizeof(seg));
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=" "+s[i];
    }
    for(int i=1;i<=m;i++)nxt[0][i]=mn+i;
    upd(1,0,n,0);
    for(int i=1;i<=n;i++){
        eval(i);
    }
    while(q--){
        string aa;
        int a,b;
        cin>>aa;
        if(aa=="A") {
            cin>>a>>b;
            int v=qu(1,0,n,a,b);
            if(v<mn*2)printf("0 %d\n",v-mn);
            else if(v<mn*3)printf("%d 0\n",v-mn*2);
            else if(v<mn*4)printf("%d %d\n",v-mn*3,m+1);
            else printf("-1 -1\n");
        }
        else{
            cin>>a>>b>>aa;
            s[a][b]=aa[0];
            eval(a);
        }
    }
}