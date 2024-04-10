#include <bits/stdc++.h>

using namespace std;
int touched[30];
int main()
{
    //plz hack this :)
    char a[10000];
    int x,brojac=0;
    cin>>a;
    int k=strlen(a);
    cin>>x;
    if(x>k){cout<<"impossible";return 0;}
    for(int i=0;i<k;i++){
        touched[a[i]-96]++;
    }
    for(int i=1;i<=26;i++){
        if(touched[i]>0)brojac+=touched[i]-1;
    }
    int r=x-k+brojac;
    cout<<max(r,0);
    return 0;
}