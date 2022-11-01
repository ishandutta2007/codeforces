#include<bits/stdc++.h>
using namespace std;
int M[21] , R[21];
int main(){
    int N;
    cin >> N;
    int cnt = 0;
    for(int i = 1 ; i <= N ; ++i)
        cin >> M[i];
    for(int i = 1 ; i <= N ; ++i)
        cin >> R[i];
    for(int i = 0 ; i < 720720 ; ++i){
        bool f = 0;
        for(int j = 1 ; j <= N && !f ; ++j)
            f = i % M[j] == R[j];
        cnt += f;
    }
    cout << fixed << setprecision(6) << cnt / 720720.0;
    return 0;
}