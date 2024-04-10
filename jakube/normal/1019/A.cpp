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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> parties(m);
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        parties[p-1].push_back(c);
    }
    for (auto& s : parties) {
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
    }
        
    int cnt = parties[0].size();
    long long best_total = std::numeric_limits<long long>::max();
    for (int target = cnt; target <= n; target++) {
        vector<int> others;
        int cur_cnt = cnt;
        long long total = 0;
        for (int i = 1; i < m; i++) {
            for (auto [j, c] : enumerate(parties[i])) {
                if (j < target - 1)
                    others.push_back(c);
                else {
                    total += c;
                    cur_cnt++;
                }
            }
        }
        sort(others.begin(), others.end());
        reverse(others.begin(), others.end());
        while (cur_cnt < target) {
            total += others.back();
            others.pop_back();
            cur_cnt++;
        }
        best_total = min(best_total, total);
    }
    cout << best_total << '\n';
}