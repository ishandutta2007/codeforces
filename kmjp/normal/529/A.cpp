#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


struct SuffixArray {
    int N; vector<int> rank,lcp,sa; string S;
    
    SuffixArray(string S) : S(S){
        int i,h=0; vector<int> tmp,tr;
        N=S.size(); rank.resize(N+1); sa.resize(N+1); tmp.resize(N+1);
        FOR(i,N+1) sa[i]=i, rank[i]=i==N?-1:S[i];
        
        for(int k=1; k<=N; k<<=1) {
            auto pred2 = [k,this](int& a,int &b)->bool{ return (((a+k<=N)?rank[a+k]:-1)<((b+k<=N)?rank[b+k]:-1));};
            auto pred = [pred2,k,this](int& a,int &b)->bool{ return (rank[a]!=rank[b])?(rank[a]<rank[b]):pred2(a,b);};
            int x=0;
            if(k!=1) for(i=1;i<N+1;i++) if(rank[sa[i]]!=rank[sa[x]]) sort(sa.begin()+x,sa.begin()+i,pred2), x=i;
            sort(sa.begin()+x,sa.end(),pred);
            FOR(i,N+1) tmp[sa[i]]=(i==0)?0:tmp[sa[i-1]]+pred(sa[i-1],sa[i]);
            swap(rank,tmp);
        }
        lcp.resize(N+1); tr.resize(N+1);
        FOR(i,N+1) tr[sa[i]]=i;
        FOR(i,N) {
            int j=sa[tr[i]-1];
            for(h=max(h-1,0);i+h<N && j+h<N; h++) if(S[j+h]!=S[i+h]) break;
            lcp[tr[i]-1]=h;
        }
    }
};

string S;
int L,P;
int score[2500000];
int sd[4500000];
const int OFF=2200000;
int mi=OFF;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>S;
    L=S.size();
    S+=S;
    SuffixArray sa(S);
    
    FOR(i,L) {
        score[i+1]=score[i] + ((S[i]=='(')?1:-1);
        sd[OFF+score[i+1]]++;
        mi=min(mi,OFF+score[i+1]);
    }
    int dif=score[L];
    int ret=-1;
    FOR(i,L) {
        if((mi-OFF)-score[i] >= min(0,dif) && (ret == -1 || sa.rank[i]<=sa.rank[ret])) ret = i;
        
        score[i+L+1]=score[i+L] + ((S[i+L]=='(')?1:-1);
        sd[OFF+score[i+L+1]]++;
        mi=min(mi,OFF+score[i+L+1]);
        if(--sd[OFF+score[i+1]]==0 && mi==OFF+score[i+1]) mi += (sd[OFF+score[i+1]-1])?-1:1;
    }
    
    if(dif<0) cout<<string(-dif,'(');
    cout<<S.substr(ret,L);
    if(dif>0) cout<<string(dif,')');
    cout<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}