#include <bits/stdc++.h>
using namespace std;

char a[1000000],b[100];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    cin>>a>>b;
    int n=strlen(a),m=strlen(b),br=0,i,j;
    for(i=0;i<=n-m;i++){
        for(j=0;j<m;j++){
            if(a[i+j]!=b[j])break;
            if(j==m-1){br++;i+=m-1;break;}
        }
    }
    cout<<br;
    return 0;
}