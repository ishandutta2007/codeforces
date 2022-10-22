#include <iostream>

using namespace std;
int niz[101];
int main()
{
    int n,i,a,brojac=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        niz[a]++;
    }
    n/=2;
    for(i=1;i<=100;i++){
        if(niz[i]==n){brojac++;if(brojac==1)a=i;}
        else if(niz[i]>0){cout<<"NO";return 0;}
        if(brojac==2){cout<<"YES"<<endl<<a<<" "<<i;return 0;}
    }
    cout<<"NO";
    return 0;
}