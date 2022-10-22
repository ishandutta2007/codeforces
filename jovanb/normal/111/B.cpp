#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int latest[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x, y;
        cin >> x >> y;
        int cnt=0;
        for(int j=1; j*j<=x; j++){
            if(x%j == 0){
                int prvi = j, drugi = x/j;
                if(latest[prvi] < i-y) cnt++;
                if(latest[drugi] < i-y && prvi != drugi) cnt++;
                latest[prvi] = i;
                latest[drugi] = i;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}