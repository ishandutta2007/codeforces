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

int N,W,Q;
int L,R;

template<class V, int ME> class BIT {
public:
    V bit[1<<ME];
    V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
    void update(int e, V val) {e++; while(e<=1<<ME) bit[e-1]+=val,e+=e&-e;}
};
BIT<int,20> bt;
int B[100010];

void solve() {
    int f,i,j,k,l,x,y,r;
    cin>>N>>Q;
    L=1, R=N+1;
    
    FOR(i,N) bt.update(i+1,1), B[i+1]=1;
    
    while(Q--) {
        cin>>x;
        if(x==1) {
            cin>>x;
            
            if(L<R) {
                if(2*x<=R-L) {
                    for(i=L;i<L+x;i++) B[L+x+(L+x-1-i)]+=B[i],bt.update(L+x+(L+x-1-i),B[i]);
                    L+=x;
                }
                else {
                    for(i=R-1;i>=L+x;i--) B[L+x-1-(i-(L+x))]+=B[i],bt.update(L+x-1-(i-(L+x)),B[i]);
                    R=L-1;
                    L=L+x-1;
                }
            }
            else {
                if(2*x<=L-R) {
                    for(i=L;i>L-x;i--) B[L-x-(i-(L-x+1))]+=B[i],bt.update(L-x-(i-(L-x+1)),B[i]);
                    L-=x;
                }
                else {
                    for(i=R+1;i<=L-x;i++) B[L-x+1-(i-(L-x))]+=B[i],bt.update(L-x+1-(i-(L-x)),B[i]);
                    R=L+1;
                    L=L-x+1;
                }
            }
        }
        else {
            cin>>l>>r;
            if(L<R) cout<<bt.total(r+L-1)-bt.total(l+L-1)<<endl;
            else cout<<bt.total(L-l)-bt.total(L-r)<<endl;
        }
        
    }
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}