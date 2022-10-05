#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class UF {
    public:
    static const int ufmax=200052;
    int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
    UF() { init();}
    void init(){int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
    int find(int x) {   return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
    int operator[](int x) {return find(x);}
    int count(int x) {return ufcnt[find(x)];}
    void unite(int x,int y) {
        x = find(x); y = find(y);
        if(x==y) return;
        if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
        else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
    }
};

template<class V, int ME> class BIT {
public:
    V bit[1<<ME];
    V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
    void update(int e, V val) {e++; while(e<=1<<ME) bit[e-1]+=val,e+=e&-e;}
};
BIT<int,20> bt;

int N;
int X1[300000],Y1[300000],X2[300000],Y2[300000];
ll L[300000];
set<int> E, SY;
map<int,vector<pair<int,int> > > H1,V,H2;
UF uf;
set<pair<pair<int,int>,int> > S; // bottom,top,id
map<int,int> Ys;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    Ys[1<<30]=Ys[-1<<30]=0;
    FOR(i,N) {
        cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
        if(X1[i]>X2[i]) swap(X1[i],X2[i]);
        if(Y1[i]>Y2[i]) swap(Y1[i],Y2[i]);
        L[i]=((ll)X2[i])-X1[i]+Y2[i]-Y1[i];
        Ys[Y1[i]]=Ys[Y2[i]]=0;
    }
    
    i=0;
    ITR(it,Ys) it->second=i++;
    
    FOR(i,N) {
        Y1[i]=Ys[Y1[i]];
        Y2[i]=Ys[Y2[i]];
        E.insert(X1[i]);
        E.insert(X2[i]);
        if(X1[i]==X2[i]) V[X1[i]].push_back(make_pair(Y1[i],i));
        if(X1[i]!=X2[i]) H1[X1[i]].push_back(make_pair(Y1[i],i)),H2[X2[i]].push_back(make_pair(Y1[i],i));
    }
    
    ITR(it,E) {
        set<pair<pair<int,int>,int> >::iterator seg,seg2;
        set<int>::iterator sit,sit2;
        pair<pair<int,int>,int> p,p2;
        
        /*
        _P("aa %d::",*it);
        ITR(itit,S) _P("(%d,%d,%d,%lld) ",itit->first.second,itit->first.first,itit->second,L[uf[itit->second]]);
        _P("\n");
        */
        
        ITR(it2,H1[*it]) { // add
            seg=S.lower_bound(make_pair(make_pair(it2->first,0),0));
            if(seg!=S.end() && seg->first.second<=it2->first) { //insert
                p=make_pair(make_pair(0,seg->first.second),seg->second);
                p2=make_pair(make_pair(seg->first.first,0),seg->second);
                S.erase(seg);
                
                sit=SY.lower_bound(it2->first);
                p2.first.second=*sit;
                sit--;
                p.first.first=*sit;
                S.insert(p);
                S.insert(p2);
            }
            
            p=make_pair(make_pair(it2->first,it2->first),it2->second);
            bt.update(it2->first,1);
            SY.insert(it2->first);
            S.insert(p);
        }
        
        /*
        _P("bb %d::",*it);
        ITR(itit,S) _P("(%d,%d,%d,%lld) ",itit->first.second,itit->first.first,itit->second,L[uf[itit->second]]);
        _P("\n");
        */
        
        ITR(it2,V[*it]) { // conn
            seg=S.lower_bound(make_pair(make_pair(Y1[it2->second],0),0));
            seg2=S.lower_bound(make_pair(make_pair(Y2[it2->second],0),0));
            if(seg2!=S.end() && seg2->first.second<=Y2[it2->second]) seg2++;
            if(seg==seg2) continue;
            
            if(seg->first.first>Y2[it2->second] && seg->first.second<Y1[it2->second]) {
                // in single seg
                if(bt.total(Y2[it2->second])-bt.total(Y1[it2->second]-1)==0) continue;
            }
            
            pair<pair<int,int>,int> p=make_pair(make_pair(-1<<30,1<<30),it2->second);
            L[it2->second] -= bt.total(Y2[it2->second])-bt.total(Y1[it2->second]-1);
            
            // conn seg-seg2
            for(; seg!=seg2;) {
                x=uf[p.second]; y=uf[seg->second];
                if(x!=y) L[x]=L[y]=L[x]+L[y]+1, uf.unite(x,y);
                p.first.first=max(p.first.first,seg->first.first);
                p.first.second=min(p.first.second,seg->first.second);
                S.erase(seg++);
            }
            S.insert(p);
        }
        /*
        _P("cc %d::",*it);
        ITR(itit,S) _P("(%d,%d,%d,%lld) ",itit->first.second,itit->first.first,itit->second,L[uf[itit->second]]);
        _P("\n");
        */
        
        ITR(it2,H2[*it]) { // del
            seg=S.lower_bound(make_pair(make_pair(it2->first,0),0));
            p=*seg;
            S.erase(seg);
            bt.update(it2->first,-1);
            SY.erase(it2->first);
            if(p.first.first==p.first.second) continue;
            if(p.first.first==it2->first) {
                sit=SY.lower_bound(it2->first);
                p.first.first=*(--sit);
            }
            else if(p.first.second==it2->first) {
                p.first.second=*SY.lower_bound(it2->first);
            }
            S.insert(p);
            
        }
        /*
        _P("dd %d::",*it);
        ITR(itit,S) _P("(%d,%d,%d,%lld) ",itit->first.second,itit->first.first,itit->second,L[uf[itit->second]]);
        _P("\n");
        */
    }
    
    ll ma=0;
    FOR(i,N) ma=max(ma,L[i]);
    
    cout << ma << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}