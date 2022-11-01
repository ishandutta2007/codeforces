#include<bits/stdc++.h>
using namespace std;

int a[120];

int main(){
    int N , K;
    cin >> N >> K;
    if(K > 1){
        puts("Yes");
        return 0;
    }
    int ind = 0;
    for(int i = 1 ; i <= N ; ++i){
        cin >> a[i];
        if(a[i] == 0)
            ind = i;
    }
    cin >> a[ind];
    for(int i = 2 ; i <= N ; ++i)
        if(a[i] < a[i - 1]){
            puts("Yes");
            return 0;
        }
    puts("No");
    return 0;
}