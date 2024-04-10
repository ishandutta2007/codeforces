#include <bits/stdc++.h>
using namespace std;
char a[100];
int main()
{
    long long br=0,i,j,l;
    cin>>a;
    int k=strlen(a);
    for(i=0;i<k;i++){
        for(j=i+1;j<k;j++){
            for(l=j+1;l<k;l++){
                if(a[i]=='Q' && a[j]=='A' && a[l]=='Q')br++;
            }
        }
    }
    cout<<br;
    return 0;
}