#include<bits/stdc++.h>
using namespace std;
int main(){
    int maxN = 0 , N;
    cin >> N;
    for(int i = 1 ; i <= N ; i++){
        int a;
        cin >> a;
        maxN = max(maxN , a - 25);
    }
    cout << maxN;
    return 0;
}