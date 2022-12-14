#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1004][1004];
vector < int > X[1004], Y[1004];

int main(){
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) scanf("%d", arr[i]+j), X[i].push_back(arr[i][j]),
        Y[j].push_back(arr[i][j]);
    for(int i=1;i<=N;++i) sort(X[i].begin(), X[i].end()), X[i].erase(unique(X[i].begin(), X[i].end()), X[i].end());
    for(int j=1;j<=M;++j) sort(Y[j].begin(), Y[j].end()), Y[j].erase(unique(Y[j].begin(), Y[j].end()), Y[j].end());
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            int val = lower_bound(X[i].begin(), X[i].end(), arr[i][j])-X[i].begin();
            val += Y[j].end()-lower_bound(Y[j].begin(), Y[j].end(), arr[i][j]);
            int Val = lower_bound(Y[j].begin(), Y[j].end(), arr[i][j])-Y[j].begin();
            Val += X[i].end()-lower_bound(X[i].begin(), X[i].end(), arr[i][j]);
            printf("%d ", max((int)X[i].size(), max((int)Y[j].size(), max(val, Val))));
        }
        puts("");
    }
    return 0;
}