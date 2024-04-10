
 #include <cstdio>
inline int readc() {
    int ch;
    while (ch = getchar(), ch != 'b' && ch != 'w');
    return ch;
}
int n,st;
int main(){
    scanf("%d",&n);--n;int l = 1, r = 1000000000;
    printf("%d %d\n", 0, 100), fflush(stdout); 
    st = readc();
    for (int i = 1; i <= n; ++i) {
        int mid = l + r >> 1;
        printf("%d %d\n", mid, 100), fflush(stdout);
        if (readc()!=st) r = mid - 1;
        else l = mid + 1;
    }
    printf("%d %d %d %d\n", l, 99, r, 101);
}