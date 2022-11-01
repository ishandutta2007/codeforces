#include<bits/stdc++.h>
#define MAXN 5001
using namespace std;
long long num[MAXN] , sorted[MAXN] , dir[MAXN] , ans[MAXN][MAXN];
inline int min(int a , int b){return a < b ? a : b;}
int main(){
    int N;
    scanf("%d" , &N);
    for(int i = 1 ; i <= N ; i++){
        scanf("%d" , num + i);
        sorted[i] = num[i];
    }
    sort(sorted + 1 , sorted + N + 1);
    int t = unique(sorted + 1 , sorted + N + 1) - sorted;
    for(int i = 1 ; i <= N ; i++)
        for(int j = 0 ; j < t && (num[i - 1] >= sorted[j] || num[i] >= sorted[j]) ; j++){
            if(sorted[j] > num[i - 1])	ans[i][j] = ans[i - 1][dir[i - 1]] + sorted[j] - sorted[dir[i - 1]];
            else	if(sorted[j] > num[i])	ans[i][dir[i]] = min(ans[i][dir[i]] , ans[i - 1][j]);
            else	ans[i][j] = ans[i - 1][j];
            if(sorted[j] == num[i])	dir[i] = j;
            if(num[i] > sorted[j])	ans[i][j]++;
    }
    int minN = 0x3f3f3f3f;
    for(int i = 0 ; i <= dir[N] ; i++)	minN = min(minN , ans[N][i]);
    cout << minN;
    return 0;
}