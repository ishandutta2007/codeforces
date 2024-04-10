#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
struct Node {
    int isWord;
    Node* child[26];
    Node() {
        isWord=-1;
        REP(i,26) child[i]=NULL;
    }
};
Node* root;
string big,small[MAX];
int trace[MAX],n;
char lowerCase(char x) {
    if ('A'<=x && x<='Z') return (x-'A'+'a');
    return (x);
}
void addWord(string s,int id) {
    reverse(ALL(s));
    Node *p=root;
    FORE(it,s) {
        if (p->child[lowerCase(*it)-'a']==NULL) p->child[lowerCase(*it)-'a']=new Node();
        p=p->child[lowerCase(*it)-'a'];
    }
    p->isWord=id;
}
void init(void) {
    cin>>n>>big>>n;
    FOR(i,1,n) cin>>small[i];
    root=new Node();
    FOR(i,1,n) addWord(small[i],i);
}
void process(void) {
    memset(trace,-1,sizeof trace);
    trace[0]=0;
    REP(i,big.size()) if (trace[i]>=0) {
        int j=i;
        Node *p=root;
        while (p!=NULL && j<big.size()) {
            p=p->child[big[j]-'a'];
            j++;
            if (p!=NULL && p->isWord>0) trace[j]=p->isWord;
        }
    }
    assert(trace[big.size()]>=0);
    int i=big.size();
    vector<int> res;
    while (i>0) {
        res.push_back(trace[i]);
        i-=small[trace[i]].size();
    }
    reverse(ALL(res));
    FORE(it,res) cout<<small[*it]<<" ";
    cout<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}