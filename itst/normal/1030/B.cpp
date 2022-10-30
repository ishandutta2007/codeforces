#include<bits/stdc++.h>
using namespace std;
bool vis[101][101];
int main(){
    int N , D , K;
    cin >> N >> D >> K;
    if(D <= N >> 1){
        for(int i = 0 ; i < D ; ++i)
            for(int j = D - i ; j <= D + i ; ++j)
                vis[i][j] = vis[N - i][N - j] = 1;
        for(int i = D ; i <= N - D ; ++i)
            for(int j = i - D ; j <= i + D ; ++j)
                vis[i][j] = 1;
    }
    else{
        for(int i = 0 ; i < N - D ; ++i)
            for(int j = D - i ; j <= D + i ; ++j)
                vis[i][j] = vis[N - i][N - j] = 1;
        for(int i = N - D ; i <= D ; ++i)
            for(int j = D - i ; j <= D - i + (N - D) * 2 ; ++j)
                vis[i][j] = 1;
    }
    while(K--){
        int a , b;
        cin >> a >> b;
        cout << (vis[a][b] ? "YES" : "NO") << endl;
    }
    return 0;
}