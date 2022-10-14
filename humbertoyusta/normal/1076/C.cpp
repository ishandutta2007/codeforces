#include<bits/stdc++.h>
#define lg2(x) 31 - __builtin_clz(x)
#define maxn 1001
#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

typedef long double ld;
int tc;
ld a,b,n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed); cout.precision(9);

    cin >> tc;
    while(tc--){
        cin >> n;
        if(n<4&&n>0){cout<<"N\n"; continue;}
        cout << "Y";
        a = ( n + sqrt(n*n-4*n) ) / ld(2);
        b = n - a;
        cout << " " << max(a,b) << " " << min(b,a) << '\n';
    }

    return 0;
}