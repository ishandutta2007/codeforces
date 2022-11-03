#include <cstdio>
#include <string>
#include <map>
#define r (m['R'])
#define g (m['G'])
#define b (m['B'])

int main()
{
    std::map<char,int> m;
    r=0;
    g=0;
    b=0;
    int n;
    char c;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        c='\n';
        while(c=='\n' || c==' '){
            scanf("%c",&c);
        }
        m[c]++;
    }
    if(((r+g>=2) && (b+g>=2)) && (r+b>=2)){
        printf("BGR");
        return 0;
    }
    if(r+g==0){
        printf("B");
        return 0;
    }
    if(r+b==0){
        printf("G");
        return 0;
    }
    if(b+g==0){
        printf("R");
        return 0;
    }
    if(r+g+b>2){
        if(b<=1)
            printf("B");
        if(g<=1)
            printf("G");
        if(r<=1)
            printf("R");
    }else{
        if(b==0)
            printf("B");
        if(g==0)
            printf("G");
        if(r==0)
            printf("R");
    }
    return 0;
}