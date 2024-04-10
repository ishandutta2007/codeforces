#include <bits/stdc++.h>

using namespace std;

const int NS = (int)2e5+4;
int N, k;
string A;
char stk[NS]; int stkN;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> k >> A;

    k = N-k;
    for(int i=0;i<N;++i){
        stk[++stkN] = A[i];
        if(stk[stkN-1]=='('&&stk[stkN]==')'&&k){
            k-=2, stkN-=2;
        }
    }
    for(int i=1;i<=stkN;++i) cout << stk[i];

    return 0;
}