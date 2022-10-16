#include<bits/stdc++.h>
#define MAX   227
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
class AhoCorasick {
    private:
    struct Node {
        Node *ch[26],*fail,*next[26];
        int val,id;
        Node() {
            REP(i,26) ch[i]=next[i]=NULL;
            fail=NULL;
            val=id=0;
        }
        Node(int x) {
            REP(i,26) ch[i]=NULL;
            fail=NULL;
            val=0;
            id=x;
        }
    };
    vector<Node *> add;
    Node *root;
    public:
    AhoCorasick() {
        root=new Node(0);
        add.push_back(root);
    }
    void addString(const string &s,int val) {
        Node *p=root;
        FORE(it,s) {
            if (p->ch[*it-'a']==NULL) {
                p->ch[*it-'a']=new Node(add.size());
                add.push_back(p->ch[*it-'a']);
            }
            p=p->ch[*it-'a'];
        }
        p->val+=val;
    }
    void BFS(void) {
        queue<Node *> q;
        REP(i,26) root->next[i]=root->ch[i]==NULL?root:root->ch[i];
        REP(i,26) if (root->ch[i]!=NULL) {
            root->ch[i]->fail=root;
            q.push(root->ch[i]);
            REP(j,26) root->ch[i]->next[j]=root->ch[i]->ch[j]==NULL?root->next[j]:root->ch[i]->ch[j];
        }
        while (!q.empty()) {
            Node *u=q.front();q.pop();
            REP(i,26) if (u->ch[i]!=NULL) {
                Node *v=u->ch[i];
                q.push(v);
                Node *w=u->fail;
                while (w!=NULL && w->ch[i]==NULL) w=w->fail;
                if (w==NULL) v->fail=root; else v->fail=w->ch[i];
                v->val+=v->fail->val;
                REP(j,26) v->next[j]=v->ch[j]==NULL?v->fail->next[j]:v->ch[j];
            }
        }
    }
    int size(void) const {
        return (add.size());
    }
    int getVal(int id) const {
        assert(id<add.size());
        return (add[id]->val);
    }
    int nextNode(int id,int x) {
        assert(id<add.size());
        return (add[id]->next[x]->id);
    }
};
int val[MAX];
string str[MAX];
int n,numNode;
long long len;
AhoCorasick AC;
long long maxValPw2[60][MAX][MAX],maxVal[2][MAX][MAX];
void init(void) {
    cin>>n>>len;
    REP(i,n) cin>>val[i];
    REP(i,n) cin>>str[i];
}
void buildGraph(void) {
    REP(i,n) AC.addString(str[i],val[i]);
    AC.BFS();
    numNode=AC.size();
    memset(maxValPw2,-0x3f,sizeof maxValPw2);
    FOR(i,1,numNode) REP(j,26) {
        int t=AC.nextNode(i-1,j)+1;
        int tmp=AC.getVal(t-1);
        maximize(maxValPw2[0][i][t],tmp);
    }
}
void process(void) {
    FOR(t,1,50) FOR(i,1,numNode) FOR(j,1,numNode) FOR(k,1,numNode)
        maximize(maxValPw2[t][i][k],maxValPw2[t-1][i][j]+maxValPw2[t-1][j][k]);
    int cur=0;
    memset(maxVal,-0x3f,sizeof maxVal);
    maxVal[cur][1][1]=0;
    REP(t,50) if (BIT(len,t)) {
        int prev=cur;
        cur^=1;
        memset(maxVal[cur],-0x3f,sizeof maxVal[cur]);
        FOR(i,1,numNode) FOR(j,1,numNode) FOR(k,1,numNode)
            maximize(maxVal[cur][i][k],maxVal[prev][i][j]+maxValPw2[t][j][k]);
    }
    long long res=0;
    FOR(i,1,numNode) maximize(res,maxVal[cur][1][i]);
    cout<<res<<endl;
}
int main(void) {
    init();
    buildGraph();
    process();
    return 0;
}