#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n, k, ar[maxn], best, cont;

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    cont = 1;
    for(int i = 1; i <= n; i++){
        best = max(best , cont);
        if(ar[i] != ar[i+1]){
            cont++;
        }
        else cont = 1;
    }
    cout << best;

    return 0;
}