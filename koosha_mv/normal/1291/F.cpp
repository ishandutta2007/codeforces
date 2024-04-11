#include <bits/stdc++.h>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2050;

int n,k,res,Sz[N];
bool mark[N];
char s;
vector<int> v[N];

void read(){
    cin>>n>>k;
    maxm(k,2);
    f(i,n,2*n)
        Sz[i]=1,v[i].pb(i-n+1);
}
void ask(int x){
    cout<<"? "<<x<<endl;
    cin>>s;
    res=(s=='N');
}
void clear(){
    cout<<"R"<<endl;
}
void solve(int x){
    int c1=x*2,c2=x*2+1;
    fill(mark,mark+N,1);
    Sz[x]=Sz[c1]*2;
    if(Sz[x]<k){
        f(i,0,sz(v[c1]))
            v[x].pb(v[c1][i]);
        f(i,0,sz(v[c2]))
            v[x].pb(v[c2][i]);
        return ;
    }
    if(Sz[x]==k){
        clear();
        f(i,0,sz(v[c1])){
            ask(v[c1][i]);
            if(res) v[x].pb(v[c1][i]);
        }
        f(i,0,sz(v[c2])){
            ask(v[c2][i]);
            if(res) v[x].pb(v[c2][i]);
        }
        return ;
    }
    
    int e=Sz[x]/k;
    vector<vector<int> > p1(e),p2(e);
   f(i,0,sz(v[c1])){
        p1[i/(k/2)].pb(v[c1][i]);
		v[x].pb(v[c1][i]);
	}
    f(i,0,sz(v[c2]))
        p2[i/(k/2)].pb(v[c2][i]);
    f(i,0,e)
        f(j,0,e){
            clear();
            f(l,0,sz(p1[i]))
                ask(p1[i][l]);
            f(l,0,sz(p2[j])){
                ask(p2[j][l]);
                if(!res) mark[p2[j][l]]=0;
            }
        }
    f(i,0,sz(v[c2]))
        if(mark[v[c2][i]])
            v[x].pb(v[c2][i]);
}
void do_it(){
    f_(i,n-1,1)
        solve(i);
    cout<<"! "<<sz(v[1])<<endl;
}

int main(){
    read();
    do_it();
}