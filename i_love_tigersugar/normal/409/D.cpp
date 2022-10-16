#include<cstdio>
const int ans[]={1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0};
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);    
}
int main(void) {
    printf("%d",ans[nextInt()-1]);
    return 0;
}