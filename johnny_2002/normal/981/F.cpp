#include <bits/stdc++.h>

using namespace std;



#define X first
#define Y second

typedef long long ll;
typedef pair<int,int> ii;


const int N=4e5+10;
int n,len,n1;
int a[2][N];
ii b[N];


ii standardize_seg(ii a){
        if (a.X<0) a.X+=len;
        if (a.X>=len) a.X-=len;
        if (a.Y<0) a.Y+=len;
        if (a.Y>=len) a.Y-=len;
        return a;
}
ii getrem(int p2,int p1,int reach){
        int dist=p2-p1;
        if (p2<p1) dist=len-p1+p2;
        return standardize_seg(ii(p2-min(reach,dist-reach-1),p2+reach));
}
ii getseg(int pos,int reach){
        ii ans=ii(pos-reach,pos+reach);
        if (ans.X<0) ans.X+=len;
        if (ans.Y>=len) ans.Y-=len;
        return ans;
}
int findmen(ii segment){
        int ans=upper_bound(a[1]+1,a[1]+n+1,segment.Y)-lower_bound(a[1]+1,a[1]+n+1,segment.X);
        if (segment.Y<segment.X) ans+=n;
        return ans;
}
struct segtree{
        int b[N<<2],laz[N<<2];
        void lazyupdate(int node,int L,int R){
                b[node]+=laz[node];
                if (L<R){
                        laz[node*2+1]+=laz[node];
                        laz[node*2]+=laz[node];
                }
                laz[node]=0;
        }
        void add(int node,int L,int R,int l,int r,int val){
                lazyupdate(node,L,R);
                if (L>r||R<l) return;
                if (l<=L&&R<=r){
                        laz[node]+=val;
                        lazyupdate(node,L,R);
                        return;
                }
                add(node*2,L,(L+R)/2,l,r,val);
                add(node*2+1,(L+R)/2+1,R,l,r,val);
                b[node]=min(b[node*2],b[node*2+1]);
        }
        void reset(){
                memset(b,0,sizeof(b));
                memset(laz,0,sizeof(laz));
        }
}mseg;
bool check(int reach){
        //cout<<"?"<<reach<<'\n';
        int bad=0;
        for(int i=1;i<=2*n1;i++){
                ii cre=getseg(b[i].X,reach);
                int fbad=findmen(getseg(b[i].X,reach))-b[i].Y;
                if (i>1){
                        ii remreach=getrem(b[i].X,b[i-1].X,reach);
                        int sbad=bad+findmen(remreach)-b[i].Y;
                        bad=min(fbad,sbad);
                }else bad=fbad;
                if (bad<0) return 0;
        }
        return 1;
}
int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin>>n>>len;
        for(int i=1;i>=0;i--){
                for(int j=1;j<=n;j++) cin>>a[i][j];
                sort(a[i]+1,a[i]+n+1);
        }
        //for(int i=1;i<=n;i++) cout<<a[1][i]<<" \n"[i==n];
        b[0].X=-1;
        for(int i=1;i<=n;i++){
                if (a[0][i]==b[n1].X) b[n1].Y++;
                else b[++n1]=ii(a[0][i],1);
        }
        for(int i=1;i<=n1;i++) b[n1+i]=b[i];
        ///not handle twinkle case
        int L=0,R=len/2-1;
        while (L<=R){
                int mid=(L+R)/2;
                if (check(mid)) R=mid-1;
                else L=mid+1;
        }
        cout<<L;
        //check(27);
}