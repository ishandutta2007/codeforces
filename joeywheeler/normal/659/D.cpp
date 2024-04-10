#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int x[1005], y[1005];
int n;

bool inpoly(double X, double Y) {
    int t = 0;
    FO(i,0,n) if (y[i] == y[i+1]) {
        if (y[i] < Y) {
            if (x[i] < x[i+1]) {
                if (x[i] < X && X < x[i+1]) t++;
            } else {
                if (x[i+1] < X && X < x[i]) t--;
            }
        }
    }
    return t;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d %d", x+i, y+i);
    x[n] = x[0]; y[n] = y[0];
    int res = 0;
    FO(i,0,n) {
        double X, Y;
        if (x[i] == x[i+1]) X = x[i+1]+0.5;
        else {
            if (x[i] < x[i+1]) X = x[i+1]+0.5;
            else X = x[i+1]-0.5;
        }
        if (y[i] == y[i+1]) Y = y[i+1]+0.5;
        else {
            if (y[i] < y[i+1]) Y = y[i+1]+0.5;
            else Y = y[i+1]-0.5;
        }
        //printf("%lf %lf\n", X, Y);
        if (inpoly(X,Y)) res++;
    }
    printf("%d\n", res);
}