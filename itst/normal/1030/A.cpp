#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    for(int i = 1 ; i <= N ; ++i){
        int a;
        cin >> a;
        if(a){
            cout << "HARD";
            return 0;
        }
    }
    cout << "EASY";
    return 0;
}