#include <cstdio>
using namespace std;
int main()
{
    char **a;
    int n;
    int s=0;
    int count;
    scanf("%d",&n);
    a = new char*[n];
    for(int i=0;i<n;i++){
        a[i] = new char[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%c",&a[i][j]);
			if(a[i][j]=='\n')
				scanf("%c",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(a[i][j]=='C')
                count++;
        }
        s+=(count*(count-1))/2;
    }
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(a[j][i]=='C')
                count++;
        }
        s+=(count*(count-1))/2;
    }
    printf("%d",s);
}