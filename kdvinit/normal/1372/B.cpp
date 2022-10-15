#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(long long int n){
    if (n <= 1)
        return false;
    for (long long int i = 2; i < sqrt(n); i++)
        if (n % i == 0) return false;

    return true;
}
int main(){
        int t;
        cin>>t;
        while(t--){
                long long int n;
                cin>>n;
                if(n%2==0) cout<<n/2<<" "<<n/2<<endl;
                else {
                    long long int i=1,in=1,l=0,sqrtn=sqrt(n);
                    int ind[sqrtn];
                    //cout<<i<<endl;
                    //cout<<sqrt(n)<<endl;
                    for(int j=1;j<=sqrt(n);j++){
                        //cout<<j<<endl;
                        if(isPrime(j)){
                            ind[l]=j;
                            l++;
                        }
                    }
                    for(i=0;i<l;i++){
                        if(n%ind[i]==0) { in=ind[i]; break; }
                    }
                    if(in==1) {cout<<in<<" "<<n-in<<endl; continue;}
                    in=n/in;
                    cout<<in<<" "<<n-in<<endl;
        }

}
}