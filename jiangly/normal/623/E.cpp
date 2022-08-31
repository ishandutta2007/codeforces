// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int P=1e9+7,N=1<<16;
const long double PI=atan2(0,-1);
class Complex{
private:
long double x,y;
public:
Complex(long double _x=0,long double _y=0):x(_x),y(_y){}
long double &real(){
    return x;
}
long double &imag(){
    return y;
}
friend Complex operator +(const Complex &,const Complex &);
friend Complex operator -(const Complex &,const Complex &);
friend Complex operator *(const Complex &,const Complex &);
friend Complex operator /(const Complex &,long double);
friend ostream &operator <<(ostream &,const Complex &);
};
Complex operator +(const Complex &a,const Complex &b){
    return {a.x+b.x,a.y+b.y};
}
Complex operator -(const Complex &a,const Complex &b){
    return {a.x-b.x,a.y-b.y};
}
Complex operator *(const Complex &a,const Complex &b){
    return {a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
}
Complex operator /(const Complex &a,long double b){
    return {a.x/b,a.y/b};
}
ostream &operator <<(ostream &out,const Complex &a){
    return out<<"("<<a.x<<", "<<a.y<<")";
}
vector<int> rev(N);
vector<Complex> omega(N);
void FFT_Init(){
    for(int i=1;i<N;++i){
        rev[i]=(rev[i>>1]>>1)|((N>>1)*(i&1));
    }
    for(int i=0;i<N;++i){
        omega[i]={cos(2*PI*i/N),sin(2*PI*i/N)};
    }
}
void FFT(vector<Complex> &a){
    for(int i=0;i<N;++i){
        if(rev[i]<i){
            swap(a[i],a[rev[i]]);
        }
    }
    for(int k=2;k<=N;k<<=1){
        vector<Complex> w(k);
        for(int i=0;i<k;++i){
            w[i]=omega[N/k*i];
        }
        for(int i=0;i<N;i+=k){
            Complex u,v;
            for(int j=0;j<(k>>1);++j){
                u=a[i|j];
                v=a[i|j|(k>>1)]*w[j];
                a[i|j]=u+v;
                a[i|j|(k>>1)]=u-v;
            }
        }
    }
}
void IFFT(vector<Complex> &a){
    reverse(a.begin()+1,a.end());
    FFT(a);
    for(int i=0;i<N;++i){
        a[i]=a[i]/N;
    }
}
vector<int> Poly_Mul(const vector<int> &a,const vector<int> &b){
    vector<Complex> c(N),d(N);
    for(int i=0;i<(N>>1);++i){
        c[i]=Complex(a[i]&32767,a[i]>>15);
        d[i]=Complex(b[i]&32767,b[i]>>15);
    }
    FFT(c);
    FFT(d);
    vector<Complex> e(N),f(N);
    for(int i=0;i<N;++i){
        int r=(N-i)&(N-1);
        e[i]=Complex(0.5*(c[i].real()+c[r].real()),0.5*(c[i].imag()-c[r].imag()))*d[i];
        f[i]=Complex(0.5*(c[i].imag()+c[r].imag()),0.5*(c[r].real()-c[i].real()))*d[i];
    }
    IFFT(e);
    IFFT(f);
    vector<int> g(N);
    for(int i=0;i<(N>>1);++i){
        ll x=e[i].real()+0.5,y=e[i].imag()+0.5,z=f[i].real()+0.5,w=f[i].imag()+0.5;
        g[i]=(x+(((y+z)%P)<<15)+((w%P)<<30))%P;
    }
    return g;
}
int Pow(int a,int b){
    int c=1;
    while(b){
        if(b&1){
            c=1ll*c*a%P;
        }
        a=1ll*a*a%P;
        b>>=1;
    }
    return c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    FFT_Init();
    ll n;
    int k;
    cin>>n>>k;
    if(n>k){
        cout<<0<<endl;
        return 0;
    }
    vector<int> a(N),b(N),c(N);
    a[0]=1;
    b[1]=1;
    for(int i=2;i<(N>>1);++i){
        b[i]=1ll*b[i-1]*Pow(i,P-2)%P;
    }
    int x=2;
    while(n){
        if(n&1){
            for(int i=0,j=1;i<(N>>1);++i,j=1ll*j*x%P){
                a[i]=1ll*a[i]*j%P;
            }
            a=Poly_Mul(a,b);
        }
        for(int i=0,j=1;i<(N>>1);++i,j=1ll*j*x%P){
            c[i]=1ll*b[i]*j%P;
        }
        b=Poly_Mul(b,c);
        n>>=1;
        x=1ll*x*x%P;
    }
    int ans=0;
    for(int i=0,j=1;i<=k;j=1ll*j*(k-i)%P,++i){
        ans=(ans+1ll*a[i]*j)%P;
    }
    cout<<ans<<endl;
    return 0;
}