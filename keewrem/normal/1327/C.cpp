#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int T,N,M;

int main(){
    cin >> N >> M;
    cout << N-1+N-1+N*(M-1)+M-1<<"\n";
    for(int i = 1; i< N; i++){
        cout << "U";
    }
    for(int i = 1; i < M; i++)cout << "L";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M-1; j++){
            if(i%2==0)cout << "R";
            else cout << "L";
        }
        if(i!=N-1)cout<<"D";
    }
    cout << "\n";
    return 0;
}