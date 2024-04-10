#include<bits/stdc++.h>
#define inf 1000000007
#define f first
#define s second
using namespace std;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    while( n >= 10 ){
        ans++;
        n++;
        while( n % 10 == 0 ) n /= 10;
    }
    cout << ans + 9 << '\n';

    return 0;
}