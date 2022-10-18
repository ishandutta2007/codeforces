#include<bits/stdc++.h>
#define MAX   500500
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
struct Item {
    Item *prev,*next,*havePair;
    char ch;
    Item() {
        prev=next=havePair=NULL;
        ch=0;
    }
};
Item *item[MAX];
char s[MAX],query[MAX];
int pairPos[MAX];
int n,m,q;
void process(void) {
    scanf("%d%d%d",&n,&q,&m);
    scanf("%s",s+1);
    scanf("%s",query+1);
    stack<int> st;
    FOR(i,1,n) {
        if (s[i]=='(') st.push(i);
        else {
            pairPos[st.top()]=i;
            pairPos[i]=st.top();
            st.pop();
        }
    }
    FOR(i,0,n+1) item[i]=new Item();
    FOR(i,0,n) item[i]->next=item[i+1];
    FOR(i,1,n+1) item[i]->prev=item[i-1];
    FOR(i,1,n) item[i]->havePair=item[pairPos[i]];
    FOR(i,1,n) item[i]->ch=s[i];
    Item *cur=item[m];
    FOR(i,1,q) {
        if (query[i]=='R') cur=cur->next;
        else if (query[i]=='L') cur=cur->prev;
        else {
            Item *open=cur->ch=='('?cur:cur->havePair;
            Item *close=open->havePair;
            Item *prev=open->prev;
            Item *next=close->next;
            prev->next=next;
            next->prev=prev;
            cur=next->next==NULL?prev:next;
        }
    }
    for (Item *p=item[0]->next;p!=item[n+1];p=p->next) printf("%c",p->ch); printf("\n");
}
int main(void) {
    process();
    return 0;
}