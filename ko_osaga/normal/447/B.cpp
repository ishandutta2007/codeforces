#include <cstdio>

char s[1005];
int k,w[26],m,r,i;
int main(){
    scanf("%s",s);
    scanf("%d",&k);
    for (int i=0; i<26; i++) {
        scanf("%d",&w[i]);
        if(m<w[i]) m = w[i];
    }
    for (i=0; s[i]; i++) {
        r += (i+1)*w[s[i]-'a'];
    }
    r += (2*i+k+1)*k/2*m;
    printf("%d",r);
}