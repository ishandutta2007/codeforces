#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<string>
#include<vector>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long ll;
class BIT {
    private:
    int n;
    vector<int> v;
    void update(int x,int d) {
        if (x<1 || x>n) return;
        for (;x<=n;x+=x&-x) v[x]+=d;
    }
    public:
    BIT() {
        n=0;
    }
    BIT(int n) {
        this->n=n;
        v.assign(n+7,0);
    }
    int get(int x) const {
        if (x<1 || x>n) return (0);
        int ret=0;
        for (;x>=1;x&=x-1) ret+=v[x];
        return (ret);
    }
    void update(int l,int r,int d) {
        update(l,d);
        update(r+1,-d);
    }
};
class AhoCorasick {
    private:
    struct node {
        vector<node *> suf;
        node *ch[26],*fail;
        int val,sta,fin;
        node() {
            REP(i,26) ch[i]=NULL;
            fail=NULL;
            val=sta=fin=0;
        }
    };
    node *root;
    vector<bool> stt;
    vector<node *> add;
    BIT bit;
    void BFS(void) {
        queue<node *> q;
        REP(i,26) if (root->ch[i]!=NULL) {
            q.push(root->ch[i]);
            root->ch[i]->fail=root;
            root->suf.push_back(root->ch[i]);            
        }
        while (!q.empty()) {
            node *u=q.front();q.pop();
            REP(i,26) if (u->ch[i]!=NULL) {
                node *v=u->ch[i];
                node *w=u->fail;
                q.push(v);
                while (w!=NULL && w->ch[i]==NULL) w=w->fail;
                if (w==NULL) v->fail=root; else v->fail=w->ch[i];
                v->fail->suf.push_back(v);
                v->val+=v->fail->val;                
            }
        }
    }
    void DFS(node *u,int &cnt) {
        u->sta=++cnt;
        FORE(it,u->suf) DFS(*it,cnt);
        u->fin=cnt;
    }
    public:
    AhoCorasick() {
        root=new node();
    }
    void addstring(const string &s) {       
        node *p=root;
        FORE(it,s) {
            if (p->ch[*it-'a']==NULL) p->ch[*it-'a']=new node();
            p=p->ch[*it-'a'];
        }
        p->val++;
        stt.push_back(true);
        add.push_back(p);
    }
    void build(void) {
        BFS();
        int cnt=0;
        DFS(root,cnt);
        bit=BIT(cnt);
    }
    void insert(int i) {
        if (stt[i]) return;
        stt[i]=true;        
        bit.update(add[i]->sta,add[i]->fin,1);
    }
    void remove(int i) {
        if (!stt[i]) return;
        stt[i]=false;
        bit.update(add[i]->sta,add[i]->fin,-1);
    }
    ll countfit(const string &s) {
        node *p=root;
        ll res=0;
        FORE(it,s) {
            while (p!=NULL && p->ch[*it-'a']==NULL) p=p->fail;
            if (p==NULL) p=root; else p=p->ch[*it-'a'];
            res+=p->val+bit.get(p->sta);
        }
        return (res);
    }
};
inline int nextInt(void) {
    int x;
    cin>>x;
    return (x);
}
inline string nextString(void) {
    string s;
    cin>>s;
    return (s);
}
AhoCorasick AC;
void process(void) {
    int q=nextInt();
    REP(zz,nextInt()) AC.addstring(nextString());
    AC.build();
    REP(zz,q) {     
        string tmp=nextString();        
        if (tmp[0]=='+') AC.insert(atoi(tmp.c_str()+1)-1);
        if (tmp[0]=='-') AC.remove(atoi(tmp.c_str()+1)-1);
        if (tmp[0]=='?') cout<<AC.countfit(tmp.substr(1,tmp.size()))<<"\n";
    }
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    process();
    return 0;
}