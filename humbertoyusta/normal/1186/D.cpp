#include<bits/stdc++.h>
#define maxn 1000010
#define eps (ld)(1e-9)
#define f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

ll n, sum;
ld a[maxn];

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += ceil(a[i]);
    }

    for(int i=1; i<=sum; i++){
        if( floor(a[i]) == ceil(a[i]) ) sum++;
        cout << floor(a[i]) << '\n';
    }

    for(int i=sum+1; i<=n; i++){
        int x = ceil(a[i]);
        cout << x << '\n';
    }

    return 0;
}