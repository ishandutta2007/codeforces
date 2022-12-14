#include <bits/stdc++.h>

using namespace std;

int N;
struct data{
    int a, b, c, d, num;
    bool operator<(const data&r)const{
        if(a+b+c+d!=r.a+r.b+r.c+r.d) return a+b+c+d>r.a+r.b+r.c+r.d;
        else return num<r.num;
    }
}arr[1004];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;++i) scanf("%d %d %d %d", &arr[i].a, &arr[i].b, &arr[i].c, &arr[i].d),
        arr[i].num = i;
    sort(arr, arr+N);
    for(int i=0;i<N;++i) if(arr[i].num==0) printf("%d", i+1);
    return 0;
}