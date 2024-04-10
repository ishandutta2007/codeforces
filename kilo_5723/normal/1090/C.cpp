#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
struct node{
    int l,r,siz;
    node *ls,*rs;
    node(int _l=0,int _r=0,int _s=0){
        l=_l; r=_r; siz=_s;
        ls=rs=NULL;
    }
};
void add(node* nd,int val){
    nd->siz++;
    if (nd->l==nd->r) return;
    int m=(nd->l+nd->r)/2;
    if (val<=m){
        if (!(nd->ls)) nd->ls=new node(nd->l,m);
        add(nd->ls,val);
    }
    else{
        if (!(nd->rs)) nd->rs=new node(m+1,nd->r);
        add(nd->rs,val);
    }
}
void del(node* nd,int val){
    nd->siz--;
    if (nd->l==nd->r) return;
    int m=(nd->l+nd->r)/2;
    if (val<=m) del(nd->ls,val);
    else del(nd->rs,val);
}
int sear(node *a,node *b){
    if (a->l==a->r){
        return a->l;
    }
    if (!b){
        if (a->ls&&a->ls->siz)
            return sear(a->ls,NULL);
        else return sear(a->rs,NULL);
    }
    int val=0;
    if (a->ls) val+=a->ls->siz;
    if (b&&b->ls) val-=b->ls->siz;
    if (val>0) return sear(a->ls,b?b->ls:NULL);
    else return sear(a->rs,b?b->rs:NULL);
}
struct box{
    int id,size;
    node *root;
    box(int _i=0){
        id=_i; size=0; root=new node(1,100000);
    }
    void insert(int val){
        add(root,val);
        size++;
    }
    void erase(int val){
        del(root,val);
        size--;
    }
    void clear(){
        size=0; root=new node(1,100000);
    }
};
int find(box a,box b){
    return sear(a.root,b.root);
}
bool operator < (box a,box b){
    return a.size<b.size;
}
multiset<box> st;
box bx;
const int maxn=5e5+5;
int ope[maxn][3],siz;
int main(){
    int i,j,n,m;
    int k,t;
    int ans;
    multiset<box>::iterator it1,it2;
    box u,v;
    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++){
        scanf("%d",&k); bx.clear();
        bx.id=i+1;
        for(j=0;j<k;j++){
            scanf("%d",&t);
            bx.insert(t);
        }
        st.insert(bx);
    }
    ans=0; siz=0;
    while (true){
        it1=st.begin(); it2=st.end(); it2--;
        if (it2->size-it1->size<=1) break;
        u=*it1; v=*it2;
        st.erase(it1); st.erase(it2);
        t=find(v,u);
        v.erase(t); u.insert(t);
        ans++; ope[siz][0]=v.id; ope[siz][1]=u.id; ope[siz][2]=t;
        siz++;
        st.insert(u); st.insert(v);
    }
    printf("%d\n",ans);
    for (i=0;i<siz;i++)
        printf("%d %d %d\n",ope[i][0],ope[i][1],ope[i][2]);
    return 0;
}