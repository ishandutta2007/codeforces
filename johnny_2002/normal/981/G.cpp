#include <bits/stdc++.h>

using namespace std;



#define X first
#define Y second

typedef long long ll;
typedef pair<int,int> ii;
const int MOD=998244353;
const int N=2e5+10;

int n;
set <ii> mset[N];
struct segtree{
        int b[N<<2],laza[N<<2],lazm[N<<2];
        void lazyupdate(int node,int L,int R){
                b[node]=(1LL*b[node]*lazm[node]+1LL*laza[node]*(R-L+1))%MOD;
                if (L<R){
                        for(int i=0;i<=1;i++){
                                laza[node*2+i]=(1LL*laza[node*2+i]*lazm[node]+laza[node])%MOD;
                                lazm[node*2+i]=1LL*lazm[node*2+i]*lazm[node]%MOD;
                        }
                }
                lazm[node]=1;
                laza[node]=0;
        }
        void build(){
                fill(lazm,lazm+(N<<2),1);
        }
        void update(int node,int L,int R,int l,int r,int type){
                lazyupdate(node,L,R);
                if (L>r||R<l) return;
                if (l<=L&&R<=r){
                        if (type==1) laza[node]++;
                        else lazm[node]=2;
                        lazyupdate(node,L,R);
                        return;
                }
                update(node*2,L,(L+R)/2,l,r,type);
                update(node*2+1,(L+R)/2+1,R,l,r,type);
                b[node]=(b[node*2]+b[node*2+1])%MOD;
        }
        int get(int node,int L,int R,int l,int r){
                lazyupdate(node,L,R);
                if (L>r||R<l) return 0;
                if (l<=L&&R<=r) return b[node];
                return (get(node*2,L,(L+R)/2,l,r)+get(node*2+1,(L+R)/2+1,R,l,r))%MOD;
        }
}mseg;


ii cross(ii a,ii b){
        if (a.X>b.X) swap(a,b);
        return ii(b.X,min(a.Y,b.Y));
}
void call_update(int pos,int L,int R){
        vector <ii> c_merg;
        while (1){
                auto ite=mset[pos].lower_bound(ii(L,-1));
                if (ite==mset[pos].end()) break;
                if (ite->Y>R) break;
                c_merg.push_back(ii(ite->Y,ite->X));
                //cout<<"pull "<<ite->Y<<" "<<ite->X<<'\n';
                mset[pos].erase(ite);
        }
        if (c_merg.empty()){
                //cout<<"ins "<<R<<" "<<L<<'\n';
                mset[pos].insert(ii(R,L));
                mseg.update(1,1,n,L,R,1);
                return;
        }
        ///contain entire length
        if (c_merg[0].X<=L&&c_merg[0].Y>=R){
                //cout<<"+ "<<L<<" "<<R<<"2\n";
                mseg.update(1,1,n,L,R,2);
                mset[pos].insert(ii(c_merg[0].Y,c_merg[0].X));
                return;
        }
        ///cross from the left
        int st=0,curL=L;
        if (c_merg[0].X<=L){
                ii com=cross(c_merg[0],ii(L,R));
                mseg.update(1,1,n,com.X,com.Y,2);
                //cout<<"?"<<com.X<<" "<<com.Y<<"2\n";
                L=c_merg[0].X;
                curL=com.Y+1;
                st=1;
        }
        int en=int(c_merg.size())-1;
        
        for(int i=st;i<=en;i++){
                ii com=cross(ii(L,R),c_merg[i]);
                if (curL<com.X) mseg.update(1,1,n,curL,com.X-1,1);
                mseg.update(1,1,n,com.X,com.Y,2);
               
                //cout<<"+"<<curL<<" "<<com.X<<" "<<com.Y<<"\n";
                curL=com.Y+1;
        }
        if (curL<=R) {
                mseg.update(1,1,n,curL,R,1);
                //cout<<"?"<<curL<<" "<<R<<"1\n";
        }
        if (c_merg[en].Y>=R)
                R=c_merg[en].Y;
        //cout<<"ins "<<R<<" "<<L<<'\n';
        mset[pos].insert(ii(R,L));
}
int main(){
        int test;
        cin>>n>>test;
        mseg.build();
        while (test--){
                int type,L,R;
                cin>>type>>L>>R;
                if (type==1){
                        int pos;
                        cin>>pos;
                        call_update(pos,L,R);
                }else cout<<(mseg.get(1,1,n,L,R)+MOD)%MOD<<'\n';
        }
}