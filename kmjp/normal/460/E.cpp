#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,R;
vector<pair<int,int> > V,V2;
int mat[1000][1000];
int ma,st[10],be[10];

void dfs(int cur,int pos,int sum) {
    int i,j;
    if(cur==N) {
        if(sum>ma) {
            ma=sum;
            FOR(i,N) be[i]=st[i];
        }
        return;
    }
    
    for(i=pos;i<V.size();i++) {
        int nsum=sum;
        FOR(j,cur) nsum+=mat[st[j]][i];
        st[cur]=i;
        dfs(cur+1,i,nsum);
    }
}

ll veccross(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3) {
    p3.first-=p1.first;p2.first-=p1.first;
    p3.second-=p1.second;p2.second-=p1.second;
    return p3.first*(ll)p2.second-p2.first*(ll)p3.second;
}
vector<int> convex_hull(vector< pair<int, int> >& vp) {
    vector<pair<pair<int, int>, int> > sorted;
    vector<int> res;
    int i,k=0,rb;
    
    if(vp.size()<=2) {
        if(vp.size()>=1) res.push_back(0);
        if(vp.size()>=2) res.push_back(1);
        return res;
    }
    
    FOR(i,vp.size()) sorted.push_back(make_pair(vp[i],i));
    sort(sorted.begin(),sorted.end());
    res.resize(vp.size()*2);
    /* bottom */
    FOR(i,vp.size()) {
        while(k>1 && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=0) k--;
        res[k++]=sorted[i].second;
    }
    /* top */
    for(rb=k, i=vp.size()-2;i>=0;i--) {
        while(k>rb && veccross(vp[res[k-2]],vp[res[k-1]],sorted[i].first)<=0) k--;
        res[k++]=sorted[i].second;
    }
    res.resize(k-1);
    return res;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>R;
    FOR(i,R+1) {
        y=0;
        while((y+1)*(y+1)+i*i<=R*R) y++;
        V2.push_back(make_pair(i,y));
        V2.push_back(make_pair(i,-y));
        V2.push_back(make_pair(-i,y));
        V2.push_back(make_pair(-i,-y));
    }
    sort(V2.begin(),V2.end());
    V2.erase(unique(V2.begin(),V2.end()),V2.end());
    vector<int> VV;
    VV=convex_hull(V2);
    FOR(i,VV.size()) V.push_back(V2[VV[i]]);
    
    FOR(i,V.size()) FOR(j,V.size()) mat[i][j]=(V[i].first-V[j].first)*(V[i].first-V[j].first)+(V[i].second-V[j].second)*(V[i].second-V[j].second);
    
    dfs(0,0,0);
    
    
    _P("%d\n",ma);
    FOR(i,N) _P("%d %d\n",V[be[i]].first,V[be[i]].second);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}