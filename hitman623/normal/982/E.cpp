#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int gcd(int a,int b,int &x,int &y){
    if(a==0){
        x=0,y=1;
        return b;
    }
    int x1,y1;
    int d=gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}
bool find_any_solution(int a,int b,int c,int& l,int& k,int& g){
    g=gcd(abs(a),abs(b),l,k);
    if(c%g!=0){
        return false ;
    }
    l*=c/g;
    k*=c/g;
    if(a<0) l*=-1;
    if(b<0) k*=-1;
    return true;
}
void solve(){
    int n,m,x,y,vx,vy;
    cin>>n>>m>>x>>y>>vx>>vy;
    if(!vx){
        if(x==0 || x==n){
            cout<<x<<" ";
            if(vy==1) cout<<m<<endl;
            else cout<<0<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        return;
    }
    if(!vy){
        if(y==0 || y==m){
            if(vx==1) cout<<n<<" ";
            else cout<<0<<" ";
            cout<<y<<" ";
        }
        else{
            cout<<-1<<endl;
        }
        return;
    }
    int a=2*n*vy,b=-2*m*vx,c=x*vy-y*vx,l,k,g;
    set<pair<double,int>> ans;
    if(find_any_solution(a,b,c,l,k,g)){
        int dx=abs(2*n*b/g);
        double X=2.0*n*l;        
        while((X-x)*vx<0) X+=vx*dx;
        while((X-x-vx*dx)*vx>0) X-=vx*dx;
        ans.insert({(X-x)*vx,0});
    }
    c-=n*vy;
    if(find_any_solution(a,b,c,l,k,g)){
        int dx=abs(2*n*b/g);
        double X=2.0*n*l+n;        
        while((X-x)*vx<0) X+=vx*dx;
        while((X-x-vx*dx)*vx>0) X-=vx*dx;
        ans.insert({(X-x)*vx,2});
    }
    c+=m*vx;
    if(find_any_solution(a,b,c,l,k,g)){
        int dx=abs(2*n*b/g);
        double X=2.0*n*l+n;        
        while((X-x)*vx<0) X+=vx*dx;
        while((X-x-vx*dx)*vx>0) X-=vx*dx;
        ans.insert({(X-x)*vx,3});
    }
    c+=n*vy;
    if(find_any_solution(a,b,c,l,k,g)){
        int dx=abs(2*n*b/g);
        double X=2.0*n*l;
        while((X-x)*vx<=0) X+=vx*dx;
        while((X-x-vx*dx)*vx>0) X-=vx*dx;
        ans.insert({(X-x)*vx,1});
    }
    if(sz(ans)){
        int d=(*ans.begin()).y;
        cout<<(d/2)*n<<" "<<(d%2)*m<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

signed main(){
    cout<<fixed<<setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}