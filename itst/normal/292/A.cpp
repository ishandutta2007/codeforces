#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , maxSize = 0 , nowT = 0 , nowC = 0;
    for(cin >> n ; n ; n--){
        int a , b;
        cin >> a >> b;
        nowC = max(nowC - a + nowT , 0) + b;
        maxSize = max(maxSize , nowC);
        nowT = a;
    }
    cout << nowT + nowC << ' ' << maxSize;
    return 0;
}