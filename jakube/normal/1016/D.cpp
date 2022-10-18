#include <bits/stdc++.h>
using namespace std;

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

    int n, m;
    cin >> n >> m;
    Vector<int> a(n), b(m);
    cin >> a >> b;
    
    Matrix M(n, m, 0);
    for (int bit = 0; bit < 30; bit++) {
        auto rows = a & 1;
        auto cols = b & 1;
        if ((sum(rows) + sum(cols)) & 1) {
            cout << "NO" << endl;
            return 0;
        }

        int col_idx = 0;
        for (auto [row_idx, x] : enumerate(rows)) {
            if (x) {
                while (col_idx < m - 1 && cols[col_idx] == 0)
                    col_idx++;
                M[row_idx][col_idx] |= 1 << bit;
                cols[col_idx] ^= 1;
            }
        }
        for (auto [idx, x] : enumerate(cols)) {
            if (x)
                M[0][idx] |= 1 << bit;
        }

        a >>= 1;
        b >>= 1;
    }

    cout << "YES" << '\n';
    cout << M << '\n';
}