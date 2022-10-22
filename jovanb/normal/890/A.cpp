#include <iostream>

using namespace std;
int niz[6];
int main()
{
    int zbir=0,i,j,k;
    for(i=0;i<6;i++){cin>>niz[i];zbir+=niz[i];}
    if(zbir%2!=0){cout<<"NO";return 0;}
    zbir/=2;
    for(i=0;i<4;i++){
        for(j=i+1;j<5;j++){
            for(k=j+1;k<6;k++){
                if(zbir==niz[i]+niz[j]+niz[k]){cout<<"YES";return 0;}
            }
        }
    }
    cout<<"NO";
    return 0;
}