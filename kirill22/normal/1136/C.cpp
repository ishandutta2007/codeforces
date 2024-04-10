#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n,m;
   cin >> n >> m;
   int a[n][m];
   int b[n][m];
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin >> a[i][j];
    }
   }
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin >> b[i][j];
    }
   }
   for(int ii=0;ii<=m+n-1-1;ii++){
        vector<int> x;
   vector<int> y;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if (i+j==ii){
            x.push_back(a[i][j]);
            //cout << a[i][j] << " " << i <<" " << j << endl;
            y.push_back(b[i][j]);
            //cout << b[i][j] << " " << i <<" " << j << endl;
        }
    }

   }
   sort(x.begin(),x.end());
   sort(y.begin(),y.end());
   for(int u=0;u<x.size();u++){
if (x[u]!=y[u]){
    cout << "NO";
    return 0;
}
    //cout << x[u] << " " << y[u] << " " << ii << endl;
   }
   }
   cout << "YES";

}