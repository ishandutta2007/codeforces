#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e5+10;
#define mid ((l+r)>>1)
struct segtree{
    int seg[mn*4],laz[mn*4];
    segtree(){memset(laz,-1,sizeof(laz));memset(seg,0,sizeof(seg));}
    inline void prop(int x,int l,int r){
        if(laz[x]<0)return;
        seg[x]=laz[x]?(r-l+1):0;
        if(x*2+1<mn*4){
            laz[x*2]=laz[x*2+1]=laz[x];
        }
        laz[x]=-1;
    }
    inline void eval(int x,int l,int r){
        prop(x*2,l,mid),prop(x*2+1,mid+1,r);
        seg[x]=seg[x*2]+seg[x*2+1];
    }
    void upd(int x,int l,int r,int a,int b,int c){
        if(l==a&&r==b)laz[x]=c;
        else{
            prop(x,l,r);
            if(b<=mid)upd(x*2,l,mid,a,b,c);
            else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
            else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
            eval(x,l,r);
        }
    }
    int qu(int x,int l,int r,int a,int b){
        prop(x,l,r);
        if(l==a&&r==b)return seg[x];
        else if(b<=mid)return qu(x*2,l,mid,a,b);
        else if(a>mid)return qu(x*2+1,mid+1,r,a,b);
        else return qu(x*2,l,mid,a,mid)+qu(x*2+1,mid+1,r,mid+1,b);
    }
} s[26];
int cnt[26];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    string str;
    cin>>str;
    for(int i=0;i<n;i++)s[str[i]-'a'].upd(1,0,n-1,i,i,1);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b),a--,b--;
        int no=0;
        for(int i=0;i<26;i++){
            cnt[i]=s[i].qu(1,0,n-1,a,b);
            if(cnt[i]&1)no++;
        }
        if(no>1)continue;
        for(int i=0;i<26;i++)s[i].upd(1,0,n-1,a,b,0);
        int num=0;
        for(int i=0;i<26;i++)if(cnt[i]/2){
                s[i].upd(1,0,n-1,a+num,a+num+cnt[i]/2-1,1);
                s[i].upd(1,0,n-1,b-num-cnt[i]/2+1,b-num,1);
                num+=cnt[i]/2;
            }
        for(int i=0;i<26;i++)if(cnt[i]%2==1){
                s[i].upd(1,0,n-1,a+num,a+num,1);
            }
    }
    for(int i=0;i<n;i++)for(int j=0;j<26;j++)if(s[j].qu(1,0,n-1,i,i))printf("%c",j+'a');
}