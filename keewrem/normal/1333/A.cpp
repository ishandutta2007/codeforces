#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,K,T,M;
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        if((N*M)%2){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if((j+i)%2)cout<<"W";
                    else cout << "B";
                }
                cout << "\n";
            }
        }else{
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(i == 0 && j == 0)cout << "B";
                    else if((j+i)%2)cout<<"B";
                    else cout << "W";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}