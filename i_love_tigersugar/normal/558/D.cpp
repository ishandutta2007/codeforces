#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define MASK(i) (1LL<<(i))
#define fi   first
#define se   second
using namespace std;
const string err="Game cheated!";
const string need="Data not sufficient!";
int h,q;
vector<pair<long long,long long> > inSeg,outSeg;
long long firstLeaf(long long x,int t) {
    long long each=MASK(h-1)/MASK(t-1);
    long long prev=x-MASK(t-1);
    return (prev*each+MASK(h-1));
}
long long lastLeaf(long long x,int t) {
    long long each=MASK(h-1)/MASK(t-1);
    return (firstLeaf(x,t)+each-1);
}
vector<pair<long long,long long> > joinSeg(vector<pair<long long,long long> > v) {
    if (v.empty()) return (vector<pair<long long,long long> > ());
    sort(ALL(v));
    vector<pair<long long,long long> > res;
    FORE(it,v) {
        if (!res.empty() && res.back().se>=it->fi) res.back().se=max(res.back().se,it->se);
        else res.push_back(*it);
    }
    return (res);
}
void process(void) {
    cin>>h>>q;
    inSeg.push_back(make_pair(MASK(h-1),MASK(h)-1));
    REP(love,q) {
        int t,ans;
        long long l,r;
        cin>>t>>l>>r>>ans;
        if (ans) inSeg.push_back(make_pair(firstLeaf(l,t),lastLeaf(r,t)));
        else outSeg.push_back(make_pair(firstLeaf(l,t),lastLeaf(r,t)));
    }
    long long minRange=inSeg[0].fi;
    long long maxRange=inSeg[0].se;
    FORE(it,inSeg) {
        minRange=max(minRange,it->fi);
        maxRange=min(maxRange,it->se);
    }
    if (minRange>maxRange) {
        cout<<err<<endl;
        return;
    }
    outSeg=joinSeg(outSeg);
    long long numAns=maxRange-minRange+1;
    FORE(it,outSeg) {
        long long L=max(it->fi,minRange);
        long long R=min(it->se,maxRange);
        if (L<=R) numAns-=R-L+1;
    }
    if (numAns==0) {
        cout<<err<<endl;
        return;
    }
    if (numAns>1) {
        cout<<need<<endl;
        return;
    }
    if (minRange==maxRange) {
        cout<<minRange<<endl;
        return;
    }
    if (minRange<=outSeg.front().fi-1 && outSeg.front().fi-1<=maxRange) {
        cout<<outSeg.front().fi-1<<endl;
        return;
    }
    if (minRange<=outSeg.back().se+1 && outSeg.back().se+1<=maxRange) {
        cout<<outSeg.back().se+1<<endl;
        return;
    }
    REP(i,(int)outSeg.size()-1) if (outSeg[i].se+1<outSeg[i+1].fi) {
        if (minRange<=outSeg[i].se+1 && outSeg[i].se+1<=maxRange) {
            cout<<outSeg[i].se+1<<endl;
            return;
        }
        if (minRange<=outSeg[i+1].fi-1 && outSeg[i+1].fi-1<=maxRange) {
            cout<<outSeg[i+1].fi-1<<endl;
            return;
        }
    }
    assert(false);
}
int main(void) {
    process();
    return 0;
}