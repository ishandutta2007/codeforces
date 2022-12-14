#include <bits/stdc++.h>

using namespace std;

int N, r;
struct Data{
    int A, B;
    Data(){}
    Data(int A, int B):A(A), B(B){}
    bool operator<(const Data&r)const{
        return A + B > r.A + r.B;
    }
};
vector < Data > mi;
struct Datb{
    int A, B;
    Datb(){}
    Datb(int A, int B):A(A), B(B){}
    bool operator<(const Datb&r)const{
        return A < r.A;
    }
};
vector < Datb > pl;
int d[(int)1e5 + 4], D[(int)1e5 + 4];

int main(){
    scanf("%d %d", &N, &r);
    for(int i = 1; i <= N; ++i){
        int a, b; scanf("%d %d", &a, &b);
        if(b >= 0) pl.push_back(Datb(a, b));
        else mi.push_back(Data(a, b));
    }
    sort(pl.begin(), pl.end());
    sort(mi.begin(), mi.end());
    int cnt = 0;
    for(auto&i:pl){
        if(i.A <= r) r += i.B, ++cnt;
    }
    d[r] = cnt, D[r] = cnt;
    for(auto&i:mi){
        for(int j = r; j >= i.A; --j){
            if(j + i.B >= 0){
                D[j + i.B] = max(D[j + i.B], d[j] + 1);
            }
        }
        for(int j = 0; j <= r; ++j) d[j] = D[j];
    }
    int ans = 0;
    for(int i = 0; i <= r; ++i){
        ans = max(ans, d[i]);
    }
    printf("%s\n", ans == N ? "YES" : "NO");
    return 0;
}