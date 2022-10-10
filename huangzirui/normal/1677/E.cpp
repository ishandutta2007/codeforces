#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=200010,maxm=1000010;
int i,j,k,n,m,p[maxn],id[maxn],lmax[maxn],rmax[maxn];
int Sta[maxn],top;
vector<int>V[maxn];
struct Query{
    int L,R,y;
    int op,id;
}Q[maxm*20];int Cnt;
vector<pair<int,int> >Tmp,Tmp2;
void init(){
    p[0]=1e9;p[n+1]=1e9;
    Sta[top=1]=0;
    for(int i=1;i<=n;i++){
        while(p[i]>p[Sta[top]])--top;
        lmax[i]=Sta[top];Sta[++top]=i;
    }
    Sta[top=1]=n+1;
    for(int i=n;i>=1;i--){
        while(p[i]>p[Sta[top]])--top;
        rmax[i]=Sta[top];Sta[++top]=i;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;i*j<=n;j++)
            V[i*j].push_back(i);
    for(int K=1;K<=n;K++){
        Tmp.clear();
        int L1=lmax[id[K]]+1,R2=rmax[id[K]]-1,lst=L1;
        // cerr<<"K="<<K<<endl;
        for(int i:V[K]){
            if(1ll*i*i==K)continue;
            int L2=min({id[i],id[K/i],id[K]}),R1=max({id[i],id[K/i],id[K]});
            // cerr<<L1<<' '<<L2<<' '<<R1<<' '<<R2<<endl;
            Tmp.push_back(make_pair(L2,R1));
        }
        if(!Tmp.size())continue;
        sort(Tmp.begin(),Tmp.end(),[](auto a,auto b){return a.second<b.second || (a.second==b.second && a.first>b.first);});
        Tmp2.push_back(Tmp[0]);
        for(int i=1;i<Tmp.size();i++)if(Tmp[i].first>(*--Tmp2.end()).first)Tmp2.push_back(Tmp[i]);
        Tmp=Tmp2;Tmp2.clear();
        for(auto P:Tmp){
            if(P.first<L1)continue;
            if(P.second>R2)break;
            // cerr<<"OK! "<<lst<<' '<<P.first<<' '<<P.second<<' '<<R2<<endl;
            Q[++Cnt]={lst,P.first,P.second,1,0};
            Q[++Cnt]={lst,P.first,R2+1,-1,0};
            lst=P.first+1;
        }
    }
}
namespace segment_tree{
    #define Mid ((L+R)>>1)
    #define ls(x) ((x)<<1)
    #define rs(x) ((x)<<1|1)
    ll K[maxn*4],B[maxn*4];
    ll lK[maxn*4],lB[maxn*4];
    void update(int root){
        K[root]=K[ls(root)]+K[rs(root)];
        B[root]=B[ls(root)]+B[rs(root)];
    }
    void pushdown(int root,int L,int R){
        K[ls(root)]+=lK[root]*(Mid-L+1);lK[ls(root)]+=lK[root];
        B[ls(root)]+=lB[root]*(Mid-L+1);lB[ls(root)]+=lB[root];
        K[rs(root)]+=lK[root]*(R-Mid);lK[rs(root)]+=lK[root];
        B[rs(root)]+=lB[root]*(R-Mid);lB[rs(root)]+=lB[root];
        lK[root]=lB[root]=0;
    }
    void ADD(int root,int L,int R,int l,int r,int tk,int tb){
        // cerr<<"ADD "<<root<<' '<<L<<' '<<R<<' '<<l<<' '<<r<<' '<<tk<<' '<<tb<<endl;
        if(L==l && R==r){
            K[root]+=1ll*tk*(R-L+1);
            B[root]+=1ll*tb*(R-L+1);
            lK[root]+=tk;
            lB[root]+=tb;
        }else{
            pushdown(root,L,R);
            if(r<=Mid)ADD(ls(root),L,Mid,l,r,tk,tb);
            else if(l>Mid)ADD(rs(root),Mid+1,R,l,r,tk,tb);
            else ADD(ls(root),L,Mid,l,Mid,tk,tb),ADD(rs(root),Mid+1,R,Mid+1,r,tk,tb);
            update(root);
        }
    }
    ll find(int root,int L,int R,int l,int r,int s){
        // cerr<<"find "<<root<<' '<<L<<' '<<R<<' '<<l<<' '<<r<<' '<<s<<endl;
        if(L==l && R==r)return K[root]*s+B[root];
        else{
            pushdown(root,L,R);
            if(r<=Mid)return find(ls(root),L,Mid,l,r,s);
            else if(l>Mid)return find(rs(root),Mid+1,R,l,r,s);
            else return find(ls(root),L,Mid,l,Mid,s)+find(rs(root),Mid+1,R,Mid+1,r,s);
        }
    }
}
ll ANS[maxm];
int main(){
    cin>>n>>m;
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
        id[p[i]]=i;
    }
    init();
    cerr<<"OK!"<<endl;
    for(i=1;i<=m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        Q[++Cnt]={l,r,l-1,-1,i};
        Q[++Cnt]={l,r,r,1,i};
    }
    sort(Q+1,Q+1+Cnt,[](Query a,Query b){return a.y<b.y || (a.y==b.y && a.id<b.id);});
    // for(i=1;i<=Cnt;i++)
    //     cerr<<"i="<<i<<' '<<Q[i].L<<' '<<Q[i].R<<' '<<Q[i].y<<' '<<Q[i].op<<' '<<Q[i].id<<endl;
    for(i=1;i<=Cnt;i++){
        // cerr<<"i="<<i<<' '<<Q[i].L<<' '<<Q[i].R<<' '<<Q[i].y<<' '<<Q[i].op<<' '<<Q[i].id<<endl;
        if(Q[i].id){
            int id=abs(Q[i].id),b=Q[i].op>0?1:-1;
            ll S=segment_tree::find(1,1,n,Q[i].L,Q[i].R,Q[i].y);
            // cerr<<"S="<<S<<endl;
            ANS[id]+=b*S;
        }else{
            int tk=Q[i].op,tb=-tk*(Q[i].y-1);
            segment_tree::ADD(1,1,n,Q[i].L,Q[i].R,tk,tb);
        }
    }
    for(i=1;i<=m;i++)printf("%lld\n",ANS[i]);
}