#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
struct node{
    int id;
    ll val;
};
ll a[maxn];
node b[maxn];
ll val[maxn],ans1[maxn],ans2[maxn];
bool cmp(node a,node b){
    return a.val<b.val;
}
int sear(int l,int r,ll v){
    if (r-l==1) return l;
    int m=(l+r)/2;
    if (val[m]<=v) return sear(m,r,v);
    else return sear(l,m,v);
}
int main(){
    int i,n,m,siz;
    int id,p,cnt;
    ll wid;
    ll l,r,k;
    ll ans;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%I64d",&a[i]);
    sort(a,a+n); m=n-1;
    for (i=0;i<m;i++){
        b[i].val=a[i+1]-a[i];
        b[i].id=i;
    }
    sort(b,b+m,cmp);
    siz=0; wid=0; cnt=n;
    val[0]=-1; ans1[0]=0; ans2[0]=n;
    siz++;
    for (i=0;i<m;i++){
        id=b[i].id;
        wid+=a[id+1]-a[id]; cnt--;
        if (i==m-1||b[i].val!=b[i+1].val){
            val[siz]=b[i].val;
            ans1[siz]=wid; ans2[siz]=cnt;
            siz++;
        }
    }
    scanf("%d",&m);
    for (i=0;i<m;i++){
        scanf("%I64d%I64d",&l,&r);
        k=r-l;
        p=sear(0,siz,k);
        ans=ans1[p]+ans2[p]*(k+1);
        printf("%I64d ",ans);
    }
    puts("");
    return 0;
}