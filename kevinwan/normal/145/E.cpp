#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+10;
int sa[mn*3],sb[mn*3],sab[mn*3],sba[mn*3];
bool laz[mn*3];
void prop(int x){
    if(laz[x]){
        swap(sa[x],sb[x]);
        swap(sab[x],sba[x]);
        if(x*2+1<mn*3){
            laz[x*2]^=1;
            laz[x*2+1]^=1;
        }
        laz[x]=0;
    }
}
void eval(int x){
    prop(x*2),prop(x*2+1);
    sa[x]=sa[x*2]+sa[x*2+1];
    sb[x]=sb[x*2]+sb[x*2+1];
    sab[x]=max(sab[x*2]+sb[x*2+1],sa[x*2]+sab[x*2+1]);
    sba[x]=max(sba[x*2]+sa[x*2+1],sb[x*2]+sba[x*2+1]);
}
#define mid (l+r>>1)
void up(int x,int l,int r,int a,int b){
    if(l==a&&r==b)laz[x]^=1;
    else{
        prop(x);
        if(b<=mid)up(x*2,l,mid,a,b);
        else if(a>mid)up(x*2+1,mid+1,r,a,b);
        else up(x*2,l,mid,a,mid),up(x*2+1,mid+1,r,mid+1,b);
        eval(x);
    }
}
string s;
void init(int x,int l,int r){
    if(l==r){
        if(s[l]=='4')sa[x]=sab[x]=sba[x]=1;
        else sb[x]=sab[x]=sba[x]=1;
    }
    else{
        init(x*2,l,mid);
        init(x*2+1,mid+1,r);
        eval(x);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    cin>>s;
    s=" "+s;
    init(1,1,n);
    while(m--){
        string a;
        int b,c;
        cin>>a;
        if(a[0]=='c'){
            prop(1);
            printf("%d\n",sab[1]);
        }
        else{
            scanf("%d%d",&b,&c);
            up(1,1,n,b,c);
        }
    }
}