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
 
int n;
double x[1005], y[1005], z[1005];
 
inline double hyp(double x, double y, double z){
    return x * x + y * y + z * z;
}
 
int main(){
    scanf("%d",&n);
    double px = 0, py = 0, pz = 0;
    for(int i=0; i<n; i++){
        scanf("%lf %lf %lf",&x[i],&y[i],&z[i]);
        px += x[i];
        py += y[i];
        pz += z[i];
    }
    px *= 1.0 / n;
    py *= 1.0 / n;
    pz *= 1.0 / n;
    double rat = 0.1;
    for(int i=0; i<100000; i++){
        double maxv = -1;
        int maxp = -1;
        for(int j=0; j<n; j++){
            double tmp = hyp(x[j] - px, y[j] - py, z[j] - pz);
            if(maxv < tmp){
                maxv = tmp;
                maxp = j;
            }
        }
        px += (x[maxp] - px) * rat;
        py += (y[maxp] - py) * rat;
        pz += (z[maxp] - pz) * rat;
        rat *= 0.998;
    }
    printf("%.10lf %.10lf %.10lf", px, py, pz);
}