#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define MASK(i) (1<<(i))
#define tget(i) ((t[(i)/8]&MASK((i)%8))?1:0)
#define tset(i,b) t[(i)/8]=(b)?(t[(i)/8]|MASK((i)%8)):(t[(i)/8]&(~MASK((i)%8)))
#define chr(i) ((cs==sizeof(int))?((int *)s)[i]:((unc *)s)[i])
#define isLMS(i) ((i)>0 && tget(i) && !tget((i)-1))
#define fi   first
#define se   second
using namespace std;
typedef unsigned char unc;
typedef long long ll;
typedef pair<int,int> ii;
const int mod=(int)1e9+7;
ll comb[MAX],res[MAX];
class SuffixArray {
    public:
    int *sa,*lcp,*rank,n;
    unc *s;
    void getbuckets(unc s[],vector<int> &bkt,int n,int k,int cs,bool end) {
        FOR(i,0,k) bkt[i]=0;
        REP(i,n) bkt[chr(i)]++;
        int sum=0;
        FOR(i,0,k) {
            sum+=bkt[i];
            bkt[i]=end?sum:sum-bkt[i];
        }
    }
    void inducesal(vector<unc> &t,int sa[],unc s[],vector<int> &bkt,int n,int k,int cs,bool end) {
        getbuckets(s,bkt,n,k,cs,end);
        REP(i,n) {
            int j=sa[i]-1;
            if (j>=0 && !tget(j)) sa[bkt[chr(j)]++]=j;
        }
    }
    void inducesas(vector<unc> &t,int sa[],unc s[],vector<int> &bkt,int n,int k,int cs,bool end) {
        getbuckets(s,bkt,n,k,cs,end);
        FORD(i,n-1,0) {
            int j=sa[i]-1;
            if (j>=0 && tget(j)) sa[--bkt[chr(j)]]=j;
        }
    }
    void build(unc s[],int sa[],int n,int k,int cs) {
        int j;
        vector<unc> t=vector<unc>(n/8+1,0);
        tset(n-2,0);
        tset(n-1,1);
        FORD(i,n-3,0) tset(i,(chr(i)<chr(i+1) || (chr(i)==chr(i+1) && tget(i+1)))?1:0);
        vector<int> bkt=vector<int> (k+1,0);
        getbuckets(s,bkt,n,k,cs,true);
        REP(i,n) sa[i]=-1;
        REP(i,n) if (isLMS(i)) sa[--bkt[chr(i)]]=i;
        inducesal(t,sa,s,bkt,n,k,cs,false);
        inducesas(t,sa,s,bkt,n,k,cs,true);
        bkt.clear();
        int n1=0;
        REP(i,n) if (isLMS(sa[i])) sa[n1++]=sa[i];
        FOR(i,n1,n-1) sa[i]=-1;
        int name=0;
        int prev=-1;
        REP(i,n1) {
            int pos=sa[i];
            bool diff=false;
            REP(d,n) {
                if (prev<0 || chr(prev+d)!=chr(pos+d) || tget(prev+d)!=tget(pos+d)) {
                    diff=true;
                    break;
                }
                else if (d>0 && (isLMS(prev+d) || isLMS(pos+d))) break;
            }
            if (diff) {
                name++;
                prev=pos;
            }
            sa[n1+pos/2]=name-1;
        }
        j=n-1;
        FORD(i,n-1,n1) if (sa[i]>=0) sa[j--]=sa[i];
        int *sa1=sa;
        int *s1=sa+n-n1;
        if (name<n1) build((unc *)s1,sa1,n1,name-1,sizeof(int));
        else REP(i,n1) sa1[s1[i]]=i;
        bkt.assign(k+1,0);
        getbuckets(s,bkt,n,k,cs,true);
        j=0;
        REP(i,n) if (isLMS(i)) s1[j++]=i;
        REP(i,n1) sa1[i]=s1[sa1[i]];
        FOR(i,n1,n-1) sa[i]=-1;
        FORD(i,n1-1,0) {
            j=sa[i];
            sa[i]=-1;
            sa[--bkt[chr(j)]]=j;
        }
        inducesal(t,sa,s,bkt,n,k,cs,false);
        inducesas(t,sa,s,bkt,n,k,cs,true);
        bkt.clear();
        t.clear();
    }
    void calc_lcp(void) {
        FOR(i,1,n) rank[sa[i]]=i;
        int h=0;
        REP(i,n) if (rank[i]<n) {
            int j=sa[rank[i]+1];
            while (s[i+h]==s[j+h]) h++;
            lcp[rank[i]]=h;
            if (h>0) h--;
        }
    }
    SuffixArray() {
        n=0;
        sa=NULL;lcp=NULL;rank=NULL;
        s=NULL;
    }
    SuffixArray(string ss) {
        n=ss.size();
        sa=new int[n+7];
        lcp=new int [n+7];
        rank=new int [n+7];
        s=(unc *)ss.c_str();
        build(s,sa,n+1,256,sizeof(char));
        calc_lcp();
//        cerr<<ss<<endl;
//        printf("Suffix Result\n");
//        FOR(i,1,n) cerr << ss.substr(sa[i],ss.size()) << " " << lcp[i] << endl;
    }
    void count(int mode,int lim) {
        set<int> rem;
        vector<ii> pos;
        FOR(i,1,n-1) pos.push_back(ii(lcp[i],i));
        sort(pos.begin(),pos.end());
        rem.insert(0);
        rem.insert(n);
        int j=0;
        ll val=comb[n];
        FOR(i,1,lim) {
            while (j<pos.size() && lcp[pos[j].se]<i) {
                __typeof(rem.begin()) it=rem.insert(pos[j].se).fi;
                __typeof(it) lt=it; lt--;
                __typeof(it) rt=it; rt++;
                val-=comb[*rt-*lt];
                val+=comb[*rt-*it];
                val+=comb[*it-*lt];
                j++;
            }
            res[i]+=mode*val;
        }
    }
};
SuffixArray SA;
string s[3];
int n;
void process(void) {
    REP(i,3) cin>>s[i];
    n=min(s[0].size(),min(s[1].size(),s[2].size()));
    FOR(i,3,MAX-1) comb[i]=1LL*i*(i-1)*(i-2)/6;
    SuffixArray(s[0]+"@"+s[1]+"#"+s[2]).count(1,n);
    SuffixArray(s[0]+"$"+s[1]).count(-1,n);
    SuffixArray(s[1]+"%"+s[2]).count(-1,n);
    SuffixArray(s[2]+"^"+s[0]).count(-1,n);
    SuffixArray(s[0]).count(1,n);
    SuffixArray(s[1]).count(1,n);
    SuffixArray(s[2]).count(1,n);
    FOR(i,1,n) cout<<res[i]%mod<<" ";
}
int main(void) {
    process();
    return 0;
}