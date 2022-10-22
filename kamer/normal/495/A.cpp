#include<iostream>
#include<algorithm>
using namespace std;

int deg[100];
int v[100][7];

int main(void){

    int aux[7] = {1,1,1,0,1,1,1};
    std::copy(aux,aux+6,v[0]);
    int au[7] = {0,0,1,0,0,1,0};
    std::copy(au,au+6,v[1]);
    int aus[7] = {1,0,1,1,1,0,1};
    std::copy(aus,aus+6,v[2]);
    int aum[7] = {1,0,1,1,0,1,1};
    std::copy(aum,aum+6,v[3]);
    int aur[7] = {0,1,1,1,0,1,0};
    std::copy(aur,aur+6,v[4]);
    int auy[7] = {1,1,0,1,0,1,1};
    std::copy(auy,auy+6,v[5]);
    int auq[7] = {1,1,0,1,1,1,1};
    std::copy(auq,auq+6,v[6]);
    int aup[7] = {1,0,1,0,0,1,0};
    std::copy(aup,aup+6,v[7]);
    int aua[7] = {1,1,1,1,1,1,1};
    std::copy(aua,aua+6,v[8]);
    int aut[7] = {1,1,1,1,0,1,1};
    std::copy(aut,aut+6,v[9]);

    int i,j,k;
    bool ok;
    for (i=0;i<=9;i++){
        for (j=0;j<=9;j++){
            ok = 1;
            if (j != i){
                for (k=0;k<=6;k++)
                    if (v[i][k] > v[j][k])
                        ok = 0;
            }
            if (ok) 
                deg[i]++;

        }
    }

    int n;
    cin >> n;
    int a,b;
    a = n % 10;
    b = n/10;
    cout << deg[a]*deg[b];

    return 0;

    
}