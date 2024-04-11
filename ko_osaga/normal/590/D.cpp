#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef pair<double, double> pr;

int dp1[2][76][11250];
int dp2[2][76][11250];

int a[155];
int n, k, s;

int main(){
    scanf("%d %d %d",&n,&k,&s);
    int sum = 0;
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        if(i <= k) sum += a[i];
    }
    s = min(s, n*(n-1)/2);
    int ret = 1e9;
    for(int j=0; j<=min(k, n-k); j++){
        for(int l=0; l<=s; l++){
            dp1[0][j][l] = (j? -1e9 : 0);
            dp2[(n+1)%2][j][l] = (j ? 1e9 : 0);
        }
    }
    for(int i=1; i<=k; i++){
        for(int j=0; j<=min(k, n-k); j++){
            for(int l=0; l<=s; l++){
                dp1[i%2][j][l] = dp1[(i-1)%2][j][l];
                if(j && l - k + i >= 0){
                    dp1[i%2][j][l] = max(dp1[i%2][j][l], dp1[(i-1)%2][j-1][l-(k-i)] + a[i]);
                }
            }
        }
    }
    for(int i=n; i>k; i--){
        for(int j=0; j<=min(k, n-k); j++){
            for(int l=0; l<=s; l++){
                dp2[i%2][j][l] = dp2[(i+1)%2][j][l];
                if(j && l - i + k + 1 >= 0){
                    dp2[i%2][j][l] = min(dp2[i%2][j][l], dp2[(i+1)%2][j-1][l-(i-k-1)] + a[i]);
                }
            }
        }
    }
    for(int i=0; i<=min(k, n-k); i++){
        for(int j=0; j<=s-i; j++){
            ret = min(ret, sum - dp1[k%2][i][j] + dp2[(k+1)%2][i][s-j-i]);
        }
    }
    printf("%d",ret);
}