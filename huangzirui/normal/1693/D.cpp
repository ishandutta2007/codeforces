#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k,n,m,a[maxn],L[2][maxn],R[2][maxn],ansR[maxn],Ni[maxn];
namespace segment_tree{
    #define ls(x) ((x)<<1)
    #define rs(x) ((x)<<1|1)
    #define Mid ((L+R)>>1)
    int tree[maxn*4],Min[maxn*4];
    void pushdown(int root){
        Min[ls(root)]=min(Min[ls(root)],Min[root]);
        Min[rs(root)]=min(Min[rs(root)],Min[root]);
        tree[ls(root)]=min(tree[ls(root)],Min[root]);
        tree[rs(root)]=min(tree[rs(root)],Min[root]);
        Min[root]=1e9;
    }
    void clear(int root,int L,int R){
        if(L!=R)clear(ls(root),L,Mid),clear(rs(root),Mid+1,R);
        tree[root]=Min[root]=1000000000;
    }
    void change(int root,int L,int R,int l,int r,int w){
        if(l>r)return;
        if(L==l && R==r){
            Min[root]=min(Min[root],w);
            tree[root]=min(tree[root],w);
        }else{
            pushdown(root);
            if(r<=Mid)change(ls(root),L,Mid,l,r,w);
            else if(l>Mid)change(rs(root),Mid+1,R,l,r,w);
            else change(ls(root),L,Mid,l,Mid,w),change(rs(root),Mid+1,R,Mid+1,r,w);
        }
    }
    void update(int root,int L,int R,int x,int w){
        if(L==R)Min[root]=tree[root]=w;
        else{
            pushdown(root);
            if(x<=Mid)update(ls(root),L,Mid,x,w);
            else update(rs(root),Mid+1,R,x,w);
        }
    }
    void getans(int root,int L,int R,int *A){
        if(L==R)A[Ni[L]]=Min[root];
        else{
            pushdown(root);
            getans(ls(root),L,Mid,A);
            getans(rs(root),Mid+1,R,A);
        }
    }
}
int Sta[maxn],top,Ans[2][maxn];
vector<int>V[2][2][maxn];
int main(){
    cin>>n;
    for(i=1;i<=n;i++)scanf("%d",&a[i]),Ni[a[i]]=i;
    Sta[top=1]=1;
    for(i=2;i<=n;i++){
        while(top && a[i]>a[Sta[top]])top--;
        L[1][i]=Sta[top];
        Sta[++top]=i;
    }
    Sta[top=1]=1;
    for(i=2;i<=n;i++){
        while(top && a[i]<a[Sta[top]])top--;
        L[0][i]=Sta[top];
        Sta[++top]=i;
    }
    Sta[top=1]=n+1;
    for(i=n;i>=1;i--){
        while(top!=1 && a[i]>a[Sta[top]])top--;
        R[1][i]=Sta[top];
        Sta[++top]=i;
    }
    Sta[top=1]=n+1;
    for(i=n;i>=1;i--){
        while(top!=1 && a[i]<a[Sta[top]])top--;
        R[0][i]=Sta[top];
        Sta[++top]=i;
    }
    for(i=1;i<=n;i++){
        V[0][0][L[0][i]].push_back(i);
        V[1][0][R[0][i]].push_back(i);
        V[0][1][L[1][i]].push_back(i);
        V[1][1][R[1][i]].push_back(i);
    }
    segment_tree::clear(1,1,n);
    //3 4 1 2
    for(i=1;i<=n+1;i++){
        for(int u:V[0][0][i]){
            segment_tree::change(1,1,n,a[u]+1,n,u-1);
        }
        for(int u:V[1][1][i]){
            segment_tree::update(1,1,n,a[u],100000000);
        }
    }
    segment_tree::getans(1,1,n,Ans[0]);
    segment_tree::clear(1,1,n);
    for(i=1;i<=n+1;i++){
        for(int u:V[0][1][i]){
            segment_tree::change(1,1,n,1,a[u]-1,u-1);
        }
        for(int u:V[1][0][i]){
            segment_tree::update(1,1,n,a[u],100000000);
        }
    }
    segment_tree::getans(1,1,n,Ans[1]);
    for(i=1;i<=n;i++)cerr<<Ans[0][i]<<' ';cerr<<endl;
    long long ANS=0;
    multiset<int>St;int p=0;
    for(i=1;i<=n;i++){
        while(p!=n && (!St.size() || p+1<=*St.begin())){
            ++p;
            St.insert(min(Ans[0][p],Ans[1][p]));
        }
        St.erase(St.find(min(Ans[0][i],Ans[1][i])));
        // cerr<<"i="<<i<<' '<<p<<endl;
        ANS+=p-i+1;
    }
    cout<<ANS<<endl;
}