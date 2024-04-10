#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
struct Block {
    char ch;
    int l,r;
    Block() {
        ch=l=r=0;
    }
    Block(char _ch,int _l,int _r) {
        ch=_ch;l=_l;r=_r;
    }
    Block(int x) {
        ch='$';
        l=r=x;
    }
    bool operator < (const Block &b) const {
        return (l<b.l);
    }
};
char s[MAX];
int n,q;
set<Block> block;
void init(void) {
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    FOR(i,1,n) block.insert(Block(s[i],i,i));
}
void splitBlock(int x) {
    __typeof(block.begin()) it=block.lower_bound(Block(x));
    if (it!=block.end() && it->l==x) return;
    it--;
    Block prev(it->ch,it->l,x-1);
    Block next(it->ch,x,it->r);
    block.erase(it);
    block.insert(prev);
    block.insert(next);
}
void query(int l,int r,bool t) {
    splitBlock(l);
    splitBlock(r+1);
    vector<Block> toDel;
    int cnt[26];
    memset(cnt,0,sizeof cnt);
    __typeof(block.begin()) it=block.lower_bound(l);
    while (it!=block.end() && it->l<=r) {
        toDel.push_back(*it);
        it++;
    }
    FORE(it,toDel) block.erase(*it);
    FORE(it,toDel) cnt[it->ch-'a']+=it->r-it->l+1;
    int tmp=l;
    if (t) {
        REP(i,26) if (cnt[i]>0) {
            block.insert(Block(i+'a',tmp,tmp+cnt[i]-1));
            tmp+=cnt[i];
        }
    } else {
        FORD(i,25,0) if (cnt[i]>0) {
            block.insert(Block(i+'a',tmp,tmp+cnt[i]-1));
            tmp+=cnt[i];
        }
    }
}
void process(void) {
    REP(love,q) {
        int l,r,t;
        scanf("%d%d%d",&l,&r,&t);
        query(l,r,t);
    }
    FORE(it,block) REP(love,it->r-it->l+1) printf("%c",it->ch);
    printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}