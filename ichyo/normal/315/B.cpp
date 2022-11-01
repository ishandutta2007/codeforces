#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    int sum = 0;
    REP(i, N) cin >> a[i];
    REP(i, M){
        int t;
        cin >> t;
        if(t == 1){
            int v, x;
            cin >> v >> x;
            a[v - 1] = x - sum;
        }else if(t == 2){
            int y;
            cin >> y;
            sum += y;
        }else if(t == 3){
            int q;
            cin >> q;
            cout << a[q - 1] + sum << endl;
        }
    }
    return 0;
}