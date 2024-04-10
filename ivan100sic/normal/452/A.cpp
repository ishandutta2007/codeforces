#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string A[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
string S;

int N;

bool uporedi(int x){
    int i;
    if (A[x].length() != S.length()) return false;
    for (i=0; i<A[x].length(); i++){
        if (A[x][i] != S[i] && S[i] != '.') return false;
    }
    return true;
}

int main(){
    cin >> N;
    cin >> S;
    int i;
    for (i=0; i<8; i++) if (uporedi(i)){
        cout << A[i] << "\n";
        return 0;
    }
    return 0;
}