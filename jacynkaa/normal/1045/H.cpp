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

const int mod=1e9+7;


int mod_pow(int a, int b){
    if(b==0) return 1;
    if(b%2==0){
        int c=mod_pow(a,b/2);
        return (c*c)%mod;
    }
    return (a*(mod_pow(a,b-1)))%mod;
 
}

const int MAXN=1e5+99;

int pot[MAXN];
int pot_inv[MAXN];

void pre(){
    pot[0]=pot_inv[0]=1;
    for(int i=1;i<MAXN;i++){
        pot[i]=(pot[i-1]*i)%mod;
        pot_inv[i]=mod_pow(pot[i],mod-2);
    }
}

int binom(int a, int b){
    if(a<0 && b<0) return 1;
    return (pot[a]*((pot_inv[b]*pot_inv[a-b])%mod))%mod;
}

int get(string S){
    return (S[0]=='1')*2+(S[1]=='1');
}

vector<int> getv(string S){
    vector<int>X(4);
    rep(i,sz(S)-1)X[get({S[i],S[i+1]})]++;
    return X;
}

int get_all(vector<int> C){
    if(*min_element(all(C))<0) return 0;

  //  debug(C);
    int OI=C[get("01")];
    int IO=C[get("10")];

    if(OI==IO || OI==IO+1){
            int t0=max(OI,IO+1);
            int t1=OI;
            int c11=C[3];
            int c00=C[0];
           // debug(t0,t1,c00,c11);
            return binom(c11+t1-1,t1-1)*binom(c00+t0-1,t0-1);      
    }
    return 0;
}

int solve(string &S, vector<int>C, int idx){
  //  debug(S,C,idx);
    if(*min_element(all(C))<0) return 0;

    int n=sz(S);

    if(idx==n){
        assert(accumulate(all(C),0)==0);
        return 1;
    }

    int A,B;

    //biore to co mam
    {
        auto tmp=C;
        tmp[get({S[idx-1],S[idx]})]--;
        A=solve(S,tmp,idx+1);
    }
    //biore zero
    if(S[idx]!='0')
    {
        auto tmp=C;
        tmp[get({S[idx-1],'0'})]--;
        B=get_all(tmp);
    }

    if(S[idx]=='0'){
        return A;
    }else return (A+B)%mod;
}

int solve(string S, vector<int>C){
    int r=accumulate(all(C),0);

    if(r+1<sz(S)){
      //  debug("HALO");
        swap(C[0],C[3]);
        swap(C[1],C[2]);
        return get_all(C);
    } 
    if(r+1>sz(S)) {
        //debug("00");
        return 0;}
     return(solve(S,C,1));
}

// void test(){
//     debug(solve("10",{0,0,0,0}));
//     const int MAXN=20;
//     int res=0;
//     string S;
//    rep(i,MAXN) S.push_back('1');
//     rep(i,MAXN) rep(j,MAXN) rep(k,MAXN) rep(l,MAXN){
//         res+=solve(S,{i,j,k,l});
//     }
//     debug(res,( (1<<MAXN)-1));

// }



int32_t main(){
    pre();
   // test();
    string A,B;
    cin>>A>>B;
    vector<int>C(4);
    rep(i,4) cin>>C[i];

    auto r = solve(A,C);
    auto q = solve(B,C);
    int c = (getv(A)==C);

    debug(q,r,c);

    cout<< ((q-r+c+mod*mod)%mod)<<endl;
}