#include <iostream>

using namespace std;
char niz[200];
int main()
{
    int n,i,j,gr=0,br=0,maxbr=0,l=0;
    cin>>n;
    cin>>niz;
    for(i=0;i<n;i++){
        l=0;
        if(niz[i]<='Z'){maxbr=max(br,maxbr);br=0;gr=i+1;}
        else{
            for(j=gr;j<i;j++){
                if(niz[i]==niz[j])l=1;
            }
            if(l==0)br++;
        }
        maxbr=max(br,maxbr);
    }

    cout<<maxbr;
    return 0;
}