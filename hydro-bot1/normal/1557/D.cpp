// Hydro submission #625a1718cc64917dc4671d0e@1650071359664
#include <algorithm>
#include <stdio.h>
#include <vector>
typedef long long llt;
typedef unsigned uint;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return(a<b)?a=b,true:false;}
template<typename T>bol _min(T&a,T b){return(b<a)?a=b,true:false;}
template<typename T>T power(T base,T index,T mod){return((index<=1)?(index?base:1):(power(base*base%mod,index>>1,mod)*power(base,index&1,mod)))%mod;}
template<typename T>T lowbit(T n){return n&-n;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T lcm(T a,T b){return(a!=0||b!=0)?a/gcd(a,b)*b:(T)0;}
template<typename T,typename len_def>
class Splay
{
    public:
        Splay():rot(NULL){}
        ~Splay(){if(rot!=NULL)delete rot;}
        len_def size(){return(rot==NULL)?0:rot->siz;}
        voi bzr(){if(rot!=NULL)delete rot;rot=NULL;}
        voi insert(T key,len_def cnt=1)
        {
            if(rot==NULL){rot=new node(cnt),rot->key=key;return;}
            node*p=rot,*f=NULL;
            do
            {
                if(p->key==key){p->cnt+=cnt,p->resize();if(f!=NULL)f->resize();splay(p);return;}
                if((f=p,p=p->son[p->key<key])==NULL)
                {
                    p=new node(cnt),p->key=key,p->fath=f,f->son[f->key<key]=p,f->resize(),splay(p);
                    return;
                }
            }
            while(true);
        }
        voi cut(T key,len_def cnt=1)
        {
            node*p=rot,*f=NULL;
            while(p!=NULL)
            {
                if(p->key==key)
                {
                    p->cnt=(cnt<p->cnt)?p->cnt-cnt:0,p->resize();
                    if(f!=NULL)f->resize();
                    splay(p);return;
                }
                f=p,p=p->son[p->key<key];
            }
            splay(f);
        }
        voi make_count(T key,len_def cnt)
        {
            if(cnt==0){erase_all(key);return;}
            if(rot==NULL){rot=new node(cnt),rot->key=key;return;}
            node*p=rot,*f=NULL;
            do
            {
                if(p->key==key){p->cnt=cnt,p->resize();if(f!=NULL)f->resize();splay(p);return;}
                if((f=p,p=p->son[p->key<key])==NULL)
                {
                    p=new node(cnt),p->key=key,p->fath=f,f->son[f->key<key]=p,f->resize(),splay(p);
                    return;
                }
            }
            while(true);
        }
        voi erase(T key,len_def cnt=1)
        {
            if(rot==NULL)return;
            rank(key);node*p=rot;
            if(p->key!=key)return;
            if(cnt<p->cnt){p->cnt-=cnt,p->siz-=cnt;return;}
            if(p->son[0]==NULL&&p->son[1]==NULL){bzr();return;}
            if(p->son[0]==NULL){rot=p->son[1],rot->fath=NULL,kill(p);return;}
            if(p->son[1]==NULL){rot=p->son[0],rot->fath=NULL,kill(p);return;}
            pre(),p->son[1]->fath=rot,rot->son[1]=p->son[1],kill(p),rot->resize();
        }
        voi erase_all(T key)
        {
            if(rot==NULL)return;
            rank(key);node*p=rot;
            if(p->key!=key)return;
            if(p->son[0]==NULL&&p->son[1]==NULL){bzr();return;}
            if(p->son[0]==NULL){rot=p->son[1],rot->fath=NULL,kill(p);return;}
            if(p->son[1]==NULL){rot=p->son[0],rot->fath=NULL,kill(p);return;}
            pre(),p->son[1]->fath=rot,rot->son[1]=p->son[1],kill(p),rot->resize();
        }
        len_def count(T key)
        {
            node*p=rot,*last=NULL;
            do
            {
                if(p==NULL)return splay(last),0;
                if(key==p->key)break;
                p=p->son[p->key<key];
            }
            while(true);
            return splay(p),p->cnt;
        }
        len_def rank(T key)
        {
            len_def ans=0;node*p=rot,*last=NULL;
            while(p!=NULL)
                if(key<p->key)last=p,p=p->son[0];
                else
                {
                    if(p->son[0]!=NULL)ans+=p->son[0]->siz;
                    if(key==p->key)return splay(p),ans;
                    ans+=p->cnt,last=p,p=p->son[1];
                }
            return splay(last),ans;
        }
        T kth(len_def k)
        {
            node*p=rot;
            while(p!=NULL)
                if(p->son[0]!=NULL&&k<p->son[0]->siz)p=p->son[0];
                else
                {
                    if(p->son[0]!=NULL)k-=p->son[0]->siz;
                    if(k<p->cnt)break;
                    k-=p->cnt,p=p->son[1];
                }
            return splay(p),p->key;
        }
        T pre(T key){insert(key),pre();T ans=rot->key;erase(key);return ans;}
        T nxt(T key){insert(key),nxt();T ans=rot->key;erase(key);return ans;}
    private:
        class node
        {
            public:
                T key;len_def cnt,siz;node*son[2],*fath;
                node(len_def cnt=1){siz=this->cnt=cnt,son[0]=son[1]=fath=NULL;}
                ~node(){if(son[0]!=NULL)delete son[0];if(son[1]!=NULL)delete son[1];}
                voi resize()
                {
                    siz=cnt;
                    if(son[0]!=NULL)siz+=son[0]->siz;
                    if(son[1]!=NULL)siz+=son[1]->siz;
                }
                bol howson(){return this==fath->son[1];}
                voi rotate()
                {
                    node*f=fath;
                    if(f==NULL)return;
                    node*ff=f->fath;
                    bol sk=howson();
                    if(ff!=NULL)ff->son[f->howson()]=this;
                    f->son[sk]=son[!sk];
                    if(son[!sk]!=NULL)son[!sk]->fath=f;
                    son[!sk]=f,f->fath=this,fath=ff,f->resize(),resize();
                }
        };
        node*rot;
        voi splay(node*p)
        {
            if(p==NULL)return;
            while(p->fath!=NULL)
            {
                if(p->fath->fath!=NULL)((p->howson()==p->fath->howson())?p->fath:p)->rotate();
                p->rotate();
            }
            rot=p;
        }
        voi kill(node*p){p->son[0]=p->son[1]=NULL;delete p;}
        node*pre()
        {
            node*p=rot->son[0];
            if(p==NULL)return NULL;
            while(p->son[1]!=NULL)p=p->son[1];
            return splay(p),p;
        }
        node*nxt()
        {
            node*p=rot->son[1];
            if(p==NULL)return NULL;
            while(p->son[0]!=NULL)p=p->son[0];
            return splay(p),p;
        }
};
typedef std::pair<ullt,uint>Pair;
int In[300005];
Pair P[1919810];
std::vector<uint>Way[300005];
Splay<int,uint>S;
uint DP[300005],Last[300005];
int main()
{
    uint n,m,u,l,r;scanf("%u%u",&n,&m);
    for(uint i=0;i<m;i++)scanf("%u%u%u",&u,&l,&r),P[i<<1]=Pair((ullt)l*2-1,--u),P[(i<<1)|1]=Pair((ullt)r*2,u);
    std::sort(P,P+(m<<=1));
    S.insert(-1),S.insert(n);
    for(uint i=0;i<m;i++)
    {
        u=P[i].second;
        if(P[i].first&1)
        {
            int p=S.pre(u),q=S.nxt(u);
            if(~p)Way[u].push_back(p);
            if((uint)q<n)Way[q].push_back(u);
            S.insert(u);
            In[u]++;
        }
        else S.erase(u),In[u]--;
    }
    uint ans=0;
    u=-1;
    for(uint i=0;i<n;i++)
    {
        Last[i]=-1;
        // printf("%u:",i+1);
        for(auto p:Way[i])
        {
            if(_max(DP[i],DP[p]))Last[i]=p;
            // printf("%u ",p+1);
        }
        // putchar('\n');
        if(_max(ans,++DP[i]))u=i;
    }
    while(~u)In[u]=true,u=Last[u];
    ans=n-ans;
    printf("%u\n",ans);
    for(uint i=0;i<n;i++)if(!In[i])
        printf("%u%c",i+1,(--ans)?' ':'\n');
    return 0;
}