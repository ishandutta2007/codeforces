#include<bits/stdc++.h>
#define MAX   5050
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
struct Node {
    Node *child[2];
    int totPalin,numPalin;
    Node() {
        REP(i,2) child[i]=NULL;
        numPalin=totPalin=0;
    }
    void calc(void) {
        totPalin=numPalin;
        REP(i,2) if (child[i]!=NULL) {
            child[i]->calc();
            totPalin+=child[i]->totPalin;
        }
    }
};
char s[MAX];
int n,pos;
bool isPalin[MAX][MAX];
Node *root;
void init(void) {
    scanf("%s",s+1);
    n=strlen(s+1);
    scanf("%d",&pos);
}
void findPalin(void) {
    FOR(i,1,n-1) {
        int L=i+1;
        int R=i;
        while (1<=L-2 && R+2<=n && s[L-2]==s[R+2]) {
            L-=2;R+=2;
            isPalin[L][R]=true;
        }
    }
    FOR(i,1,n-1) if (s[i]==s[i+1]) {
        int L=i;
        int R=i+1;
        isPalin[L][R]=true;
        while (1<=L-2 && R+2<=n && s[L-2]==s[R+2]) {
            L-=2;R+=2;
            isPalin[L][R]=true;
        }
    }
    FOR(i,1,n) {
        int L=i;
        int R=i;
        isPalin[L][R]=true;
        while (1<=L-2 && R+2<=n && s[L-2]==s[R+2]) {
            L-=2;R+=2;
            isPalin[L][R]=true;
        }
    }
    FOR(i,1,n) {
        int L=i+1;
        int R=i-1;
        while (1<=L-2 && R+2<=n && s[L-2]==s[R+2]) {
            L-=2;R+=2;
            isPalin[L][R]=true;
        }
    }
}
void buildTrie(void) {
    root=new Node();
    FOR(i,1,n) {
        Node *p=root;
        FOR(j,i,n) {
            if (p->child[s[j]-'a']==NULL) p->child[s[j]-'a']=new Node();
            p=p->child[s[j]-'a'];
            if (isPalin[i][j]) p->numPalin++;
        }
    }
    root->calc();
}
void trace(void) {
    string res;
    Node *p=root;
    while (true) {
        if (p->numPalin>=pos) break;
        pos-=p->numPalin;
        if (p->child[0]!=NULL && p->child[0]->totPalin>=pos) {
            p=p->child[0];
            res.push_back('a');
        } else {
            if (p->child[0]!=NULL) pos-=p->child[0]->totPalin;
            p=p->child[1];
            res.push_back('b');
        }
    }
    cout<<res<<endl;
}
int main(void) {
    init();
    findPalin();
    buildTrie();
    trace();
    return 0;
}