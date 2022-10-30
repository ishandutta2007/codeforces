#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 9;

int num[1010] , N;

int main(){
    cin >> N;
    for(int i = 1 ; i <= N ; ++i)
        cin >> num[i];
    sort(num + 1 , num + N + 1);
    int p = N - 1;
    for(int i = 1 ; i <= N ; ++i){
        if(p <= 0)
            p = 1;
        cout << num[p] << ' ';
        if(i & 1)
            ++p;
        else
            p -= 3;
    }
    return 0;
}