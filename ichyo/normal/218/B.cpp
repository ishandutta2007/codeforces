#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int greedy_min(vector<int> a, int N){
    sort(a.begin(), a.end());
    int k = 0;
    int res = 0;
    REP(iter, N){
        while(a[k] == 0) k++;
        res += a[k]--;
    }
    return res;
}
int greedy_max(vector<int> a, int N){
    int M = a.size();
    int res = 0;
    REP(iter, N){
        nth_element(a.begin(), a.begin() + M - 1, a.end());
        res += a[M - 1];
        a[M - 1]--;
    }
    return res;
}


int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    REP(i, M) cin >> a[i];
    printf("%d %d\n", greedy_max(a, N), greedy_min(a, N));
    return 0;
}