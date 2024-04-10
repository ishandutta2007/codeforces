//B
#include<bits/stdc++.h>
#define ll long long
#define sq(X) ((X)*(X))
#define ANS(X,Y,Z) ((-(Y)+sqrt((Y)*(Y)-4*(X)*(Z)))/(2*(X)))
using namespace std;
ll X1,Y1,X2,Y2;
ll vmax,t;
ll vx,vy,ux,uy;

int main() {
    scanf("%I64d%I64d%I64d%I64d",&X1,&Y1,&X2,&Y2);
    scanf("%I64d%I64d",&vmax,&t);
    scanf("%I64d%I64d%I64d%I64d",&vx,&vy,&ux,&uy);
    if(sq(X2-(X1+vx*t))+sq(Y2-(Y1+vy*t))<=sq(vmax*t)) {
        printf("%.12lf",ANS((double)(sq(vmax)-sq(vx)-sq(vy)),(double)(2*(vx*(X2-X1)+vy*(Y2-Y1))),(double)(-sq(X1-X2)-sq(Y1-Y2))));
        return 0;
    }
    else {
        printf("%.12lf",ANS((double)(sq(vmax)-sq(ux)-sq(uy)),-(double)(2*(ux*(vx*t-ux*t+X1-X2)+uy*(vy*t-uy*t+Y1-Y2))),(double)(-sq(vx*t-ux*t+X1-X2)-sq(vy*t-uy*t+Y1-Y2))));
        return 0;
    }
}