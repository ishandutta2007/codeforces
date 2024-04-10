#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL NS = 300004;
LL N;
LL x, y;
LL xfar[NS], yfar[NS];
LL Start[NS], Link[NS*2], Child[NS*2], np=1;
LL q[NS], far[NS], f, r;
struct data{
    LL a, num;
    data(){}
    data(LL a, LL num):a(a), num(num){}

    bool operator<(const data&r)const{
        return a>r.a;
    }
};

LL scan(){
    char c = getchar(); LL num = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) num = num*10+c-'0', c = getchar();
    return num;
}

void push(LL s, LL e){
    np++;
    Link[np] = Start[s], Child[np] = e, Start[s] = np;
}

int main(){
    N = scan(), x = scan(), y = scan();
    LL i, a, b;
    for(i=1;i<=N-1;i++){
        a = scan(), b = scan();
        push(a, b), push(b, a);
    }
    f = r = 0;
    q[r] = x, far[r++] = 0;
    while(f<r){
        for(i=Start[q[f]];Child[i]!=0;i=Link[i]){
            if(xfar[Child[i]]==0&&Child[i]!=x){
                xfar[Child[i]] = far[f]+1;
                q[r] = Child[i], far[r++] = far[f]+1;
            }
        }
        f++;
    }
    f = r = 0;
    q[r] = y, far[r++] = 0;
    while(f<r){
        for(i=Start[q[f]];Child[i]!=0;i=Link[i]){
            if(yfar[Child[i]]==0&&Child[i]!=y){
                yfar[Child[i]] = far[f]+1;
                q[r] = Child[i], far[r++] = far[f]+1;
            }
        }
        f++;
    }

    LL cnt1 = 0, cnt2 = 0;
    for(i=1;i<=N;i++){
        if(xfar[i]+xfar[y]==yfar[i]) cnt1++;
        if(yfar[i]+yfar[x]==xfar[i]) cnt2++;
    }

    printf("%I64d", N*(N-1)-cnt1*cnt2);

    return 0;
}