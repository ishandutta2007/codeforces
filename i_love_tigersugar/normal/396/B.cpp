#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
bool prime(int x) {
    int i=2;
    if (x<2) return (false);
    while (true) {
        if (x%i==0 && x>i) return (false);
        i++;
        if (1LL*i*i>x) return (true);
    }
}
ll gcd(ll a,ll b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a=a%b; else b=b%a;
    }
}
void printfrac(ll p,ll q) {
    ll t=gcd(p,q);
    cout << p/t << '/' << q/t << "\n";
}
int lessprime(int n) {
    while (true) if (prime(n)) return (n); else n--;
}
int greaterprime(int n) {
    n++;
    while (true) if (prime(n)) return (n); else n++;
}
void process(void) {
    int n;
    cin >> n;
    if (prime(n+1)) printfrac(n-1,2*(n+1));
    else {
        int y=greaterprime(n);
        int x=lessprime(n);
        printfrac(1LL*x*y-2*x-2*y+2*(n+1),2LL*x*y);
    }
}
int main(void) {
    int t;cin >> t;
    REP(i,t) process();
    return 0;
}