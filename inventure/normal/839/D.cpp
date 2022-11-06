#include <bits/stdc++.h>

using namespace std;

namespace Poly{
    struct Complex{
        double r , c;
        Complex( double r = 0 , double c = 0 ) : r( r ) , c( c ){}
        friend Complex operator + ( const Complex & x , const Complex & y ){
            return Complex( x.r + y.r , x.c + y.c );
        }
        friend Complex operator * ( const Complex & x , const Complex & y ){
            return Complex( x.r * y.r - x.c * y.c , x.r * y.c + y.r * x.c );
        }
        friend Complex operator - ( const Complex & x , const Complex & y ){
            return Complex( x.r - y.r , x.c - y.c );
        }
        Complex Conj(){
            return Complex( this->r , -this->c );
        }
    };

    const static int maxn = 1 << 19;
    const double pi = acos( -1 );
    const int mod = 1e9 + 7;

    Complex w1[maxn] , w2[maxn] , fr[maxn] , fw[maxn] , A[maxn] , B[maxn] , C[maxn] , D[maxn];

    int power( int x , int y ){
        int ret = 1;
        while( y ){
            if( y & 1 )
                ret = 1LL * ret * x % mod;
            y >>= 1;
            x = 1LL * x * x % mod;
        }
        return ret;
    }

    void Prepare(){
        for(int i = 0 ; i < maxn ; ++ i)
            w1[i] = w2[i] = Complex( cos( 2 * pi * i / maxn ) , sin( 2 * pi * i / maxn ) ),
            w2[i].c = -w2[i].c;
    }

    void ButterflyTrans( Complex * x , int n ){
        for(int i = 1 , j = n >> 1 ; i < n - 1 ; ++ i ){
            if( i < j )
                swap( x[i] , x[j] );
            int k = n >> 1;
            while( j >= k ){
                j -= k;
                k >>= 1;
            }
            if( j < k)
                j += k;
        }
    }

    void DFT( Complex * x , int n , int on ){
        ButterflyTrans( x , n );
        for(int len = 2 , step = (maxn >> 1) ; len <= n ; len <<= 1 , step >>= 1)
            for(int i = 0 ; i < n ; i += len){
                Complex * base = on > 0 ? w1 : w2;
                for( Complex * l = x + i , * r = x + i + (len >> 1) ; r < x + i + len ; ++ l , ++ r , base += step ){
                    Complex u = *l , v = *r * *base;
                    *l = u + v;
                    *r = u - v;
                }
            }
    }

    void DFT( Complex * x , int n ,  Complex * r1 = A , Complex * r2 = B ){
        DFT( x , n , 1 );
        for(int i = 0 ; i < n ; ++ i){
            int j = ( n - i ) & (n - 1);
            r1[i] = ( x[i] + x[j].Conj() ) * Complex( 0.5 , 0 );
            r2[i] = ( x[i] - x[j].Conj() ) * Complex( 0 , -0.5 );
        }
    }

    void Mul( int * x , int * y , int * z , int n ){
        for(int i = 0 ; i < n ; ++ i){
            fr[i] = Complex( x[i] >> 15 , x[i] & 32767 );
            fw[i] = Complex( y[i] >> 15 , y[i] & 32767 );
        }
        DFT( fr , n , A , B );
        DFT( fw , n , C , D );
        for(int i = 0 ; i < n ; ++ i){
            fr[i] = A[i] * C[i];
            fw[i] = A[i] * D[i] + B[i] * C[i];
            A[i] = B[i] * D[i];
            B[i] = Complex( fr[i].r - fw[i].c , fr[i].c + fw[i].r );
        }
        DFT( B , n , -1 );
        DFT( A , n , -1 );
        for(int i = 0 ; i < n ; ++ i){
            int a = (long long)( B[i].r / n + 0.5 ) % mod;
            int b = (long long)( B[i].c / n + 0.5 ) % mod;
            int c = (long long)( A[i].r / n + 0.5 ) % mod;
            z[i] = ( ((long long)a << 30LL) + ((long long)b << 15LL) + c ) % mod;
        }
    }
};

int Cnt[1000050] , F[1000050] , n , Fac[200050] , Inv[200050];
int a[Poly::maxn] , b[Poly::maxn] , c[Poly::maxn];

inline void Update( int & x , int y ){
	x += y;
	if( x >= Poly:: mod ) x -= Poly::mod;
}

int main( int argc , char * argv[] ){
	Poly::Prepare();
	int mx = 0;
	scanf( "%d" , & n );
	for(int i = 1 ; i <= n ; ++ i){
		int x ;
		scanf( "%d" , & x );
		mx = max( mx , x );
		++ Cnt[x];
	}
	Fac[0] = Inv[0] = 1;
	for(int i = 1 ; i <= n ; ++ i) Fac[i] = 1LL * Fac[i - 1] * i % Poly::mod , Inv[i] = Poly::power( Fac[i] , Poly::mod - 2 );
	for(int i = 0 ; i <= n ; ++ i) a[i] = 1LL * i * Inv[i] % Poly::mod , b[i] = Inv[i];
	int l = 1;
	while( l < 2 * n + 1 ) l <<= 1;
	Poly::Mul( a , b , c , l );
	for(int i = 0 ; i <= n ; ++ i) c[i] = 1LL * c[i] * Fac[i] % Poly::mod;
	for(int i = 1 ; i <= mx ; ++ i)
		for(int j = i ; j <= mx ; j += i)
			F[i] += Cnt[j];
	for(int i = 1 ; i <= mx ; ++ i) F[i] = c[F[i]];
	for(int i = mx ; i >= 1 ; -- i)
		for(int j = i + i ; j <= mx ; j += i)
			Update( F[i] , Poly::mod - F[j] );
	int ans = 0;
	for(int i = 2 ; i <= mx ; ++ i) Update( ans , 1LL * F[i] * i % Poly::mod );
	printf( "%d\n" , ans );
	return 0;
}