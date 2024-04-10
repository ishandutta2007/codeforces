#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Qs,N,i,j,k,l,T,mx,rec,mes;

int main(){
    scanf("%d",&N);
    while (N--){
        scanf("%d%d",&rec,&mes);
        //praznim poruke sa queue-a
        Qs = max(0,Qs+T-rec);
        Qs += mes;
        mx = max(mx,Qs);
        T = rec;
    }
    T += Qs;
    printf("%d %d\n",T,mx);
    return 0;
}