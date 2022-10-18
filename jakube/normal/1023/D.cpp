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

struct S
{
    int val, l, r;
};

class SegmentTreeRecLazy
{
public:
    SegmentTreeRecLazy(int n) : n(n)
    {
        data.assign(4 * n, 0);
        todo.assign(4 * n, 0);
    }

    SegmentTreeRecLazy(std::vector<int> const& v) {
        n = v.size();
        data.assign(4 * n, 0);
        todo.assign(4 * n, 0);
        build(v);
    }

    void build(std::vector<int> const& v, int id = 1, int l = 0, int r = -1) {
        if (r == -1)
            r = n;

        if (l == r - 1) {
            data[id] = v[l];
        } else {
            int m = (l + r) >> 1;
            build(v, id << 1, l, m);
            build(v, id << 1 | 1, m, r);
            data[id] = std::min(data[id << 1], data[id << 1 | 1]);
        }
    }

    int minimum(int x, int y, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
            return std::numeric_limits<int>::max();
        } else if (x <= l && r <= y) {
            return data[id];
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            return std::min(minimum(x, y, id << 1, l, m),
                            minimum(x, y, id << 1 | 1, m, r));
        }
    }

    void update(int x, int y, int val, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
        } else if (x <= l && r <= y) {
            data[id] = val;
            todo[id] = val;
        } else {
            push(id, l, r);
            int m = (l + r) >> 1;
            update(x, y, val, id << 1, l, m);
            update(x, y, val, id << 1 | 1, m, r);
            data[id] = std::min(data[id << 1], data[id << 1 | 1]);
        }
    }

private:
    void push(int id, int l, int r)
    {
        if (todo[id] > 0) {
            data[id << 1] = todo[id];
            todo[id << 1] = todo[id];
            data[id << 1 | 1] = todo[id];
            todo[id << 1 | 1] = todo[id];
            todo[id] = 0;
        }
    }

    int n;
    std::vector<int> data, todo;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    Vector<int> v(n);
    cin >> v;
    
    bool largest = false;
    int empty_idx = -1;
    for (auto [i, x] : enumerate(v)) {
        if (x == q)
            largest = true;
        if (x == 0)
            empty_idx = i;
    }
    
    if (!largest && empty_idx == -1) {
        cout << "NO" << '\n';
        return 0;
    }

    Vector<int> first(q + 1, -1), last(q + 1, -1);
    for (auto [i, x] : enumerate(v)) {
        if (first[x] == -1)
            first[x] = i;
        last[x] = i;
    }

    int INF = q + 1;
    for (auto& x : v) {
        if (x == 0)
            x = INF;
    }
    SegmentTreeRecLazy st(v);

    vector<S> rev;
    for (int i = q; i > 0; i--) {
        if (first[i] == -1) continue;
        if (st.minimum(first[i], last[i]+1) < i) {
            cout << "NO" << '\n';
            return 0;
        }
        st.update(first[i], last[i] + 1, i);
        rev.push_back({i, first[i], last[i]});
    }

    rev.push_back({1, 0, n-1});
    reverse(rev.begin(), rev.end());
    
    for (auto s : rev) {
        st.update(s.l, s.r + 1, s.val);
    }

    if (!largest)
        st.update(empty_idx, empty_idx+1, q);

    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        cout << st.minimum(i, i+1) << " ";
    }
    cout << endl;
}