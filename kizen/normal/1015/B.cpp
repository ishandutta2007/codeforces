#include <bits/stdc++.h>

using namespace std;

int N;
string A, B, C;
map < char, int > mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> A >> B;
    for(int i=0;i<N;++i) ++mp[A[i]];
    for(int i=0;i<N;++i) --mp[B[i]];
    for(int i=0;i<26;++i) if(mp[i+'a']){
        cout << "-1"; return 0;
    }

    int cnt = 0;
    C = A;
    for(int i=0;i<N;++i){
        for(int j=N-2;j>=i;--j) if(C[j]!=B[i]){
            ++cnt, swap(C[j], C[j+1]);
        }
    }
    cout << cnt << '\n';
    for(int i=0;i<N;++i){
        for(int j=N-2;j>=i;--j) if(A[j]!=B[i]){
            cout << j+1 << ' ', swap(A[j], A[j+1]);
        }
    }

    return 0;
}