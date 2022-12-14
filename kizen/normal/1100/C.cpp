#include <bits/stdc++.h>

using namespace std;

const double PIE = 3.1415926535897932;

int main(){
    double N, R;
    scanf("%lf %lf", &N, &R);
    double A = 360/N;
    double B = R*sin(A*PIE/180);
    double C = R-sqrt(R*R-B*B);
    double D = sqrt(B*B+C*C);
    if(A==90) D = R*sqrt(2);
    if(A>90){
        B = R*sin((A-90)*PIE/180);
        C = R*sin((180-A)*PIE/180);
        B+=R;
        D = sqrt(B*B+C*C);
    }
    printf("%.7f", D*R/(2*R-D));
    return 0;
}