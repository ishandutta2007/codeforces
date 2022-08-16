
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 10;
int x[N], y[N];

void get(int & fx, int & fy){
    int g = __gcd(abs(fx), abs(fy));
    fx /= g; fy /= g;
    if(fx < 0) fx *= -1, fy *= -1;
    if(fx == 0 && fy < 0) fy *= -1;
}

bool lies_on(int a, int b, int _x, int _y, int mx, int my){
    // if(a == _x && b == _y) return 1;
    int fx = _x - a, fy = _y - b;
    get(fx, fy);
    return fx == mx && fy == my;
}

bool collinear(vector<int> & X, vector<int> & Y){
    int n = X.size();
    if(n <= 2) return 1;
    int my = Y[1] - Y[0], mx = X[1] - X[0];
    get(mx, my);
    for(int i = 2; i < n; i++) if(!lies_on(X[0], Y[0], X[i], Y[i], mx, my)) return 0;
    return 1;
}
vector<int> X, Y;
int main(){
    int n;
    sd(n);
    if(n <= 4){
        printf("YES\n");
        return 0;
    }
    for(int i = 1; i <= n; i++){
        sd(x[i]);
        sd(y[i]);
    }
    srand(time(NULL));
    while(clock() < 0.5 * CLOCKS_PER_SEC){
        int i = 1 + rand() % (n - 1);
        int j = i + 1 + rand() % (n - i);
        int my = y[j] - y[i], mx = x[j] - x[i];
        get(mx, my);
        X.clear(); Y.clear();
        for(int k = 1; k <= n; k++){
            if(k != i && k != j && (!lies_on(x[i], y[i], x[k], y[k], mx, my))){
                X.push_back(x[k]);
                Y.push_back(y[k]);
            }
        }
        if(collinear(X, Y)){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}