#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string S,Love;
int X,i,j,k;
char z;

int main(){
    cin >> S;
    cin >> X;
    for (i=0; i<S.size(); i++){
        if (S[i] < 97) S[i] = S[i]+32;
    }
    for (i=0; i<S.size(); i++){
        z = S[i];
        if (z < X+97){
            Love += z-32;
        } else {
            Love += z;
        }
    }
    cout << Love << '\n';
    return 0;
}