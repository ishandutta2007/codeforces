#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=3e5+5,maxm=3e6+5,cut=300;    //maxn:  maxm: ac
struct node{
    node *fa,*ch[26],*fail;
    int end,cnt;    //cnt: 
    node(){
        fa=fail=NULL; end=cnt=0;
        fill(ch,ch+26,fa);
    }
    inline void set_fail(node *u){
        fail=u;
        cnt=end+(u->cnt);
    }
};
node *que[maxm];
struct ACauto{
    int siz;
struct ac_auto{
    node *root;
    int size;
    ac_auto(){
        root=new node;
        size=0;
    }
    node *merge_node(node *a,node *b){
    if (!a) return b;
    if (!b) return a;
    int i;
    node *v;
    for (i=0;i<26;i++){
        v=a->ch[i]=merge_node(a->ch[i],b->ch[i]);
        if (v) v->fa=a;
    }
    a->end+=b->end;
//    delete b;
    return a;
}
    void clear(){/*
        int i,l,r;
        node *u,*v;
        l=r=0;
        que[r++]=root;
        while (l<r){
            u=que[l++];
            for (i=0;i<26;i++) if (v=u->ch[i])
                que[r++]=v;
            delete u;
        }*/
        root=new node;
        size=0;
    }
    void add_str(char s[]){
        node *u,*v;
        int i,id;
        u=root;
        for (i=0;s[i]!='\0';i++){
            id=s[i]-'a';
            v=u->ch[id];
            if (!v){
                v=new node;
                u->ch[id]=v;
                v->fa=u;
            }
            u=v;
        }
        v->end++;
        size+=i;
    }
    void merge_ac(ac_auto &b){
        size+=b.size;
        root=merge_node(root,b.root);
        b.root=new node;
        b.size=0;
    }
    void build_fail(){
        int i,l,r;
        node *u,*v,*w;
        l=0; r=0;
        for (i=0;i<26;i++) if (v=root->ch[i]){
            v->set_fail(root);
            que[r++]=v;
        }
        while (l<r){
            u=que[l++];
            for (i=0;i<26;i++) if (v=u->ch[i]){
                que[r++]=v;
                w=u->fail;
                while (w!=root){
                    if (w->ch[i]){
                        v->set_fail(w->ch[i]);
                        break;
                    }
                    w=w->fail;
                }
                if (w==root){
                    if (w->ch[i])
                        v->set_fail(w->ch[i]);
                    else
                        v->set_fail(root);
                }
            }
        }
    }
    LL query(char s[]){
        node *u;
        int i,id;
        LL ans;
        u=root; ans=0;
        for (i=0;s[i]!='\0';i++){
            id=s[i]-'a';
            while (u!=root){
                if (u->ch[id]){
                    u=u->ch[id];
                    break;
                }
                u=u->fail;
            }
            if (u==root){
                if (u->ch[id])
                    u=u->ch[id];
                else u=root;
            }
            ans+=u->cnt;
        }
        return ans;
    }
};
ac_auto ac1[maxn];
void clear()
{
    for (int i=0;i<siz;i++) ac1[i].clear();
    siz=0;
}
void insert(char s[])
{
    ac1[siz++].add_str(s);
    while (siz>1&&ac1[siz-1].size*2>ac1[siz-2].size){
        ac1[siz-2].merge_ac(ac1[siz-1]);
        siz--;
    }
    ac1[siz-1].build_fail();
}
LL query(char s[])
{
    LL ans=0;
    for (int j=0;j<siz;j++)
        ans+=ac1[j].query(s);
    return ans;
}
}ac1,ac2;
char s[maxn];
int main()
{
    int tt;
    int i,j,n,m,op;
    ac1.clear();ac2.clear();
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        scanf("%d%s",&op,s);
        if (op==1) ac1.insert(s);
        else if (op==3) printf("%I64d\n",ac1.query(s)-ac2.query(s)),fflush(stdout);
        else ac2.insert(s);
    }
    return 0;
}