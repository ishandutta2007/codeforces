#include <cstdio>
typedef long long lint;

int n,a[2005][2005];
lint sumOfPlus[4005],sumOfMinus[4005], piv0, piv1;
int max0x, max0y, max1x, max1y;

lint value(int x, int y){return sumOfMinus[x-y+n-1] + sumOfPlus[x+y] - a[x][y];}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
            sumOfPlus[i+j] += a[i][j];
            sumOfMinus[i-j+n-1] += a[i][j];
        }
    }
    piv0 = piv1 = -1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if((i+j)%2 == 0){
                if(piv0 < value(i,j)){
                    piv0 = value(i,j);
                    max0x = i;
                    max0y = j;
                }
            }
            else{
                if(piv1 < value(i,j)){
                    piv1 = value(i,j);
                    max1x = i;
                    max1y = j;
                }
            }
        }
    }
    printf("%I64d\n%d %d %d %d",piv0+piv1,max0x+1,max0y+1,max1x+1,max1y+1);
}