#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

#include<bits/stdc++.h>

using namespace std;

struct wrap
{
    long long val;
    wrap(){}
    wrap(long long val):val(val){}
    operator long long(){return val;}
    template<class Y>
    wrap& operator=(Y y)
    {
        val=(long long)y;
        return *this;
    }
    wrap& operator=(wrap y)
    {
        val=y.val;
        return *this;
    }
};

#define unary(tp,op)  \
tp operator op(wrap w) \
{                      \
    return op w.val;   \
}

#define binary(tp,op)         \
template<class X>              \
tp operator op(X x,wrap y)      \
{                                \
    return (long long)x op y.val; \
}                                 \
template<class Y>                 \
tp operator op(wrap x,Y y)        \
{                                 \
    return x.val op (long long)y; \
}                                 \
tp operator op(wrap x,wrap y)     \
{                                 \
    return x.val op y.val;        \
}

#define assignment(op)   \
template<class X>         \
X& operator op(X&x,wrap y) \
{                          \
    return x op y.val;     \
}                           \
template<class Y>            \
wrap& operator op(wrap&x,Y y) \
{                             \
    x.val op (long long)y;    \
    return x;                  \
}                               \
wrap& operator op(wrap&x,wrap y) \
{                                \
    x.val op y.val;              \
    return x;                    \
}

/// Arithmetic operators
binary(wrap,+)
binary(wrap,-)
 unary(wrap,+)
 unary(wrap,-)
binary(wrap,*)
binary(wrap,/)
binary(wrap,%)
wrap& operator++(wrap& w)
{
    ++w.val;
    return w;
}
wrap operator++(wrap& w,int)
{
    wrap before=w;
    w.val++;
    return before;
}
wrap& operator--(wrap& w)
{
    --w.val;
    return w;
}
wrap operator--(wrap& w,int)
{
    wrap before=w;
    w.val--;
    return before;
}

/// Comparison operators/relational operators
binary(bool,==)
binary(bool,!=)
binary(bool,> )
binary(bool,< )
binary(bool,>=)
binary(bool,<=)

/// Logical operators
 unary(bool,! )
binary(bool,&&)
binary(bool,||)

/// Bitwise operators
 unary(wrap,~ )
binary(wrap,& )
binary(wrap,| )
binary(wrap,^ )
binary(wrap,<<)
binary(wrap,>>)

/// Compound assignment operators
assignment( +=)
assignment( -=)
assignment( *=)
assignment( /=)
assignment( %=)
assignment( &=)
assignment( |=)
assignment( ^=)
assignment(<<=)
assignment(>>=)

istream& operator>>(istream& in,wrap& w)
{
    return in>>w.val;
}

ostream& operator<<(ostream& out,wrap w)
{
    return out<<w.val;
}

typedef wrap ll;
#define int ll

int int_(string s)
{
    int ans=0;
    for (char c:s)
    {
        ans*=2;
        if (c=='1')
            ans++;
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt=0;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n, m;
        cin>>n>>m;
        set<int> del;
        int med=(1<<m)/2 - 1;
        for (int i=0; i<n; i++)
        {
//            cout<<med<<"\n";
            string s;
            cin>>s;
            int x=int_(s);
            del.insert(x);
            if ((x>=med) and (i%2 == 1))
            {
                med--;
                while (del.count(med))
                    med--;
            }
            else if ((x<=med) and (i%2 == 0))
            {
                med++;
                while (del.count(med))
                    med++;
            }
        }
        string ans;
        for (int i=0; i<m; i++)
            ans.pb(char('0' + (med%2))), med/=2;
        reverse(ans.begin(), ans.end());
        cout<<ans<<"\n";
    }
}