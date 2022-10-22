#include <bits/stdc++.h>

using namespace std;
unordered_map <long,long> br1,br2,br3;
long niz[200000],niz1[200000],niz2[200000];
int main() {
    long n,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
        br1[niz[i]]++;
    }
    for(i=0;i<n-1;i++){
        cin>>niz1[i];
        br2[niz1[i]]++;
    }
    for(i=0;i<n-2;i++){
        cin>>niz2[i];
        br3[niz2[i]]++;
    }
    for(i=0;i<n;i++){
        if(br1[niz[i]]>br2[niz[i]]){cout<<niz[i]<<endl;break;}
    }
    for(i=0;i<n-1;i++){
        if(br2[niz1[i]]>br3[niz1[i]]){cout<<niz1[i];break;}
    }
    return 0;
}