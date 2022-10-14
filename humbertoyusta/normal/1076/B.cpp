#include<bits/stdc++.h>
#define lg2(x) 31 - __builtin_clz(x)
#define maxn 1001
#define ll long long
#define ull unsigned long long
#define ld long double
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);

    long long n;
    cin >> n;

    if(n%2==0){
        cout<<n/2;
        return 0;
    }

    for(long long i=2; i*i<=n; i++){
        if(n%i==0){
            cout << (n-i)/2 + 1;
            return 0;
        }
    }

    cout << 1;

    return 0;
}