#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const char yes[]="YES";
const char no[]="NO";
struct Song {
    int l,r,id;
    Song() {
        l=r=id=0;
    }
    void input(int i) {
        id=i;
        scanf("%d%d",&l,&r);
    }
    bool operator < (const Song &s) const {
        return (r<s.r);
    }
};
struct Singer {
    int l,r,lim,id;
    Singer() {
        l=r=lim=id=0;
    }
    void input(int i) {
        id=i;
        scanf("%d%d%d",&l,&r,&lim);
    }
    bool operator < (const Singer &s) const {
        return (r==s.r?l>s.l:r<s.r);
    }
};
Song song[MAX];
Singer singer[MAX];
int nSong,nSinger;
int res[MAX];
void init(void) {
    scanf("%d",&nSong);
    FOR(i,1,nSong) song[i].input(i);
    sort(song+1,song+nSong+1);
    scanf("%d",&nSinger);
    FOR(i,1,nSinger) singer[i].input(i);
    sort(singer+1,singer+nSinger+1);
}
void process(void) {
    int j=1;
    set<pair<int,int> > rem;
    FOR(i,1,nSinger) {
        while (j<=nSong && song[j].r<=singer[i].r) {
            rem.insert(make_pair(song[j].l,song[j].id));
            j++;
        }
        REP(zz,singer[i].lim) {
            if (rem.empty()) break;
            __typeof(rem.begin()) it=rem.lower_bound(make_pair(singer[i].l,-1));
            if (it==rem.end()) break;
            res[it->se]=singer[i].id;
            rem.erase(it);
        }
    }
    while (j<=nSong) {
        rem.insert(make_pair(song[j].l,song[j].id));
        j++;
    }
    if (!rem.empty()) {
        printf("%s",no);
        return;
    }
    printf("%s\n",yes);
    FOR(i,1,nSong) printf("%d ",res[i]); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}