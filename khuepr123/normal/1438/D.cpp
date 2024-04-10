#include<bits/stdc++.h>
using namespace std;
 
#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n; int a[maxN];
int last; int king; int cnt;
 
void imitate(int start, int fin){
    for(int i = start; i < fin; i += 2){
        cnt++;
    }
    for(int i = start; i < fin; i += 2){
        cnt++;
    }
}
 
void doing(int start, int fin){
    for(int i = start; i < fin; i += 2){
        cout << i << " " << i + 1 << " " << i + 2 << endl;
        a[i] = ((a[i] ^ a[i + 1]) ^ a[i + 2]);
        a[i + 1] = a[i]; a[i + 2] = a[i];
    }
    for(int i = start; i < fin; i += 2){
        cout << i << " " << i + 1 << " " << fin << endl;
        a[i] = ((a[i] ^ a[i + 1]) ^ a[fin]);
        a[i + 1] = a[i]; a[fin] = a[i];
    }
}
 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cnt = 0;
    cin >> n; last = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; last = (last ^ a[i]);
    }
    if(n % 2 == 0 && last != 0){
        cout << "NO"; return 0;
    }
    cout << "YES\n";
    if(n % 2 == 1){
        imitate(1, n); cout << cnt << endl;
        doing(1, n);
    }
    else{
        imitate(1, n - 3); cnt+=2; cout << cnt << endl;
        doing(1, n - 3);
        int i;
        cout << n - 2 << " " << n - 1 << " " << n << endl;
        cout << n - 2 << " " << n - 1 << " " << n - 3 << endl;
        i = n - 2;
        a[i] = ((a[i] ^ a[i + 1]) ^ a[i + 2]);
        a[i + 1] = a[i]; a[i + 2] = a[i];
        i = n - 3;
        a[i] = ((a[i] ^ a[i + 1]) ^ a[i + 2]);
        a[i + 1] = a[i]; a[i + 2] = a[i];
    }
}