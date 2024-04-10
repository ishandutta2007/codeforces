#include<bits/stdc++.h>
using namespace std;
double upCase(int x,int y) {
    if (x==y) return (y);
    int k=(x-y)/y/2;
    if (k<=0) return (-1);
    return (1.0*(x-y)/(2*k));
}
double downCase(int x,int y) {
    if ((x+y)/y<2) return (-1);
    int k=((x+y)/y-2)/2;
    return (1.0*(x+y)/(2*k+2));
}
int main(void) {
    int x,y;
    cin>>x>>y;
    double A=upCase(x,y);
    double B=downCase(x,y);
    //cerr<<A<<" "<<B<<endl;
    if (A<0 && B<0) printf("-1\n");
    else if (A<0) printf("%.9lf\n",B);
    else if (B<0) printf("%.9lf\n",A);
    else printf("%.9lf\n",min(A,B));
    return 0;
}