#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define fwd(i,a,b) for(int i=a;i<(b);i++)
#define all(X) (X).begin(),X.end()
#define sz(X) (int)(X.size())
#define st first
#define nd second
#define pii pair<int,int>
#define int long long
typedef  long long ll;


#ifdef LOCAL
ostream &operator<<(ostream &out, string str){
    for(char c:str)
        out<<c;
    return out;
}

template<class T,class U> ostream& operator<< (ostream &out, pair<T,U> a) {
    return out<<'('<<a.st<<','<<a.nd<<')';
}

template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(),out){
    out<<'{';
    for(auto b:a){
        out<<b<<", ";
    }
    return out<<'}';
}

void dump(){cerr<<"\n";}
template<class T,class... Ts> void dump(T a, Ts... x){
    cerr<<a<<", ";
    dump(x...);
}
#define debug(...) cerr<<"[" #__VA_ARGS__ "]: ",dump(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void manacher(vector<int>&w,int n, vector<int>&p, int sh){
    int g=0;
    p[0]=1-sh;
    for(int i=1;i<n;i++){
        p[i]=2*g-i>=0 ? max(min(p[2*g-i],p[g]+g-1),0ll) : 0;
        while(i>=p[i]+sh && i+p[i]<n && w[i+p[i]]==w[i-p[i]-sh]) p[g=i]++;
    }
}
int get(int a,int b, int m){
    int c=a+b;

    return c%2==0  ? c/2 : (c+m)/2;

}

int32_t main(){
    int n,m;
    cin>>n>>m;
    debug(n,m);


    vector<int>A;

    rep(i,n){
        int a;
        cin>>a;
        debug(a);
        A.push_back(a);
    }
    sort(all(A));
    rep(i,n) A.push_back(A[i]+m);

    vector<int>X;
    rep(i,sz(A)){
        X.push_back(0);
        if(i!=sz(A)-1)
            X.push_back(A[i+1]-A[i]);
    }
    debug(X);

    vector<int>p(sz(X));
    manacher(X,sz(X),p,0);
    debug(X,p);

    set<int>S;

    rep(i,sz(X)){
        int r=i/2;
        int val=(i%2==0) ? 2*A[r] : A[r]+A[r+1];
        val%=m;
        int k=p[i];
        if(k>=n) S.insert(val);
    }

    cout<<sz(S)<<endl;
    for(int s:S)
        cout<<s<<" ";
    
}