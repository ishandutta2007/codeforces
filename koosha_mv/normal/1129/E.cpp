#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=505;

int n,sub[N],par[N];
vector<int> wp;
vector<pair<int,int> > v;

bool check(int u,int x){
	if(!sz(wp)) return 0;
    cout<<x+1<<endl;
    f(i,0,x+1) cout<<wp[i]<<" ";
    cout<<endl<<1<<endl<<1<<endl<<u<<endl;
    int res;
    cin>>res;
    cout<<endl;
    return (0<res);
}
void find_sub(int x){
    cout<<n-1<<endl;
    f(i,2,n+1)
        cout<<i<<" ";
    cout<<endl<<1<<endl<<1<<endl<<x<<endl;
    cin>>sub[x];
    cout<<endl;
    v.pb(mp(sub[x],x));
}
void solve(int x){
    while(check(x,sz(wp)-1)){
        int l=-1,r=sz(wp)-1,mid;
        while(l+1<r){
            mid=(l+r)/2;
            if(check(x,mid)) r=mid;
            else l=mid;
        }
        par[wp[r]]=x;
        wp.erase(wp.begin()+r);
    }
    wp.pb(x);
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    v.pb(mp(n,1));
    f(i,2,n+1)
        find_sub(i);
    sort(v.begin(),v.end());
    f(i,0,n)
        solve(v[i].S);
    cout<<"ANSWER"<<endl;
    f(i,2,n+1)
        cout<<i<<" "<<par[i]<<endl;
}