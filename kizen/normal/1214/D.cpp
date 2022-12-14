#include <bits/stdc++.h>

using namespace std;

using LL = long long;
LL N, M;
string in;
vector < string > arr;
vector < vector < LL > > d, D;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for(LL i = 0; i < N; ++i){
        cin >> in;
        arr.push_back(in);
        vector < LL > vc;
        d.push_back(vc);
        d[i].resize(M + 4);
        D.push_back(vc);
        D[i].resize(M + 4);
    }
//    N = 2, M = 499999;
//    for(int j = 0; j < M; ++j) in.push_back('.');
//    for(LL i = 0; i < N; ++i){
//        arr.push_back(in);
//        vector < LL > vc;
//        d.push_back(vc);
//        d[i].resize(M + 4);
//        D.push_back(vc);
//        D[i].resize(M + 4);
//    }
    d[0][0] = 1;
    for(LL i = 0; i < N; ++i){
        for(LL j = 0; j < M; ++j){
            if(i + 1 < N && arr[i + 1][j] == '.' && d[i][j]){
                d[i + 1][j] = 1;
            }
            if(j + 1 < M && arr[i][j + 1] == '.' && d[i][j]){
                d[i][j + 1] = 1;
            }
        }
    }
    D[N - 1][M - 1] = 1;
    for(int i = N - 1; i >= 0; --i){
        for(int j = M - 1; j >= 0; --j){
            if(i && D[i][j] && d[i - 1][j]) D[i - 1][j] = 1;
            if(j && D[i][j] && d[i][j - 1]) D[i][j - 1] = 1;
        }
    }
    if(!d[N - 1][M - 1]){
        cout << "0\n"; return 0;
    }
    for(LL i = 1; i < N + M - 2; ++i){
        LL A = min(N - 1, i), B = i - min(N - 1, i), cnt = 0;
        while(A >= 0 && B < M){
            if(A < N && B < M && D[A][B]) ++cnt;
            --A, ++B;
        }
        if(cnt == 1){
            cout << "1\n"; return 0;
        }
    }
    cout << "2\n";
    return 0;
}