#include<bits/stdc++.h>
using namespace std;
#define go(i,n) for(int i=0;i<n;++i)
const int N=400;
int a[N][N],d[N*N],f[N*N],ans,n,m;
int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int x = i, y = m, b = m, s = i * m + j + 1, t; x < n && (b-j)*(n-i) > ans && j < y;++x){
                for(y = j; y < b; ++y)
                    if(s != d[t = a[x][y]-1]){
                        d[t] = s;
                        f[t] = y;
                    }else if(f[t] <= y){
                        b = min(b, y);
                        break;
                    }else{
                        b = min(b,f[t]);
                        f[t] = y;
                    }
                    ans = max(ans,(x-i+1)*(y-j));
            }
    
        }
    }
    
    cout << ans;
}