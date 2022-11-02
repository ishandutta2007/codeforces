#include<cstdio>
#include<cstring>
int len,i,j,c;
char a[105],b[105]="CODEFORCES";
int main()
{
    scanf("%s",&a);
    len=strlen(a);
    for(i=0;i<len;i++) {
        for(j=0;j<len;j++) {
            if(j>=i && j<i+len-10)continue;
            if(a[j]==b[c])c++;
            else break;
        }
        if(c==10){
            printf("YES");
            return 0;
        }
        c=0;
    }
        for(j=0;j<10;j++) {
            if(a[j]==b[c])c++;
            else break;
        }
        if(c==10){
            printf("YES");
            return 0;
        }
        c=0;
    for(j=len-9;j<len;j++) {
            if(a[j]==b[c])c++;
            else break;
        }
        if(c==10){
            printf("YES");
            return 0;
        }
        c=0;
    printf("NO");
}