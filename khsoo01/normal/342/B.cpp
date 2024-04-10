#include<cstdio>
int n,m,s,e,top;
bool dis;
struct query{
    int t,l,r;
}q[100005];

int main()
{
    int i,j;
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(i=0;i<m;i++) {
        scanf("%d%d%d",&q[i].t,&q[i].l,&q[i].r);
    }
    for(i=1;;i++){
        if(q[top].t==i && q[top].l<=s && q[top].r>=s){
            printf("X");
        }
        else {
            if(s>e) {
                if(q[top].l<=s-1 && q[top].r>=s-1 && q[top].t==i)printf("X");
                else {
                    printf("L");
                    s--;
                }
            }
            else {
                if(q[top].l<=s+1 && q[top].r>=s+1 && q[top].t==i)printf("X");
                else {
                    printf("R");
                    s++;
                }
            }
        }
        if(q[top].t==i)top++;
        if(s==e)break;
    }
}