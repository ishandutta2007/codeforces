#include <iostream>
#include <cmath>
using namespace std;

int frstP(long long int a,long long int b){
    long long int i=2,index=a;
    long long int x=min((long long int)sqrt(a),b);
    for(i=1;i<=x;i++){
        //cout<<a%i<<" "<<a/i<<endl;
        if((a%i)==0){
            if(a/i<=b) return i;

         index=a/i;
         //cout<<index<<endl;
        }
    }
    return index;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int a,b;
        cin>>a>>b;
        cout<<frstP(a,b)<<endl;
        }
}