#include <cstdio>
#include <cstring>
using namespace std;

int len;
char s[100001];
int z[100000];
int cnt[100001];

int strcmpn(int i, int j) {
    int k = 0;
    while(i < len && j < len && s[i] == s[j])
        i++, j++, k++;
    return k;
}

int main(){
    scanf("%s", s);
    len = strlen(s);
    if(len == 1) {
        puts("1");
        puts("1 1");
        return 0;
    }
    z[0] = len;
    z[1] = strcmpn(0, 1);
    int l = 1, r = 1 + z[1];
    for(int i = 2; i < len; i++) {
        if(r <= i) {
            z[i] = strcmpn(0, i);
            l = i;
            r = i + z[i];
        } else if(i + z[i - l] < r){
            z[i] = z[i - l];
        } else {
            z[i] = (r - i) + strcmpn(r - i, r);
            l = i;
            r = i + z[i];
        }
    }
    for(int i = 0; i < len; i++)
        cnt[z[i]]++;
    for(int i = len - 1; i > 0; i--)
        cnt[i] += cnt[i + 1];
    int num = 0;
    for(int i = 1; i <= len; i++)
        if(z[len - i] == i)
            num++;
    printf("%d\n", num);
    for(int i = 1; i <= len; i++)
        if(z[len - i] == i)
            printf("%d %d\n", i, cnt[i]);
}