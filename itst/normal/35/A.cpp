#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int N;
    cin >> N;
    for(int i = 1 ; i <= 3 ; i++){
        int a , b;
        cin >> a >> b;
        if(N == a)
            N = b;
        else
            if(N == b)
                N = a;
    }
    cout << N << endl;
    return 0;
}