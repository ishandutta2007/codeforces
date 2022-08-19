#include<bits/stdc++.h>
using namespace std;
template<typename T>
constexpr T inverse(T a,T m){
    T u=0,v=1;
    while(a!=0){
        T t=m/a;
        m-=t*a;
        swap(a,m);
        u-=t*v;
        swap(u,v);
    }
    assert(m==1);
    return u;
}
template<int MOD>
class ModInt{
    private:
        int value;
    public:
        constexpr ModInt():value(0){}
        template<typename T>
        constexpr ModInt(const T &x):value(normalize(x)){}
        template<typename T>
        constexpr static int normalize(const T &x){
            int v=0;
            if(-MOD<=x&&x<MOD){
                v=static_cast<int>(x);
            }else{
                v=static_cast<int>(x%MOD);
            }
            if(v<0){
                v+=MOD;
            }
            return v;
        }
        constexpr const int & operator () () const {
            return value;
        }
        template<typename T>
        explicit operator T() const {
            return static_cast<T>(this->value);
        }
        constexpr ModInt & operator += (const ModInt &a){
            if((this->value+=a.value)>=MOD){
                this->value-=MOD;
            }
            return *this;
        }
        constexpr ModInt & operator -= (const ModInt &a){
            if((this->value-=a.value)<0){
                this->value+=MOD;
            }
            return *this;
        }
        template<typename T>
        constexpr ModInt & operator += (const T &a){
            return *this+=ModInt(a);
        }
        template<typename T>
        constexpr ModInt & operator -= (const T &a){
            return *this-=ModInt(a);
        }
        constexpr ModInt & operator ++ (){
            return *this+=1;
        }
        constexpr ModInt & operator -- (){
            return *this-=1;
        }
        constexpr ModInt operator ++ (int){
            ModInt a(*this);
            *this+=1;
            return a;
        }
        constexpr ModInt operator -- (int){
            ModInt a(*this);
            *this-=1;
            return a;
        }
        constexpr ModInt operator - () const {
            return ModInt(-this->value);
        }
        constexpr ModInt & operator *= (const ModInt &a){
            this->value=normalize(static_cast<int64_t>(this->value)*static_cast<int64_t>(a.value));
            return *this;
        }
        constexpr ModInt & operator /= (const ModInt &a){
            *this*=ModInt(inverse(a.value,MOD));
        }
        template<int _MOD>
        friend constexpr bool operator == (const ModInt<_MOD> &,const ModInt<_MOD> &);
        template<int _MOD>
        friend std::istream & operator >> (std::istream &,ModInt<_MOD> &);
};
template<int MOD>
constexpr bool operator == (const ModInt<MOD> &a,const ModInt<MOD> &b){
    return a.value==b.value;
}
template<int MOD,typename T>
constexpr bool operator == (const ModInt<MOD> &a,const T &b){
    return a==ModInt<MOD>(b);
}
template<int MOD,typename T>
constexpr bool operator == (const T &a,const ModInt<MOD> &b){
    return ModInt<MOD>(a)==b;
}
template<int MOD>
constexpr bool operator != (const ModInt<MOD> &a,const ModInt<MOD> &b){
    return !(a==b);
}
template<int MOD,typename T>
constexpr bool operator != (const ModInt<MOD> &a,const T &b){
    return !(a==b);
}
template<int MOD,typename T>
constexpr bool operator != (const T &a,const ModInt<MOD> &b){
    return !(a==b);
}
template<int MOD>
constexpr ModInt<MOD> operator + (const ModInt<MOD> &a,const ModInt<MOD> &b){
    return ModInt<MOD>(a)+=b;
}
template<int MOD,typename T>
constexpr ModInt<MOD> operator + (const ModInt<MOD> &a,const T &b){
    return ModInt<MOD>(a)+=b;
}
template<int MOD,typename T>
constexpr ModInt<MOD> operator + (const T &a,const ModInt<MOD> &b){
    return ModInt<MOD>(a)+=b;
}
template<int MOD>
constexpr ModInt<MOD> operator - (const ModInt<MOD> &a,const ModInt<MOD> &b){
    return ModInt<MOD>(a)-=b;
}
template<int MOD,typename T>
constexpr ModInt<MOD> operator - (const ModInt<MOD> &a,const T &b){
    return ModInt<MOD>(a)-=b;
}
template<int MOD,typename T>
constexpr ModInt<MOD> operator - (const T &a,const ModInt<MOD> &b){
    return ModInt<MOD>(a)-=b;
}
template<int MOD>
constexpr ModInt<MOD> operator * (const ModInt<MOD> &a,const ModInt<MOD> &b){
    return ModInt<MOD>(a)*=b;
}
template<int MOD,typename T>
constexpr ModInt<MOD> operator * (const ModInt<MOD> &a,const T &b){
    return ModInt<MOD>(a)*=b;
}
template<int MOD,typename T>
constexpr ModInt<MOD> operator * (const T &a,const ModInt<MOD> &b){
    return ModInt<MOD>(a)*=b;
}
template<int MOD>
constexpr ModInt<MOD> operator / (const ModInt<MOD> &a,const ModInt<MOD> &b){
    return ModInt<MOD>(a)/=b;
}
template<int MOD,typename T>
constexpr ModInt<MOD> operator / (const ModInt<MOD> &a,const T &b){
    return ModInt<MOD>(a)/=b;
}
template<int MOD,typename T>
constexpr ModInt<MOD> operator / (const T &a,const ModInt<MOD> &b){
    return ModInt<MOD>(a)/=b;
}
template<int MOD>
constexpr ModInt<MOD> power(const ModInt<MOD> &a,const int &b){
    ModInt<MOD> x=a,res=1;
    int p=b;
    while(p>0){
        if(p&1){
            res*=x;
        }
        x*=x;
        p>>=1;
    }
    return res;
}
template<int MOD>
constexpr std::string to_string(const ModInt<MOD> &a){
    return to_string(a());
}
template<int MOD>
std::ostream & operator << (std::ostream &stream,const ModInt<MOD> &a){
    return stream<<a();
}
template<int MOD>
std::istream & operator >> (std::istream &stream,ModInt<MOD> &a){
    int x;
    stream>>x;
    a.value=ModInt<MOD>::normalize(x);
    return stream;
}
template<int MOD>
constexpr ModInt<MOD> findRoot(){
    int x=(MOD-1)&(1-MOD);
    ModInt<MOD> root=1;
    while(!(power(root,x)==1&&power(root,x/2)!=1)){
        ++root;
    }
    return root;
}
template<int MOD>
class Polynomial{
    using Int=ModInt<MOD>;
    private:
        std::vector<Int> value;
    public:
        constexpr static size_t MAX_SIZE=(MOD-1)&(1-MOD);
        constexpr static Int ROOT=findRoot<MOD>();
        constexpr Polynomial():value{0}{}
        Polynomial(const std::vector<Int> &a):value(a){}
        Polynomial(const std::initializer_list<Int> &list):value(list){}
        constexpr size_t size() const {
            return value.size();
        }
        constexpr auto begin(){
            return value.begin();
        }
        constexpr auto end(){
            return value.end();
        }
        template<class T>
        void resize(const T &n){
            return value.resize(n);
        }
        template<typename T>
        constexpr const Int & operator [] (const T &index) const {
            return value[index];
        }
        template<typename T>
        constexpr Int & operator [] (const T &index){
            return value[index];
        }
        constexpr Polynomial operator += (const Polynomial &a){
            if(a.size()>value.size()){
                value.resize(a.size());
            }
            for(int i=0;i<a.size();++i){
                value[i]+=a[i];
            }
            return *this;
        }
        constexpr Polynomial operator -= (const Polynomial &a){
            if(a.size()>value.size()){
                value.resize(a.size());
            }
            for(int i=0;i<a.size();++i){
                value[i]-=a[i];
            }
            return *this;
        }
        Polynomial operator *= (const Polynomial &a){
            return *this=*this*a;
        }
        template<int _MOD>
        friend constexpr Polynomial<_MOD> operator + (Polynomial<_MOD>,const Polynomial<_MOD> &);
        template<int _MOD>
        friend constexpr Polynomial<_MOD> operator - (Polynomial<_MOD>,const Polynomial<_MOD> &);
        template<int _MOD>
        friend Polynomial<_MOD> operator * (Polynomial<_MOD>,Polynomial<_MOD>);
};
template<int MOD>
void bitReverse(Polynomial<MOD> &a){
    static vector<int> bitrev;
    if(bitrev.size()!=a.size()){
        int k=__builtin_ctz(a.size());
        bitrev.resize(a.size());
        bitrev[0]=0;
        for(int i=1;i<a.size();++i){
            bitrev[i]=bitrev[i>>1]>>1|((i&1)<<(k-1));
        }
    }
    for(int i=0;i<a.size();++i){
        if(bitrev[i]<i){
            swap(a[i],a[bitrev[i]]);
        }
    }
}
template<int MOD>
void DFT(Polynomial<MOD> &a){
    using Int=ModInt<MOD>;
    bitReverse(a);
    static vector<Int> roots{0,1};
    if(roots.size()<a.size()){
        int k=__builtin_ctz(roots.size());
        roots.resize(a.size());
        while((1<<k)<a.size()){
            int f=power(Polynomial<MOD>::ROOT,Polynomial<MOD>::MAX_SIZE>>(k+1));
            for(int i=1<<(k-1);i<(1<<k);++i){
                roots[2*i]=roots[i];
                roots[2*i+1]=roots[i]*f;
            }
            ++k;
        }
    }
    for(int k=1;k<a.size();k*=2){
        for(int i=0;i<a.size();i+=2*k){
            for(int j=0;j<k;++j){
                Int u=a[i+j];
                Int v=a[i+j+k]*roots[k+j];
                a[i+j]=u+v;
                a[i+j+k]=u-v;
            }
        }
    }
}
template<int MOD>
void IDFT(Polynomial<MOD> &a){
    reverse(a.begin()+1,a.end());
    DFT(a);
    int inv=inverse((int)a.size(),MOD);
    for(int i=0;i<a.size();++i){
        a[i]*=inv;
    }
}
template<int MOD>
constexpr Polynomial<MOD> operator + (Polynomial<MOD> a,const Polynomial<MOD> &b){
    return a+=b;
}
template<int MOD>
constexpr Polynomial<MOD> operator - (Polynomial<MOD> a,const Polynomial<MOD> &b){
    return a-=b;
}
template<int MOD>
Polynomial<MOD> operator * (Polynomial<MOD> a,Polynomial<MOD> b){
    using Int=ModInt<MOD>;
    if(min(a.size(),b.size())<128){
        vector<Int> c(a.size()+b.size()-1);
        for(int i=0;i<a.size();++i){
            for(int j=0;j<b.size();++j){
                c[i+j]+=a[i]*b[j];
            }
        }
        return Polynomial(c);
    }
    int sz=1;
    int x=a.size()+b.size()-1;
    while(sz<x){
        sz<<=1;
    }
    a.resize(sz);
    b.resize(sz);
    DFT(a);
    DFT(b);
    for(int i=0;i<sz;++i){
        a[i]*=b[i];
    }
    IDFT(a);
    a.resize(x);
    return a;
}
using Int=ModInt<998244353>;
using Poly=Polynomial<998244353>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<Int> _a(n),a,b(n);
    for(int i=0;i<n;++i){
        cin>>_a[i];
    }
    int q;
    cin>>q;
    function<Poly(int,int)> work=[&](int l,int r){
        if(r-l==1){
            return Poly{1,b[l]};
        }
        int mid=(l+r)/2;
        return work(l,mid)*work(mid,r);
    };
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int x,y,z;
            cin>>x>>y>>z;
            --y;
            a=_a;
            a[y]=z;
            for(int i=0;i<n;++i){
                b[i]=x-a[i];
            }
        }else{
            int x,l,r,y;
            cin>>x>>l>>r>>y;
            a=_a;
            for(int i=l-1;i<r;++i){
                a[i]+=y;
            }
            for(int i=0;i<n;++i){
                b[i]=x-a[i];
            }
        }
        cout<<work(0,n)[k]<<endl;
    }
    return 0;
}