#include<bits/stdc++.h>
using namespace std;

int N , M;

int main(){
    cin >> N >> M;
    for(int i = 0 ; i <= N ; ++i)
        if(2 * i + 3 * (N - i) <= M && 2 * i + 5 * (N - i) >= M){
            cout << i;
            return 0;
        }
}