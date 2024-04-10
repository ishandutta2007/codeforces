#include<bits/stdc++.h>
using namespace std;

int num[110] , year[110] , N , cnt;

int main(){
    cin >> N;
    for(int i = 1 ; i <= N ; ++i){
        cin >> num[i];
        if(cnt + 1 == num[i])
            year[++cnt] = 2000 + i;
    }
    cout << cnt << endl;
    for(int i = 1 ; i <= cnt ; ++i)
        cout << year[i] << ' ';
    return 0;
}