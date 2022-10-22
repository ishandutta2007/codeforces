#include <bits/stdc++.h>
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
    long long k,x,y,z,co=0,ans=0,q,cc,bb;
    long long ii=0,uu=0;
    cin >> q;
    for(int i=0;i<q;i++){

        long long n,m;
        cin >> n >> m;
        vector<long long> c(4);
        vector<long long> b(4);
        for(int ii=0;ii<4;ii++){
            cin >> k;
            b[ii]=k;;
        }

        for(int iii=0;iii<4;iii++){
            cin >> k;
            c[iii]=k;
        }
        if (n%2==0 || m%2==0){
           cc=n*m/2;
           bb=cc;
        }
        else{
            cc=n*m/2;
            bb=n*m/2+1;
        }

        if ((b[0]+b[1])%2==0){
            long long l=0;
            if ((b[2]-b[0]+1)%2==0 || (b[3]-b[1]+1)%2==0){
                l+=(b[2]-b[0]+1)*(b[3]-b[1]+1)/2;
            }
            else{
                l+=(b[2]-b[0]+1-1)/2*(b[3]-b[1]+1)+(b[3]-b[1]+1)/2;
            }
            cc-=l;
            bb+=l;

        }
        if ((b[0]+b[1])%2==1){
            long long l=0;
            if ((b[2]-b[0]+1)%2==0 ||(b[3]-b[1]+1)%2==0){
                l+=(b[2]-b[0]+1)*(b[3]-b[1]+1)/2;
            }
            else{
                l+=(b[2]-b[0]+1-1)/2*(b[3]-b[1]+1)+(b[3]-b[1]+2)/2;
            }
            cc-=l;
            bb+=l;
        }




        if ((c[0]+c[1])%2==0){
            long long l=0;
            if ((c[2]-c[0]+1)%2==0 || (c[3]-c[1]+1)%2==0){
                l+=(c[2]-c[0]+1)*(c[3]-c[1]+1)/2;
            }
            else{
                l+=(c[2]-c[0]+1-1)/2*(c[3]-c[1]+1)+(c[3]-c[1]+2)/2;
            }
            cc+=l;
            bb-=l;
        }
        if ((c[0]+c[1])%2==1){
            long long l=0;
            if ((c[2]-c[0]+1)%2==0 || (c[3]-c[1]+1)%2==0){
                l+=(c[2]-c[0]+1)*(c[3]-c[1]+1)/2;
            }
            else{
                l+=(c[2]-c[0]+1-1)/2*(c[3]-c[1]+1)+(c[3]-c[1]+1)/2;
            }
            cc+=l;
            bb-=l;
        }


        long long a,b1,c1,d;
        a=max(b[0],c[0]);
        b1=max(b[1],c[1]);
        c1=min(b[2],c[2]);
        d=min(b[3],c[3]);
        bool flag=true;
        if (c1<a || d<b1){
            flag=false;
        }
        if ((a+b1)%2==0 && flag){
            long long l=0;
            if ((c1-a+1)%2==0 || (d-b1+1)%2==0){
                l+=(c1-a+1)*(d-b1+1)/2;
            }
            else{
                l+=(c1-a+1-1)/2*(d-b1+1)+(d-b1+1)/2;
            }
            cc+=l;
            bb-=l;
        }
        if ((a+b1)%2==1 && flag){
            long long l=0;
            if ((c1-a+1)%2==0 ||(d-b1+1)%2==0){
                l+=(c1-a+1)*(d-b1+1)/2;
            }
            else{
                l+=(c1-a+1-1)/2*(d-b1+1)+(d-b1+2)/2;
            }
            cc+=l;
            bb-=l;
        }
        cout << bb << " " << cc << endl;




    }

}