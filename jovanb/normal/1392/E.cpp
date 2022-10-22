#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll mat[30][30];

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j%2 == 0) mat[i][j] = (1LL<<(i+j-3));
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        int ti = 1, tj = 1;
        cout << "1 1" << endl;
        while(ti <= n && tj <= n && (ti+tj < 2*n)){
            if(ti == n){
                tj++;
                cout << ti << " " << tj << endl;
                continue;
            }
            if(tj == n){
                ti++;
                cout << ti << " " << tj << endl;
                continue;
            }
            if(x & (1LL<<(ti+tj-2))){
                if(tj%2 == 0) ti++;
                else tj++;
                cout << ti << " " << tj << endl;
                continue;
            }
            else{
                if(tj%2 == 0) tj++;
                else ti++;
                cout << ti << " " << tj << endl;
                continue;
            }
        }
    }
    return 0;
}