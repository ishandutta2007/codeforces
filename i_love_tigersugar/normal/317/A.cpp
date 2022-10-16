#include<cstdio>
typedef long long ll;
ll x,y,m;
template<class T>
    void swap(T &a,T &b) {
        T sw;
        sw=a;a=b;b=sw;
    }
ll ans(ll x,ll y,ll m) {
    ll ret=0LL;
    while (x<m && y<m) {
        ret++;
        if (x<y) x=x+y;
        else y=x+y;
    }
    return (ret);
}
void process(void) {
    scanf("%I64d",&x);
    scanf("%I64d",&y);
    scanf("%I64d",&m);
    if (x<y) swap(x,y);
    if (x>=m) {
        printf("0");
        return;
    }
    if (x<=0) {
        printf("-1");
        return;
    }
    ll k=0LL;
    if (y<0) {      
        if ((-y)%x==0) k=-y/x;
        else k=(-y)/x+1LL;      
    }
    printf("%I64d",k+ans(x,y+k*x,m));
}
int main(void) {
    process();
    return 0;
}