#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5 + 4;
int T;
string A, B;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> A >> B;
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        int zpos = -1, zpos2 = -1;
        for(int i = 0; i < (int)B.size(); ++i) if(B[i] == '1'){
            zpos = i; break;
        }
        for(int i = 0; i < (int)A.size(); ++i) if(A[i] == '1'){
            zpos2 = i; break;
        }
        if(zpos == -1 || zpos2 == -1){
            puts("0"); continue;
        }
        int I;
        for(I = 0; A[zpos + I] == '0'; ++I){
            int g = 1;
        }
        cout << I << '\n';
    }
    return 0;
}