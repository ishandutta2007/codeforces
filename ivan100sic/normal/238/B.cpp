#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct num{
    int x,id,gr;
};

num A[100005];

int H,N,i,j,k,l;
int Sol[100005],opt1,opt2;

bool cmp(num a,num b){
    return a.x < b.x;
}

void brute_force(){
    int i,j,k,b1,b2,mn,mx,sol,mask;
    sol = 1000000000;
    for (i=0; i<(1<<N); i++){
        mn = 1000000000;
        mx = -1000000000;
        for (j=0; j<N; j++){
            for (k=j+1; k<N; k++){
                b1 = ((1<<j)&i) > 0;
                b2 = ((1<<k)&i) > 0;
                if (b1==b2){
                    mn = min(mn , A[j].x+A[k].x);
                    mx = max(mx , A[j].x+A[k].x);
                } else {
                    mn = min(mn , A[j].x+A[k].x+H);
                    mx = max(mx , A[j].x+A[k].x+H);
                }
            }
        }
        if (mx-mn < sol){
            sol = mx-mn;
            mask=i;
        }
    }
    printf("%d\n",sol);
    for (i=0; i<N; i++) printf("%d%c",1+(((1<<i)&mask)>0) , i==N-1?'\n':' ');
}

int main(){
    scanf("%d%d",&N,&H);
    for (i=0; i<N; i++){
        scanf("%d",&A[i].x);
        A[i].id = i;
    }
    if (N<=10) brute_force(); else {
        sort(A,A+N,cmp);
        for (i=0; i<N; i++) A[i].gr = 2;
        opt1 = A[N-1].x+A[N-2].x-A[0].x-A[1].x;
        opt2 = max(A[0].x + A[N-1].x + H , A[N-1].x+A[N-2].x) - min(A[0].x + A[1].x + H , A[1].x + A[2].x);
        if (opt1 < opt2) A[0].gr = 2; else A[0].gr = 1;
        printf("%d\n",(int)min(opt1,opt2));
        for (i=0; i<N; i++) Sol[A[i].id] = A[i].gr;
        for (i=0; i<N; i++) printf("%d%c",Sol[i],i==N-1?'\n':' ');
    }
    return 0;
}