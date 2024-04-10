#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long INF = 1e16;
int gcd(int a,int b){

    if (a<b){
        swap(a,b);
    }
    if (b==0){
        return a;
    }

    return gcd(b,a%b);

}

int main() {
    int n,k,x,y,z,co=0,ans=0,ii=0,uu=0,q;
    cin >> q;
    for(int i=0;i<q;i++){
            int yy=0;
        cin >> x >> y;
        if (x%2==0){
            yy-=(y-x+1)/2;
            if(y%2==0){
                yy+=y;
            }
            cout << yy << endl;

        }
        else{
            yy+=(y-x+1)/2;
            if (y%2==1){
                yy-=(y);
            }
            cout << yy << endl;
        }
    }

}