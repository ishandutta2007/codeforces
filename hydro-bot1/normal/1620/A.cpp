// Hydro submission #61ed28f0742c0134f3ceea9b@1643336076529
#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<string>
#include<vector>
#include<cmath>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<numeric>
#include<bitset>
#include<list>
#include<sstream>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define ls rt<<1
#define rs rt<<1|1
template <class T> void gmin(T& a, T b) {
    if(a > b) a = b;
}
template<class T> void gmax(T& a, T b) {
    if(a < b) a = b;
}
int read() {
	char c = getchar(); int x = 0, f = 1;
	while(!isdigit(c)) {if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)) {x = x * 10 + c - '0'; c = getchar();}
	return x * f;
}
inline ll gcd(ll a,ll b) {
    ll r;
    while(b>0) {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

inline ll lcm(ll a,ll b){
	return a*b/(gcd(a,b));
}
const int maxn = 200005;
int n,m;
bool a,b,c;
int T;
// int in[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        string in;
        cin >> in;
        int cj = 0;
        for(int i = 0; i < in.size(); i++) {
            if(in[i] == 'N') cj++;
        }
        if(cj == 1) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}