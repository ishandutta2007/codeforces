// Hydro submission #62d0e8bcb36e4a123829b35f@1657858237812
#include<cstdio>
#include<string>
inline int readint(int c) {
    if (c >= 'A' && c <= 'F') return c - 55;
    if (c >= '0' && c <= '9') return c - 48;
    return -1;
}
inline int read(int base) {
    int c = getchar();
    int x = 0;
    while (readint(c) == -1) c = getchar();
    while (readint(c) != -1) x = x * base + readint(c), c = getchar();
    return x;
}
inline int printint(int out, int base) {
    if (base < 10 || out < 10) return out + 48;
    return out + 55;
}
static std::string str;
inline void print(int out, int base) {
    if (!out) return;
    print(out / base, base);
    str += printint(out % base, base);
}
int main(){
    int base1 = 10, base2 = 8;
    int temp = read(base1);
    print(temp, base2);
    int cnt = 0;
    for (auto it : str) if (it == '1') cnt++;
    printf("%d", cnt);
}