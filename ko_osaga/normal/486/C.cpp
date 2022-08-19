#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n, c;
char str[100005];
int arr[100005], st, ed;

int dist(char a, char b){
    if(a > b) swap(a,b);
    return min(b - a, 26 - (b - a));
}

int main(){
    scanf("%d %d %s",&n,&c,str);
    c--;
    if(c > n - 1 - c){
        c = n - 1 - c;
    }
    for (int i=0; i<n/2; i++) {
        arr[i] = dist(str[i],str[n-1-i]);
    }
    st = 0;
    while (st < n/2 && arr[st] == 0) {
        st++;
    }
    ed = n/2-1;
    while (ed >= 0 && arr[ed] == 0) {
        ed--;
    }
    if(st > ed){
        printf("0");
        return 0;
    }
    int ret = ed - st + min(abs(ed - c),abs(st - c));
    for (int i=st; i<=ed; i++) {
        ret += arr[i];
    }
    printf("%d",ret);
}