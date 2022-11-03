#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const double eps = 1e-6;

int main()
{
    int a,b,c,d,q,r;
    int n0,n1;
    double m0,m1;
    cin >> a >> b >> c >> d;
    if(a==0 && b==0 && c==0 && d==0){
        cout << "0";
        return 0;
    }
    double z = ((double)a)+b+c+d;
    z = z*2+0.25;
    z = sqrt(z)-0.5;
    if(fabs(floor(z)-z)>eps){
        cout << "Impossible";
        return 0;
    }
    m0 = sqrt(2*a+0.25)+0.5;
    n0 = floor(m0);
    if(fabs(n0-m0)>eps){
        cout << "Impossible";
        return 0;
    }
    m1 = sqrt(2*d+0.25)+0.5;
    n1 = floor(m1);
    if(fabs(n1-m1)>eps){
        cout << "Impossible";
        return 0;
    }
    if(b==0 && c==0 && d==0){
        for(int i=0;i<n0;i++){
            cout << "0";
        }
        return 0;
    }
    if(b==0 && c==0 && a==0){
        for(int i=0;i<n1;i++){
            cout << "1";
        }
        return 0;
    }
    if(n0*1LL*n1!=b+0LL+c){
        cout << "Impossible";
        return 0;
    }
    q = c/n1;
    r = c%n1;
    if(r==0){
        for(int i=0;i<n0-q;i++){
            cout << "0";
        }
        for(int i=0;i<n1;i++){
            cout << "1";
        }
        for(int i=0;i<q;i++){
            cout << "0";
        }
    }else{
        for(int i=0;i<n0-q-1;i++){
            cout << "0";
        }
        for(int i=0;i<r;i++){
            cout << "1";
        }
        cout << "0";
        for(int i=0;i<n1-r;i++){
            cout << "1";
        }
        for(int i=0;i<q;i++){
            cout << "0";
        }
    }
}