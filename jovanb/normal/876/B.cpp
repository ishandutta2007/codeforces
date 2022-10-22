#include <iostream>

using namespace std;
long niz[100000];
long long niz2[100000];
int main()
{
    long long a;
    long n,k,m,j,i;
    cin>>n>>k>>m;
    for(i=0;i<n;i++){
        cin>>a;
        niz[a%m]++;
        niz2[i]=a;
    }
    for(i=0;i<m;i++){
        if(niz[i]>=k)break;
        if(i==m-1){cout<<"No";return 0;}
    }
    cout<<"Yes"<<endl;
    a=0;
    for(j=0;j<n && a<k;j++){
        if(niz2[j]%m==i){cout<<niz2[j]<<" ";a++;}
    }
    return 0;
}