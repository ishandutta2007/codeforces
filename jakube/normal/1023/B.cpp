#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define OP operator
#define op(O) auto&OP O##=(int x){for(T&v:*this)v O##=x;return *this;}auto OP O(int x){auto c=*this;c O##= x;return c;}
#define stream(TYPE,O,X,CLS) friend TYPE& OP O(TYPE& s,CLS&v){int b=0;for(auto&x:v){if(b)X;b=1;s O x;}return s;}
#define acc(NAME,INIT,O) friend T NAME(Vector&v){T r= INIT;for (auto& x: v) O;return r;}
template<class T>struct Vector:vector<T>{
    Vector(int n,T i=0):vector<T>(n,i){}
    op(>>)op(&)op(<<)op(|)op(+)op(-)op(*)op(/)stream(istream,>>,,Vector)stream(ostream,<<,s<<' ',Vector)
    acc(sum,0,r+=x)acc(min,numeric_limits<T>::max(),r=min(r,x))acc(max,0,r=max(r,x))acc(prod,1,r*=1)
};
template <class T>struct Matrix:Vector<Vector<T>>{
    Matrix(int n, int m, T i=0):Vector<Vector<T>>(n,Vector<T>(m,i)){}
    stream(istream,>>,,Matrix)stream(ostream,<<,s<<'\n',Matrix)
};
#define ENUM(NAME,IT,A,B,C,D) template<class T>struct NAME{struct it{int i;typename T::IT t;auto OP*(){return pair(i,*t);}it&OP++(){i++;t++;return*this;}bool OP==(it const& other){return t==other.t;}bool OP!=(it const& other){return t!=other.t;}};T& c;NAME(T&e):c(e){}it begin(){return{A,B};}it end(){return{C,D};}};
ENUM(enumerate,iterator,0,c.begin(),(int)c.size(),c.end())ENUM(rev_enumerate,reverse_iterator,(int)c.size()-1,c.rbegin(),-1,c.rend())

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    long long mi_left = max(1LL, k - n);
    long long ma_left = min(n, (k - 1) / 2);
    cout << max(0LL, ma_left + 1 - mi_left) << '\n';
}