#include <bits/stdc++.h>

using namespace std;

int N, M;
string A, B;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> A >> B;

    int f = 0;
    for(int i=0;i<N;++i) if(A[i]=='*') f = 1;
    if(f){
        if(N>M+1){
            cout << "NO"; return 0;
        }
        for(int i=0;A[i]!='*';++i){
            if(A[i]!=B[i]){
                cout << "NO"; return 0;
            }
        }
        for(int i=N-1;A[i]!='*';--i){
            if(A[i]!=B[M-(N-i)]){
                cout << "NO"; return 0;
            }
        }
        cout << "YES";
    }
    else{
        if(A==B) cout << "YES";
        else cout << "NO";
    }

    return 0;
}