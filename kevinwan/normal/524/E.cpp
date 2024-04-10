#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=2e5+10;
int xl[mn],xr[mn],yl[mn],yr[mn];
bool ansx[mn],ansy[mn];
vector<int>vx[mn],vy[mn];
int seg[mn*2];
vector<int>er;
void upd(int l,int r,int v){
    for(l+=mn,r+=mn;l<=r;l>>=1,r>>=1){
        if(l&1)seg[l]=max(seg[l],v),er.push_back(l++);
        if(!(r&1))seg[r]=max(seg[r],v),er.push_back(r--);
    }
}
int que(int x){
    int ans=0;
    for(x+=mn;x;x>>=1)ans=max(ans,seg[x]);
    return ans;
}
void veshhail(){
    for(int x:er)seg[x]=0;
    er.clear();
}
int n,m,k,q;
void veshx(int l,int r,vector<int>v){
    int mid=((l+r)>>1);
    vector<int>a,b,c;
    for(int i:v){
        if(xr[i]<=mid)a.push_back(i);
        else if(xl[i]>mid)b.push_back(i);
        else c.push_back(i);
    }
    if(l!=r)veshx(l,mid,a),veshx(mid+1,r,b);
    else c=v;
    sort(c.begin(),c.end(),[](int a,int b){return xl[a]>xl[b];});
    for(int i=mid,j=0;i>=l;i--){
        int lv=0;
        for(int x:vx[i]){
            upd(lv+1,x,x);
            lv=x;
        }
        upd(lv+1,m,m+1);
        while(j<c.size()&&xl[c[j]]==i){
            if(yr[c[j]]<que(yl[c[j]]))ansx[c[j]]=0;
            j++;
        }
    }
    veshhail();
    sort(c.begin(),c.end(),[](int a,int b){return xr[a]<xr[b];});
    for(int i=mid+1,j=0;i<=r;i++){
        int lv=0;
        for(int x:vx[i]){
            upd(lv+1,x,x);
            lv=x;
        }
        upd(lv+1,m,m+1);
        while(j<c.size()&&xr[c[j]]==i){
            if(yr[c[j]]<que(yl[c[j]]))ansx[c[j]]=0;
            j++;
        }
    }
    veshhail();
}
void veshy(int l,int r,vector<int>v){
    int mid=((l+r)>>1);
    vector<int>a,b,c;
    for(int i:v){
        if(yr[i]<=mid)a.push_back(i);
        else if(yl[i]>mid)b.push_back(i);
        else c.push_back(i);
    }
    if(l!=r)veshy(l,mid,a),veshy(mid+1,r,b);
    else c=v;
    sort(c.begin(),c.end(),[](int a,int b){return yl[a]>yl[b];});
    for(int i=mid,j=0;i>=l;i--){
        int lv=0;
        for(int x:vy[i]){
            upd(lv+1,x,x);
            lv=x;
        }
        upd(lv+1,n,n+1);
        while(j<c.size()&&yl[c[j]]==i){
            if(xr[c[j]]<que(xl[c[j]]))ansy[c[j]]=0;
            j++;
        }
    }
    veshhail();
    sort(c.begin(),c.end(),[](int a,int b){return yr[a]<yr[b];});
    for(int i=mid+1,j=0;i<=r;i++){
        int lv=0;
        for(int x:vy[i]){
            upd(lv+1,x,x);
            lv=x;
        }
        upd(lv+1,n,n+1);
        while(j<c.size()&&yr[c[j]]==i){
            if(xr[c[j]]<que(xl[c[j]]))ansy[c[j]]=0;
            j++;
        }
    }
    veshhail();
}
int main(){

    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=0;i<k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        vx[x].push_back(y);
        vy[y].push_back(x);
    }
    for(int i=1;i<=n;i++)sort(vx[i].begin(),vx[i].end());
    for(int i=1;i<=m;i++)sort(vy[i].begin(),vy[i].end());
    for(int i=0;i<q;i++)scanf("%d%d%d%d",xl+i,yl+i,xr+i,yr+i);
    vector<int>v(q);
    iota(v.begin(),v.end(),0);
    memset(ansx,1,sizeof(ansx));
    memset(ansy,1,sizeof(ansy));
    veshx(1,n,v);
    veshy(1,m,v);
    for(int i=0;i<q;i++){
        if(ansx[i]||ansy[i])printf("YES\n");
        else printf("NO\n");
    }

}