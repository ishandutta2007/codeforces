#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
const double eps=1e-9;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=1e6+9;
int n;
double c(double y,double z){
    if(z*log(y)>=y*log(z)&&z*log(y)>=log(y*z))return z*log(y);
    if(y*log(z)>=log(y*z))return y*log(z);
    return log(y*z);
}
int main(){
    double x,y,z;
    double X,Y,Z;
    cin>>x>>y>>z;

    X=c(y,z)+log(log(x));
    Y=c(x,z)+log(log(y));
    Z=c(x,y)+log(log(z));
    if(x<1&&y<1&&z<1){
        X=x,Y=y,Z=z;
        if((X>=Y)&&(X>=Z)){
            if(z*log(y)<=y*log(z)&&z*log(y)<=log(y*z))cout<<"x^y^z"<<endl;
            else if(y*log(z)<=log(y*z))cout<<"x^z^y"<<endl;
            else cout<<"(x^y)^z"<<endl;
        }
        else{
            if((Y>=Z)){
                if(z*log(x)<=x*log(z)&&z*log(x)<=log(x*z))cout<<"y^x^z"<<endl;
                else if(x*log(z)<=log(x*z))cout<<"y^z^x"<<endl;
                else cout<<"(y^x)^z"<<endl;
            }
            else {
                if(y*log(x)<=x*log(y)&&y*log(x)<=log(x*y))cout<<"z^x^y"<<endl;
                else if(x*log(y)<=log(y*x))cout<<"z^y^x"<<endl;
                else cout<<"(z^x)^y"<<endl;
            }
        }
        return 0;
    }
    if((X>=Y||y<1)&&(X>=Z||z<1)&&x>=1){
        if(z*log(y)>=y*log(z)&&z*log(y)>=log(y*z))cout<<"x^y^z"<<endl;
        else if(y*log(z)>=log(y*z))cout<<"x^z^y"<<endl;
        else cout<<"(x^y)^z"<<endl;
    }
    else{
        if((Y>=Z||z<1)&&y>=1){
            if(z*log(x)>=x*log(z)&&z*log(x)>=log(x*z))cout<<"y^x^z"<<endl;
            else if(x*log(z)>=log(x*z))cout<<"y^z^x"<<endl;
            else cout<<"(y^x)^z"<<endl;
        }
        else {
            if(y*log(x)>=x*log(y)&&y*log(x)>=log(x*y))cout<<"z^x^y"<<endl;
            else if(x*log(y)>=log(y*x))cout<<"z^y^x"<<endl;
            else cout<<"(z^x)^y"<<endl;
        }
    }
    return 0;
}
/*
5
5 6 10 7 6
*/