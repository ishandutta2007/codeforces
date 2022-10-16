#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

#define INSERT 0
#define ERASE 1

const int MAXN=1e5+99;
map<int,indexed_set>M;
//indexed_set tab[MAXN];


#define tpl tuple<int,int,int,int,int>

int get(int x,int r ,indexed_set &S){
    return sz(S)-S.order_of_key({x-r,-1});
}

int32_t main(){
    int n,k;
    cin>>n>>k;
    vector<tpl>T;
  //  vector<int>res(n);
    rep(i,n){
        int x,r,q;
        cin>>x>>r>>q;
        T.emplace_back(x, INSERT,r,i,q);
        T.emplace_back(x+r,ERASE,r,i,q);
    }
    sort(all(T));

    int res=0;
    for(auto[x,op,r,i,q]:T){
        if(op==INSERT){
            for(int l=q-k;l<=q+k;l++)
            if(M.find(l)!=M.end())
                res+=get(x,r,M[l]);
            M[q].insert({x,i});
        } else{
            M[q].erase({x-r,i});
        }
    }
    debug(M);
    cout<<res<<endl;
}