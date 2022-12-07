#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
// #include<complex>
#define pii                   pair<int,int>
#define tii                   pair<int,pair<int,int> >
#define mkp                   make_pair
#define fs                    first
#define sc                    second
#define pb                    push_back
#define ppb                   pop_back()
#define pcase(x)              printf("Case %d: ",x)
#define hi                    cout<<"hi"<<endl;
#define mod                   1000000007
#define inf                   1000000007
#define pi                    acos(-1.0)
#define mem(arr,x)            memset((arr), (x), sizeof((arr)));
#define FOR(i,x)              for(int i=0;i<(x); i++)
#define FOR1(i,x)             for(int i = 1; i<=(x) ; i++)
#define jora(a,b)             make_pair(a,b)
#define tora(a,b,c)           jora(a,jora(b,c))
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define pf1ll(a)              printf("%lld\n",a);
#define N 5*100000+5
#define level 26
#define eps 1e-9
// #define noya vector< vector<int> >(6,vector<int>(6,0))
// #define mat vector<vector<int> >
// #define m 6
using namespace std;
typedef long long lint;
 
struct complex{
    double r,v;
    complex(double a=0,double b=0):r(a),v(b){}
    inline complex operator+(const complex& b){return complex(r+b.r,v+b.v);}
    inline complex operator-(const complex& b){return complex(r-b.r,v-b.v);}
    inline complex operator*(const complex& b){return complex(r*b.r-v*b.v,v*b.r+r*b.v);}
};
typedef complex base;
//inline void swap(complex& a,complex& b){complex t(a);a=b;b=t;}
 
void fft (vector<complex> & a, bool invert) {
    int n = (int) a.size();
 
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
 
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*pi/len * (invert ? -1 : 1);
        complex wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            complex w (1);
            for (int j=0; j<len/2; ++j) {
                complex u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w =w* wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i].r =a[i].r / n;
}
void multiply (const vector<lint> & a, const vector<lint> & b, vector<lint> & res) {
    vector<complex> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    size_t n = 1;
    while (n < max (a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize (n),  fb.resize (n);
 
    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] = fa[i]*fb[i];
    fft (fa, true);
 
    res.resize (n);
    for (size_t i=0; i<n; ++i)
        res[i] = (lint) (fa[i].r + 0.5);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    
	int n, x;
	cin >> n >> x;

	int a[n];
	int m = 0;
	for(int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		if(val < x) {
			a[i] = 1;
			m++;
		}
		else
			a[i] = 0;
	}	

	long long ans0 = 0;
	long long cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] == 0)
			cnt++;
		else {
			long long cans0 = cnt * (cnt + 1LL) / 2LL;
			ans0 += cans0;
			cnt = 0;
		}
	}
	long long cans0 = cnt * (cnt + 1LL) / 2LL;
	ans0 += cans0;

	vector<long long> l;
	cnt = 0;
	for(int i = 0; i < n; ++i) {
		cnt++;
		if(a[i] == 1) {
			l.push_back(cnt);
			cnt = 0;
		}
	}

	vector<long long> r;
	cnt = 0;
	for(int i = n - 1; i >= 0; --i) {
		cnt++;
		if(a[i] == 1) {
			r.push_back(cnt);
			cnt = 0;
		}
	}

	for(int i = 0; i < m - 1; ++i) {
		l.push_back(0);
		r.push_back(0);
	}

	vector<long long> fin;
	multiply(l, r, fin);

	cout << ans0 << " ";
	for(int i = m - 1; i >= 0; --i)
		cout << fin[i] << " ";
	for(int i = m + 1; i <= n; ++i)
		cout << "0 ";

    return 0;
}