#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node{
    node *prev,*next;
    char x;
};

node A[100005],*nd1,*nd2,*tmp1,*tmp2;
char S[100005];
int N,L,i,j,k;

void obrisi(node *curr){
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    L--;
}

int main(){
    scanf("%s",S+1);
    N = strlen(S+1);
    L = N;
    for (i=1; i<=N; i++){
        A[i].x = S[i];
        A[i].next = A+i+1;
        A[i].prev = A+i-1;
    }
    A[0].next = A+1;
    A[N+1].prev = A+N;
    nd1 = A+1;
    nd2 = A+2;
    while (nd2 != A+N+1){
        //printf("%d %d\n",nd1-A,nd2-A);
        if (nd1->x == nd2->x){
            tmp1 = nd1->prev;
            tmp2 = nd2->next;
            obrisi(nd1);
            obrisi(nd2);
            nd1 = tmp1;
            nd2 = tmp2;
        } else {
            nd2 = nd2->next;
            nd1 = nd1->next;
        }
    }
    if (L==0) printf("Yes\n"); else printf("No\n");
    return 0;
}