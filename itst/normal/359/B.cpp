#include<bits/stdc++.h>
using namespace std;
int main(){
    int N , K;
    cin >> N >> K;
    for(int i = 1 ; i <= N ; ++i)
        if(!K)
            cout << i * 2 - 1 << ' ' << i * 2 << ' ';
        else{
            cout << i * 2 << ' ' << i * 2 - 1 << ' ';
            --K;
        }
    return 0;
}