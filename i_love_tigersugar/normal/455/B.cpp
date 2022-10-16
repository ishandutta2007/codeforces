#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const string fi="First";
const string se="Second";
class Trie {
    private:
    struct node {
        node *ch[26];
        bool win[2],leaf;
        node() {
            REP(i,26) ch[i]=NULL;
            win[0]=win[1]=leaf=true;
        }
        void calc(void) {
            if (leaf) {
                REP(i,2) win[i]=i;
                return;
            }
            win[0]=win[1]=false;
            REP(i,26) if (ch[i]!=NULL) {
                ch[i]->calc();
                REP(j,2) if (!ch[i]->win[j]) win[j]=true;
            }
        }
    };
    node *root;
    public:
    Trie() {
        root=new node();
    }
    void addstring(const string &t) {
        node *p=root;
        FORE(it,t) {
            if (p->ch[*it-'a']==NULL) p->ch[*it-'a']=new node();
            p->leaf=false;
            p=p->ch[*it-'a'];
        }
    }
    void calculate() {
        root->calc();
    }
    bool win(int x) const {
        return (root->win[x]);
    }
};
Trie trie;
void process(void) {
    int n,k;
    cin>>n>>k;
    REP(zz,n) {
        string t;
        cin>>t;
        trie.addstring(t);
    }
    trie.calculate();
    if (!trie.win(0)) cout<<se;
    else {
        if (trie.win(1)) cout<<fi;
        else cout<<(k%2?fi:se);
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    process();
    return 0;
}